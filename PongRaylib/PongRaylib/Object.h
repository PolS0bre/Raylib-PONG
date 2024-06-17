#pragma once
#include "Definiciones.h"
#include "raylib.h"
class Object
{
public:
	float x, y;
	float width, height;
	int speed_x, speed_y;

	void Draw();
	void Update();
};

