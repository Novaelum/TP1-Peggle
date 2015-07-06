#pragma once
#include "Engine.h"
#include "Component.h"
#include "GUtils.h"
#include "Target.h"
#include "Background.h"
#include "Canon.h"
#include "Bin.h"
#include "Bullet.h"


class Peggle : public Component {
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

	void CheckCollisions();

private:
	void SpawnTargets(int min, int max);
	D3DXVECTOR2 GeneratePosNumbers();

	Background*					mBg;
	Canon*						mCanon;
	Bin*						mBin;
	std::vector<Target*>		mTargets;
	std::vector<D3DXVECTOR2>	mTargetsPos;
	std::vector<Collider*>		mColliders;
	int							mScore;
};

