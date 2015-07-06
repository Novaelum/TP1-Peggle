#pragma once
#include "GUtils.h"


class Target {
public:
	Target();
	~Target();

	Sprite* GetSprite()					{ return mSprite; }
	Collider* GetCollider()				{ return mCollider; }

private:
	Sprite*		mSprite;
	Collider*	mCollider;

};

