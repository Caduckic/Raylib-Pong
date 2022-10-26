#ifndef _SAVEMANAGER_HPP_
#define _SAVEMANAGER_HPP_

#include "raylib.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"
#include "SavedScore.hpp"


class SaveManager {
private:
    static SaveManager instance;
    std::string savePath;
    Json::Value saveData;
    SaveManager() {
        #if _WIN32
        std::string appdata = getenv("APPDATA");
        savePath = appdata + "\\.raylibPong";
        if (!std::filesystem::exists(savePath + "\\saveData.json")) {
            std::cout << "no save data found" << std::endl;

            std::filesystem::current_path(appdata);
            std::filesystem::create_directory(".raylibPong");

            Json::StyledStreamWriter writer;

            std::ofstream file(savePath + "\\saveData.json");

            Json::Value user;
            std::string na = "jeff";
            user["name"] = na;
            user["score"] = 4;

            saveData["scores"] = Json::arrayValue;
            saveData["scores"].append(user);

            writer.write(file, saveData);
            file.close();
        }
            
        else {
            std::cout << "save data found" << std::endl;
            
            Json::Reader reader;
            std::ifstream file(savePath + "\\saveData.json");

            if (!reader.parse(file, saveData)) {
                std::cout << reader.getFormattedErrorMessages();
            }

            std::cout << saveData["scores"][0]["name"].asString() << std::endl;
        }
	    
	    #elif __linux__
            std::string localShare = getenv("HOME");
            localShare += "/.local/share";
            savePath = localShare + "/.raylibPong";
            if (!std::filesystem::exists(savePath + "/saveData.json")) {
                std::cout << "no save data found" << std::endl;

                std::filesystem::current_path(localShare);
                std::filesystem::create_directory(".raylibPong");

                Json::StyledStreamWriter writer;

                std::ofstream file(savePath + "/saveData.json");

                Json::Value user;
                std::string na = "jeff";
                user["name"] = na;
                user["score"] = 4;

                saveData["scores"] = Json::arrayValue;
                saveData["scores"].append(user);

                writer.write(file, saveData);
                file.close();
            }

            else {
                std::cout << "save data found" << std::endl;
                
                Json::Reader reader;
                std::ifstream file(savePath + "/saveData.json");

                if (!reader.parse(file, saveData)) {
                    std::cout << reader.getFormattedErrorMessages();
                }

                std::cout << saveData["scores"][0]["name"].asString() << std::endl;
            }
        #elif __APPLE__

        #endif
        //else if (DirectoryExists("$HOME/.local/share"))
            //if (!DirectoryExists("$HOME/.local/share/Raylib-Pong"))
    }

    void fetchSaveData() {
        Json::Reader reader;

         #if _WIN32
            std::ifstream file(savePath + "\\saveData.json");
        #elif __linux__
            std::ifstream file(savePath + "/saveData.json");
        #endif

        if (!reader.parse(file, saveData)) {
            std::cout << reader.getFormattedErrorMessages();
        }
    }
public:
    static SaveManager& Get() {
        return instance;
    }
    SaveManager(const SaveManager&) = delete;
    ~SaveManager() = default;

    void saveScore(const std::string name, const int score) {
        Json::StyledStreamWriter writer;

        // idk if this is needed but for now it'll work
        #if _WIN32
            std::ofstream file(savePath + "\\saveData.json");
        #elif __linux__
            std::ofstream file(savePath + "/saveData.json");
        #endif

        Json::Value user;
        user["name"] = name;
        user["score"] = score;

        saveData["scores"].append(user);

        writer.write(file, saveData);
        file.close();
    }

    std::vector<SavedScore> getScores() {
        fetchSaveData();
        std::vector<SavedScore> scores {};
        for (int i {0}; i < saveData["scores"].size(); i++) {
            SavedScore score {
                saveData["scores"][i]["name"].asString(),
                saveData["scores"][i]["score"].asInt()
            };
            scores.push_back(score);
        }
        std::sort(scores.begin(), scores.end(), [](SavedScore a, SavedScore b) {return a>b;});
        return scores;
    }

    std::string getNameAt(int index) {
        return saveData["scores"][index]["name"].asString();
    }

    int getScoreAt(int index) {
        return saveData["scores"][index]["score"].asInt();
    }
};

SaveManager SaveManager::instance;

#endif