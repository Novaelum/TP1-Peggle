#pragma once
#include "GUtils.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();

	void SetActive();
	void SetAngle(float angle)				{ mAngle = angle; }

	Sprite* GetSprite()						{ return mSprite; }
	CCircle* GetCollider()					{ return mCollider; }
	bool IsActive()							{ return mIsActive; }

private:
	Sprite*			mSprite;
	CCircle*		mCollider;
	bool			mIsActive;
	float			mAngle;
	int				mSpeed;
};

