#include "Peggle.h"
#include "Sprite.h"
#include "ResourceIDs.h"

Peggle::Peggle()
{
	//Textures->LoadTexture(Texture::ELEPHANT_DE_MER, "safe_image.jpg");
	//Textures->LoadTexture(Texture::POW_POW_POW, "powpowpow.png");
	Sounds->LoadSound(Sound::TestMusicID, "../Assets/Audio/Musics/testmusic.mp3");
	Sounds->LoadSound(Sound::TestSoundFXID, "bell.wav");
	AudioSys->play2D(Sounds->Get(Sound::TestMusicID));
	AudioSys->play2D(Sounds->Get(Sound::TestSoundFXID));
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
