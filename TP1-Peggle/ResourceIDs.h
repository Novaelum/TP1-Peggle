#ifndef ResourcesID
#define ResourcesID

// Const path
// Sprites
#define spritePath	"../Assets/Sprites/"
#define bgPath		"../Assets/Sprites/BG/"
#define canonPath	"../Assets/Sprites/Canon/"
#define targetPath	"../Assets/Sprites/Targets/"

// Audio
#define musicPath	"../Assets/Audio/Musics/"
#define soundPath	"../Assets/Audio/Sounds/"

namespace Texture
{
	enum ID
	{
		Lvl1_Bg_ID,
		Bullet_ID,
		Canon_ID,
		Target_ID,
	};
}

namespace Sound
{
	enum ID
	{
		TestMusic_ID,
		TestSoundFX_ID
	};
}

//namespace Font
//{
//	enum ID
//	{
//		Dialog
//	};
//}

#endif 
