#include "Target.h"


Target::Target()
	: sprite(nullptr)
{
	sprite = new Sprite(Texture::Target_ID);
}


Target::~Target() {

}
