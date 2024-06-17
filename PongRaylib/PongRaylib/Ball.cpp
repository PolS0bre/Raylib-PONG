#include "Ball.h"

Ball::Ball(int* pScore, int* cpuScore)
{
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	radius = 20;
	speed_x = 7;
	speed_y = 7;
	player_score = pScore;
	cpu_score = cpuScore;
}

Ball::~Ball()
{
}

void Ball::Draw() {
	DrawCircle(x, y, radius, WHITE);//Draw a circle (center of the ball on the X axis, same for Y axis, circle radius, Color)
}
void Ball::Update() {
	x += speed_x;
	y += speed_y;

	if (y + radius >= SCREEN_HEIGHT || y - radius <= 0) {
		speed_y *= -1;
	}


	if (x - radius <= 0) {
		*cpu_score += 1;
		Reset();
	}

	if (x + radius >= SCREEN_WIDTH) {
		*player_score += 1;
		Reset();
	}

}

void Ball::Reset()
{
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	speed_x *= -1;
}

int Ball::get_pos()
{
	return y;
}
