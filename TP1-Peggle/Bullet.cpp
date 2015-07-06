#include "Bullet.h"


Bullet::Bullet()
	: mSprite(nullptr)
	, mCollider(nullptr)
	, mIsActive(false)
	, mSpeed(500)
{
	mSprite = new Sprite(Texture::Bullet_ID);
	mSprite->SetVisible(false);
	mSprite->SetPivot(D3DXVECTOR3(32 * 0.5, 32 * 0.5, 0.f));
	mCollider = new CCircle(mSprite, 32 * 0.5f, 32 * 0.5f, 16);
	mCollider->SetPosition(mSprite->GetPosition().x, mSprite->GetPosition().y);
}


Bullet::~Bullet()
{
	delete mSprite;
	delete mCollider;
}

// Only called when the bullet is active
void Bullet::Update() {
	if (mIsActive) {
		mSprite->SetPosition(mSprite->GetPosition().x + sin(D3DXToRadian(mAngle)) * mSpeed * gTimer->GetDeltaTime(), mSprite->GetPosition().y + cos(D3DXToRadian(mAngle)) * mSpeed * gTimer->GetDeltaTime());
		mCollider->SetPosition(mSprite->GetPosition().x, mSprite->GetPosition().y);
	}
}

void Bullet::SetActive() {
	mIsActive = true;
	mSprite->SetVisible(true);
}

