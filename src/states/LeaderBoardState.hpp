#ifndef _LEADERBOARDSTATE_HPP_
#define _LEADERBOARDSTATE_HPP_

#include <vector>
#include <memory>
#include "../SaveManager.hpp"
#include "State.hpp"
#include "../entities/ScoreUI.hpp"
#include "../entities/ScrollBox.hpp"

class LeaderBoardState : public State {
private:
    std::vector<SavedScore> loadedScores;
    ScoreUI score;
    ScrollBox scrollBox;
public:
    LeaderBoardState() : loadedScores{SaveManager::Get().getScores()}, score{{500, 300}, {300, 200}, loadedScores.at(0), MEDIUM_FONT_SIZE},
    scrollBox{{100,100}, {800,400}, "scroll", MEDIUM_FONT_SIZE, 3,
    {std::make_shared<ScoreUI>(), std::make_shared<ScoreUI>(), std::make_shared<ScoreUI>(), std::make_shared<ScoreUI>(), std::make_shared<ScoreUI>()}} {};
    ~LeaderBoardState() = default;

    virtual void init() {
        loadedScores = SaveManager::Get().getScores();
        scrollBox.initScrollList();
    }

    virtual void update() override {
        scrollBox.update();
    }

    virtual void render() override {
        for (size_t i {0}; i < loadedScores.size(); i++) {
            DrawText(loadedScores.at(i).getText().c_str(), 400, i * 60, MEDIUM_FONT_SIZE, RAYWHITE);
        }
        scrollBox.draw();
        //score.draw();
    }
};

#endif