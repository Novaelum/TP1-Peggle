#pragma once
#include "GUtils.h"

// ==================================
// Background (Sprite at the back)
// ----------------------------------

// One for each existing level
enum lvlID {
	LVL_1,
	LVL_2
};

class Background
{
public:
	Background(lvlID lvl);
	~Background();

	void ChangeBackground(lvlID lvl);

private:
	Sprite* background;
};

