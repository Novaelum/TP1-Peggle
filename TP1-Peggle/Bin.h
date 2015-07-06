#pragma once
#include "GUtils.h"

class Bin
{
public:
	Bin();
	~Bin();

	Sprite* GetSprite()						{ return mSprite; }
	Collider* GetCollider()					{ return mCollider; }

	void MoveBin();

private:
	Sprite*		mSprite;
	Collider*	mCollider;
	bool		mMovingLeft;
	int			mSpeed;

};

