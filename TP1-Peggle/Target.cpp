#include "Target.h"

Target::Target()
	: mSprite(nullptr)
	, mCollider(nullptr)
{
	//int r = rand() % 5;
	//sprite = new Sprite(Texture::Target_ID, &D3DXVECTOR2(0, r * 50), &D3DXVECTOR2(50, 50));
	mSprite = new Sprite(Texture::TargetOff_ID);
	mSprite->SetPivot(D3DXVECTOR3(32 * 0.5, 32 * 0.5, 0.f));
	mCollider = new CCircle(mSprite, 32 * 0.5, 32 * 0.5, 16);
}


Target::~Target() {
	delete mSprite;
	delete mCollider;
}
