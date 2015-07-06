#include "Background.h"


Background::Background(lvlID lvl)
	: background(nullptr)
{
	Textures->LoadTexture(Texture::Background_ID, MakePath(bgPath, std::to_string(lvl) += ".jpg"));
	background = new Sprite(Texture::Background_ID);
	background->SetPivot(D3DXVECTOR3((SCREEN_RES_W * 0.5), (SCREEN_RES_H * 0.5), 0.f));
	background->SetRotationDeg(180.f, 0.f, 180.f);
}


Background::~Background() {
	delete background;
}


void Background::ChangeBackground(lvlID lvl) {
	Textures->RemoveResource(Texture::Background_ID);
	Textures->LoadTexture(Texture::Background_ID, MakePath(bgPath, std::to_string(lvl) += ".jpg"));
	background->SetTexInfos(Texture::Background_ID);
}

