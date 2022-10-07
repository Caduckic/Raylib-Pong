#ifndef _SAVEMANAGER_HPP_
#define _SAVEMANAGER_HPP_

#include "raylib.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"

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
            std::cout << "does not exist yo" << appdata << std::endl;

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
            std::cout << "does exist yo boi" << std::endl;
            
            Json::Reader reader;
            std::ifstream file(savePath + "\\saveData.json");

            if (!reader.parse(file, saveData)) {
                std::cout << reader.getFormattedErrorMessages();
            }

            std::cout << saveData["scores"][0]["name"].asString() << std::endl;
        }
        #elif __APPLE__
	    
	    #elif __LINUX__

        #endif
        //else if (DirectoryExists("$HOME/.local/share"))
            //if (!DirectoryExists("$HOME/.local/share/Raylib-Pong"))
    }
public:
    static SaveManager& Get() {
        return instance;
    }
    SaveManager(const SaveManager&) = delete;
    ~SaveManager() = default;

    void saveScore(const std::string name, const int score) {
        Json::StyledStreamWriter writer;
        std::ofstream file(savePath + "\\saveData.json");

        Json::Value user;
        user["name"] = name;
        user["score"] = score;

        saveData["scores"].append(user);

        writer.write(file, saveData);
        file.close();
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