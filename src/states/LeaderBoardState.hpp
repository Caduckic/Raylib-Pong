#ifndef _LEADERBOARDSTATE_HPP_
#define _LEADERBOARDSTATE_HPP_

#include <vector>
#include "../SaveManager.hpp"
#include "State.hpp"
#include "../entities/ScoreUI.hpp"

class LeaderBoardState : public State {
private:
    std::vector<SavedScore> loadedScores;
    ScoreUI score;
public:
    LeaderBoardState() : loadedScores{SaveManager::Get().getScores()}, score{{500, 300}, {300, 200}, loadedScores.at(0), MEDIUM_FONT_SIZE} {};
    ~LeaderBoardState() = default;

    virtual void init() {
        loadedScores = SaveManager::Get().getScores();
    }

    virtual void update() override {

    }

    virtual void render() override {
        for (size_t i {0}; i < loadedScores.size(); i++) {
            DrawText(loadedScores.at(i).getText().c_str(), 400, i * 60, MEDIUM_FONT_SIZE, RAYWHITE);
        }

        score.draw();
    }
};

#endif