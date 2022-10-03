#ifndef _AUDIOMANAGER_HPP_
#define _AUDIOMANAGER_HPP_

#include "raylib.h"
#include <map>
#include <string>
#include "../../score.h"

Wave LoadWaveFromHeader(const WaveSound& sound);
enum GameSounds {notasound, _WALL_BOUNCE, _PADDLE_BOUNCE, _SCORE, _START, _BUTTON};
void InitGameSounds(std::map<GameSounds, Sound>&);

class AudioManager {
private:
    std::map<GameSounds, Sound> sounds;
    static AudioManager instance;
    AudioManager() {
        InitAudioDevice();
        InitGameSounds(sounds);
    };
public:
    static AudioManager& Get() {
        return instance;
    }
    AudioManager(const AudioManager&) = delete;
    ~AudioManager() {CloseAudioDevice();};

    void playSound(GameSounds sound) {
        PlaySound(sounds[sound]);
    }
    void playScore() {

    }
};

AudioManager AudioManager::instance;

void InitGameSounds(std::map<GameSounds, Sound>& sounds) {
    sounds[_WALL_BOUNCE] = LoadSound("../src/audio/wall_bounce.wav");
    sounds[_PADDLE_BOUNCE] = LoadSound("../src/audio/paddle_bounce.wav");
    sounds[_START] = LoadSound("../src/audio/start.wav");
    sounds[_BUTTON] = LoadSound("../src/audio/button_press.wav");

    sounds[_SCORE] = LoadSound("../src/audio/score.wav");
    // Once sounds are finalized, this will be changed to the method below
    //Wave score = LoadWaveFromHeader(SCORE_SOUND);
    //sounds[_SCORE] = LoadSoundFromWave(score);
}

// I assume there is a better way to do this but this works so cool
Wave LoadWaveFromHeader(const WaveSound& sound) {
    Wave audio;
    audio.data = sound.data;
    audio.frameCount = sound.frameCount;
    audio.sampleRate = sound.sampleRate;
    audio.channels = sound.channels;
    audio.sampleSize = sound.sampleSize;
    return audio;
}

#endif