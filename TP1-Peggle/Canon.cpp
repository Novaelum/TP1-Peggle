#include "Canon.h"


Canon::Canon()
: mSprite(nullptr)
, mBullet(nullptr)
	, mAngle(180.f)
	, mRotSpeed(70)
{
	mSprite = new Sprite(Texture::Canon_ID);
	mSprite->SetPivot(D3DXVECTOR3(256 * 0.5f, 256 * 0.5f, 0.f));
	mSprite->SetPosition(0, (SCREEN_RES_H * 0.5) - 35);
	mSprite->SetRotationDeg(180.f, 0.f, mAngle);
	mBullet = new Bullet();
}


Canon::~Canon() {
	delete mSprite;
	delete mBullet;
}

void Canon::SetAngle(bool left) {
	if (left) {
		std::cout << mAngle << std::endl;
		if (mAngle < 270) {
			mAngle += mRotSpeed * gTimer->GetDeltaTime();
			if (mAngle > 270)
				mAngle = 270;
			mSprite->SetRotationDeg(180.f, 0.f, mAngle);
		}
	}
	else {
		std::cout << mAngle << std::endl;
		if (mAngle > 90) {
			mAngle -= mRotSpeed * gTimer->GetDeltaTime();
			if (mAngle < 90)
				mAngle = 90;
			mSprite->SetRotationDeg(180.f, 0.f, mAngle);
		}
	}
}


void Canon::Shoot() {
	if (!mBullet->IsActive()) {
		mBullet->GetSprite()->SetPosition(mSprite->GetPosition().x - 5 + sin(D3DXToRadian(mAngle)) * 150, mSprite->GetPosition().y + cos(D3DXToRadian(mAngle)) * 150);
		mBullet->SetAngle(mAngle);
		mBullet->SetActive();
	}
}


void Canon::Update() {
	mBullet->Update();
}
