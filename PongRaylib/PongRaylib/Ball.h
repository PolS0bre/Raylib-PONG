#pragma once
#include "Object.h"
class Ball : public Object
{
private:
	float radius;
	int* player_score, *cpu_score;
public:
	Ball(int* pScore, int* cpuScore);
	~Ball();
	void Draw();
	void Update();
	void Reset();
	int get_pos();
	int getRadius() { return radius; }
};

