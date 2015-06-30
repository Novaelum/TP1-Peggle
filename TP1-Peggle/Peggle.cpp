#include "Peggle.h"
#include "Sprite.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::Lvl1_Bg_ID, MakePath(bgPath, "lvl1_bg.jpg"));
	Textures->LoadTexture(Texture::Bullet_ID, MakePath(canonPath, "bullet.png"));
	Sounds->LoadSound(Sound::TestMusic_ID, MakePath(musicPath, "testmusic.mp3"));
	Sounds->LoadSound(Sound::TestSoundFX_ID, "bell.wav");
	AudioSys->play2D(Sounds->Get(Sound::TestMusic_ID));
	AudioSys->play2D(Sounds->Get(Sound::TestSoundFX_ID));

	Sprite* s = new Sprite(Texture::Lvl1_Bg_ID);
	D3DXVECTOR3 center((s->GetTextureInfos()->infos.Width * 0.5), (s->GetTextureInfos()->infos.Width * 0.5), 0.f);
	s->SetPivot(&center);
	Sprite* s2 = new Sprite(Texture::Bullet_ID);
}

Peggle::~Peggle()
{

}

void Peggle::Start()
{

}

void Peggle::Update()
{

}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}
