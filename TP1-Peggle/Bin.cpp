#include "Bin.h"


Bin::Bin()
	: mSprite(nullptr)
	, mCollider(nullptr)
	, mMovingLeft(true)
	, mSpeed(400)
{
	mSprite = new Sprite(Texture::Bin_ID);
	mSprite->SetPivot(D3DXVECTOR3(128 * 0.5f, 32 * 0.5f, 0.f));
	mSprite->SetPosition(0, -450);
	mCollider = new CRectangle(mSprite, mSprite->GetPosition().x - mSprite->GetTextureInfos()->infos.Width * 0.5f, mSprite->GetPosition().y - mSprite->GetTextureInfos()->infos.Height * 0.5f / 2, mSprite->GetTextureInfos()->infos.Width, mSprite->GetTextureInfos()->infos.Height);
}


Bin::~Bin() {
	delete mSprite;
	delete mCollider;
}

void Bin::MoveBin() {
	if (mMovingLeft) {
		if (mSprite->GetPosition().x > (((SCREEN_RES_W * 0.5) - 64) * -1)) {
			mSprite->SetPosition(mSprite->GetPosition().x - mSpeed * gTimer->GetDeltaTime(), mSprite->GetPosition().y);
		}
		else {
			mMovingLeft = false;
			mSprite->SetPosition(mSprite->GetPosition().x + mSpeed * gTimer->GetDeltaTime(), mSprite->GetPosition().y);
		}
	}
	else {
		if (mSprite->GetPosition().x < ((SCREEN_RES_W * 0.5) - 64)) {
			mSprite->SetPosition(mSprite->GetPosition().x + mSpeed * gTimer->GetDeltaTime(), mSprite->GetPosition().y);
		}
		else {
			mMovingLeft = true;
			mSprite->SetPosition(mSprite->GetPosition().x - mSpeed * gTimer->GetDeltaTime(), mSprite->GetPosition().y);
		}
	}
	mCollider->SetPosition(mSprite->GetPosition().x, mSprite->GetPosition().y);
}

