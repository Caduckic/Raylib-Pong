#include "src/include/raylib.h"
#include <iostream>

int main()
{
    Wave test = LoadWave("src/audio/score.wav");
    if (ExportWaveAsCode(test, "./score.h"))
        std::cout << "Success!!!" << std::endl;

    return 0;
}