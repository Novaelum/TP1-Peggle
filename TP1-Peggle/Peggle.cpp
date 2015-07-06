#include "Peggle.h"

Peggle::Peggle()
	: mBg(nullptr)
	, mCanon(nullptr)
	, mBin(nullptr)
{
	// Game textures load
	Textures->LoadTexture(Texture::Bullet_ID, MakePath(canonPath, "bullet.png"));
	Textures->LoadTexture(Texture::TargetOff_ID, MakePath(targetPath, "0_off.png"));
	Textures->LoadTexture(Texture::TargetOn_ID, MakePath(targetPath, "0_on.png"));
	Textures->LoadTexture(Texture::Canon_ID, MakePath(canonPath, "canon.png"));
	Textures->LoadTexture(Texture::Bin_ID, MakePath(canonPath, "bin.jpg"));
	// Game sounds load
	//Sounds->LoadSound(Sound::TestMusic_ID, MakePath(musicPath, "testmusic.mp3"));


	//AudioSys->play2D(Sounds->Get(Sound::TestMusic_ID));

	mBg = new Background(LVL_1);
	mCanon = new Canon();
	SpawnTargets(55, 75);
	mBin = new Bin();
	mColliders.push_back(mBin->GetCollider());
}

// Spawns a random number of targets from the given minimum and maximum wanted
void Peggle::SpawnTargets(int min, int max) {
	// Generate random number to get the exact number to spawn
	int targetCount = rand() % (max - min) + min;
	// Loop that spawns the target before placing them in a vector
	for (int i = 0; i < targetCount; ++i) {
		Target* newTarget = new Target();
		newTarget->GetSprite()->SetPosition(&GeneratePosNumbers());
		newTarget->GetCollider()->SetPosition(newTarget->GetSprite()->GetPosition().x, newTarget->GetSprite()->GetPosition().y);
		mColliders.push_back(newTarget->GetCollider());
		mTargets.push_back(newTarget);
	}
}

// Generate numbers for the target position
D3DXVECTOR2 Peggle::GeneratePosNumbers() {
	std::vector<D3DXVECTOR2>::iterator itr;
	bool done;
	int row;
	int col;
	D3DXVECTOR2 pos;
	do {
		done = true;
		row = rand() % 24;
		col = rand() % 12;
		pos = D3DXVECTOR2(row * 50 - ((SCREEN_RES_W * 0.5) - 80), col * 50 - ((SCREEN_RES_H * 0.5) - 200));

		auto iter = mTargetsPos.begin();
		for (; iter != mTargetsPos.end(); iter++) {
			// Check to make sure no target are directly next to the given position.
			if (sqrt((pow(abs((*iter).x - pos.x), 2) + pow(abs((*iter).y - pos.y), 2))) <= 50) {
				done = false;
			}
		}
		if (done)
			mTargetsPos.push_back(pos);
	} while (!done);
	return pos;
}

Peggle::~Peggle() {
	delete mBg;
	delete mCanon;
	delete mBin;
	{	auto iter = mTargets.begin();
		for (; iter != mTargets.end(); iter++) {
			delete (*iter);
		}
		mTargets.clear();
	}
	{	auto iter = mColliders.begin();
		for (; iter != mColliders.end(); iter++) {
			delete (*iter);
		}
		mColliders.clear();
	}
	mTargetsPos.clear();
}

void Peggle::Start() {

}

void Peggle::Update() {
	if (gDInput->keyDown(DIK_LEFTARROW)) {
		mCanon->SetAngle(true);
	}
	if (gDInput->keyDown(DIK_RIGHTARROW)) {
		mCanon->SetAngle(false);
	}
	if (gDInput->keyDown(DIK_SPACE)) {
		mCanon->Shoot();
	}
	mBin->MoveBin();
	mCanon->Update();
	// Check for non-null value
	CheckCollisions();
		
}

// All meaningful collision are related to the bullet
void Peggle::CheckCollisions() {
	auto iter = mColliders.begin();
	for (; iter != mColliders.end(); iter++) {
		if ((*iter)->GetType() == Type::CIRCLE) {
			if (mCanon->GetBullet()->GetCollider()->CollidesWith((CCircle*)(*iter))) {
				// if a collision is detected (forced to be a target in this check), the texture is change to turn the peggle on.
				dynamic_cast<Sprite*>((*iter)->GetGameObject())->SetTexInfos(Texture::TargetOn_ID);
				std::cout << "Score: " << mScore << std::endl;
			}
		}
		else if ((*iter)->GetType() == Type::RECTANGLE) {
			if (mCanon->GetBullet()->GetCollider()->CollidesWith((CRectangle*)(*iter))) {
				
				std::cout << "collision!" << std::endl;
			}
		}
	}
}

void Peggle::Draw() {

}

void Peggle::Stop() {

}

