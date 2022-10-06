#ifndef _SAVEMANAGER_HPP_
#define _SAVEMANAGER_HPP_

#include "raylib.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <json/json.h>
#include <json/value.h>

class SaveManager {
private:
    static SaveManager instance;
    std::string savePath;
    //Json::Value saveData;
    SaveManager() {
        #if _WIN32
        std::string appdata = getenv("APPDATA");
        savePath = appdata + "\\.raylibPong";
        if (!std::filesystem::exists(savePath.c_str())) {
            std::cout << "does not exist yo" << appdata << std::endl;
            std::filesystem::current_path(appdata);
            std::cout << "Current path is " << std::filesystem::current_path() << std::endl;
            std::filesystem::create_directory(".raylibPong");
            std::filesystem::current_path(savePath.c_str());

            /*Json::Reader reader;
            Json::StyledStreamWriter writer;

            std::ofstream newFile;
            std::ifstream file(savePath + "saveData.json");

            if (!reader.parse(file, saveData)) {
                //std::cout << reader.getFormatedErrorMessages();
                exit(1);
            }

            saveData[0]["score"] = 2;
            saveData[0]["name"] = "Caduckic";

            newFile.open(savePath + "saveData.json");
            writer.write(newFile, saveData);
            newFile.close();*/
        }
            
        else std::cout << "does exist yo boi" << std::endl;
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
};

SaveManager SaveManager::instance;

#endif