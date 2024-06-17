#include "Paddle.h"

Paddle::Paddle(int posX, int posY, int rectWidth, int rectHeight, int speed)
{
	x = posX;
	y = posY;
	width = rectWidth;
	height = rectHeight;
	speed_y = speed;
}

Paddle::~Paddle()
{
}

void Paddle::Draw()
{
	DrawRectangle(x, y, width, height, WHITE); //Draw a rectangle (X axis Position, Y axis position, width, height, Color)
}

void Paddle::Update(int ball_y)
{
	if (y + height / 2 > ball_y) {
		y -= speed_y;
	}
	else if (y + height / 2 <= ball_y) {
		y += speed_y;
	}
	limitMovement();
}

void Paddle::UpdatePlayer()
{
	if (IsKeyDown(KEY_UP)) {
		y -= speed_y;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		y += speed_y;
	}
	limitMovement();
}

void Paddle::limitMovement()
{
	if (y < 0) {
		y = 0;
	}
	if (y + height >= SCREEN_HEIGHT) {
		y = SCREEN_HEIGHT - height;
	}
}
