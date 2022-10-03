#include "raylib.h"
#include <cmath>

#include "config.hpp"

#include "states/StateManager.hpp"
#include "audio/AudioManager.hpp"

int main()
{
    InitWindow(1280, 720, "Pong raylib");

    SetTargetFPS(FRAME_TARGET);

    srand(time(NULL));

    AudioManager::Get().playSound(_START);

    StateManager::Get().pushState("menu");

    // seems to default mouse to the center, simply don't want that
    SetMousePosition(-100, -100);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground({20, 20, 20, 255});

        StateManager::Get().update();
        StateManager::Get().render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}