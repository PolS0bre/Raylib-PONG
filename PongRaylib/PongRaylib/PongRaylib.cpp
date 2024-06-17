#include <iostream>
#include "raylib.h"
#include "Definiciones.h"
#include "Ball.h"
#include "Paddle.h"

int main()
{
	//Color Dark_Green = Color{ 20, 160, 133, 255 };

	int player_score = 0;
	int cpu_score = 0;

	Ball ball = Ball(&player_score, &cpu_score);
	Paddle AI = Paddle(SCREEN_WIDTH - 35, (SCREEN_HEIGHT / 2) - 60, 25, 120, 5);
	Paddle Player = Paddle(10, (SCREEN_HEIGHT / 2) - 60, 25, 120, 5);

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG RAYLIB"); //Start the game window (Width, Height, Name)
	SetTargetFPS(60); //Set the amount of Frames per Seconds (FPS)

	while (WindowShouldClose() == false) { //WinowShouldClose is activated when we do something that would close, the close icon or ESC.
		BeginDrawing(); //Start drawing things


		//UPDATE PHASE
		ball.Update();
		Player.UpdatePlayer();
		AI.Update(ball.get_pos());

		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.getRadius(), Rectangle{ Player.x, Player.y, Player.width, Player.height })) {
			ball.speed_x *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.getRadius(), Rectangle{ AI.x, AI.y, AI.width, AI.height })) {
			ball.speed_x *= -1;
		}

		//RENDER PHASE
		ClearBackground(BLACK); //Draw all the window of the color selected (Color)
		DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
		ball.Draw();
		Player.Draw();
		AI.Draw();
		DrawText(TextFormat("%i", player_score), SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", cpu_score), SCREEN_WIDTH * 3 / 4 - 20, 20, 80, WHITE);
		EndDrawing(); //End drawing things for the loop
	}

	CloseWindow(); //Close the started window, always after InitWindow, at the end of the code
	return 0;
}