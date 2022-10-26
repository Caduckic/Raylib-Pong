#ifndef _WAVESOUND_HPP_
#define _WAVESOUND_HPP_

struct WaveSound
{
    const unsigned int frameCount = 22403;
    const unsigned int sampleRate = 44100;
    const unsigned int sampleSize = 16;
    const unsigned int channels = 1;
    unsigned char* data;
};


#endif