#pragma once
#include "Object.h"
class Paddle :public Object
{
private:

public:
	Paddle(int posX, int posY, int rectWidth, int rectHeight, int speed);
	~Paddle();
	void Draw();
	void Update(int ball_y);
	void UpdatePlayer();
	void limitMovement();
};

