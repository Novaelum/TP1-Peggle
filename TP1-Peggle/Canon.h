#pragma once
#include "GUtils.h"
#include "Bullet.h"

class Canon
{
public:
	Canon();
	~Canon();

	void Update();

	Sprite* GetSprite()			{ return mSprite; }
	Bullet* GetBullet()			{ return mBullet; }
	float GetAngle()			{ return mAngle; }

	void SetAngle(bool left);
	void Shoot();

private:
	Sprite*			mSprite;
	Bullet*			mBullet;
	float			mAngle;
	int				mRotSpeed;
};

