#include "raylib.h"
#include <cmath>

#include "config.hpp"

#include "states/StateManager.hpp"

int main()
{
    InitWindow(1280, 720, "Pong raylib");

    SetTargetFPS(FRAME_TARGET);

    srand(time(NULL));

    StateManager::Get().pushState("menu");

    //SetMouseCursor(MouseCursor::MOUSE_CURSOR_POINTING_HAND);

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