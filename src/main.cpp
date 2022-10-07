#include "raylib.h"
#include <cmath>
#include <memory>

#include "config.hpp"

#include "states/StateManager.hpp"
#include "states/MenuState.hpp"
#include "audio/AudioManager.hpp"
#include "Exiter.hpp"

#include "SaveManager.hpp"


#include "states/EnterScoreState.hpp"
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_NAME);

    SetTargetFPS(FRAME_TARGET);

    srand(time(NULL));

    AudioManager::Get().playSound(_START);

    StateManager::Get().pushState(std::make_shared<MenuState>());

    // seems to default mouse to the center, simply don't want that
    SetMousePosition(-100, -100);
    while (!WindowShouldClose() && !Exiter::Get().ShouldCloseGame())
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