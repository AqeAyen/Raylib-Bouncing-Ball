#include "raylib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bouncy Boi");

  Vector2 center = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
  Vector2 ballVelocity = {200.0f, 150.0f};

  float radius = 55.0;
  int bounceCount = 0;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    center.x += ballVelocity.x * deltaTime;
    center.y += ballVelocity.y * deltaTime;

    if ((center.x - radius <= 0) || (center.x + radius >= SCREEN_WIDTH)) {
      ballVelocity.x *= -1;
      ++bounceCount;
    }
    if ((center.y - radius <= 0) || (center.y + radius >= SCREEN_HEIGHT)) {
      ballVelocity.y *= -1;
      ++bounceCount;
    }
    ClearBackground(RAYWHITE);
    BeginDrawing();
    DrawCircleV(center, radius, BLACK);
    DrawText(TextFormat("The ball has bounce %d times", bounceCount), 0, 0, 12,
             BLACK);
    EndDrawing();
  }
  return 0;
}
