#ifndef ResourcesID
#define ResourcesID

#pragma warning(disable: 4996)


// Const path
// Sprites
#define spritePath	"../Assets/Sprites/"
#define bgPath		"../Assets/Sprites/BG/"
#define canonPath	"../Assets/Sprites/Canon/"

// Audio
#define musicPath	"../Assets/Audio/Musics/"
#define soundPath	"../Assets/Audio/Sounds/"


std::string MakePath(std::string p_constPath, std::string p_path) {
	return p_constPath.append(p_path);
}										

namespace Texture
{
	enum ID
	{
		Lvl1_Bg_ID,
		Bullet_ID
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
