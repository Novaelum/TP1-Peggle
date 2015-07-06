#ifndef UTILS
#define UTILS

#include <iostream>
#include "ResourceIDs.h"

// From engine
#include "Sprite.h"
#include "Collider.h"
#include "CCircle.h"
#include "CRectangle.h"

#define SCREEN_RES_W 1280
#define SCREEN_RES_H 1024

// Merge a constant path (going into the right ressources folder) with the resources name.
std::string MakePath(std::string p_constPath, std::string p_path);

#endif