#include "src/include/raylib.h"
#include <iostream>

int main()
{
    Wave sound = LoadWave("src/audio/button_pressfr.wav");
    if (ExportWaveAsCode(sound, "button_pressfr.h"))
        std::cout << "button_pressfr.h created!" << std::endl;
    else std::cout << "error making " << "button_pressfr.h..." << std::endl;

    return 0;
}