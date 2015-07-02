#pragma once

#include "Engine.h"
#include "Component.h"

class Peggle :
	public Component
{
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	std::string MakePath(std::string p_constPath, std::string p_path) { 
		return p_constPath.append(p_path); 
	}
};

