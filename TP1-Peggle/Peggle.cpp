#include "Peggle.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Target.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::Lvl1_Bg_ID, MakePath(bgPath, "lvl1_bg.jpg"));
	Textures->LoadTexture(Texture::Bullet_ID, MakePath(canonPath, "bullet.png"));
	Textures->LoadTexture(Texture::Target_ID, MakePath(targetPath, "targets.png"));

	Sounds->LoadSound(Sound::TestMusic_ID, MakePath(musicPath, "testmusic.mp3"));
	Sounds->LoadSound(Sound::TestSoundFX_ID, "bell.wav");

	AudioSys->play2D(Sounds->Get(Sound::TestMusic_ID));
	AudioSys->play2D(Sounds->Get(Sound::TestSoundFX_ID));

	Sprite* s = new Sprite(Texture::Lvl1_Bg_ID);
	Sprite* s2 = new Sprite(Texture::Bullet_ID);

	Target* t = new Target();
	
	D3DXVECTOR3 center ((1280 * 0.5), (1024 * 0.5), 0.f);
	D3DXVECTOR3 center2 ((s2->GetTextureInfos()->infos.Width * 0.5), (s2->GetTextureInfos()->infos.Height * 0.5), 0.f);

	s->SetPivot(center);
	s2->SetPivot(center2);
	s->SetRotationDeg(180.f, 0.f, 180.f);
	
	////std::cout << s->GetTextureInfos()->infos.Width * 0.5 << " " << s->GetTextureInfos()->infos.Height * 0.5 << std::endl;
	
	//s->SetPosition(0, 0);
	
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
