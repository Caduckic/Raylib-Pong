#include "raylib.h"
#include <cmath>
#include <memory>

#include "config.hpp"

#include "states/StateManager.hpp"
#include "states/MenuState.hpp"
#include "AudioManager.hpp"
#include "Exiter.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void updateAndDraw();

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_NAME);

    SetTargetFPS(FRAME_TARGET);

    srand(time(NULL));

    #ifndef PLATFORM_WEB
    AudioManager::Get().playSound(_START);
    #endif

    StateManager::Get().pushState(std::make_shared<MenuState>());

    // seems to default mouse to the center, simply don't want that
    SetMousePosition(-100, -100);

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(updateAndDraw, 0, 1);
    #else
        SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose() && !Exiter::Get().ShouldCloseGame())    // Detect window close button or ESC key
        {
            updateAndDraw();
        }
    #endif

    CloseWindow();

    return 0;
}

void updateAndDraw() {
    BeginDrawing();

    ClearBackground({20, 20, 20, 255});

    StateManager::Get().update();
    StateManager::Get().render();

    EndDrawing();
}