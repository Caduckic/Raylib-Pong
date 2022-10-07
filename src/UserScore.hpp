#ifndef _USERSCORE_HPP_
#define _USERSCORE_HPP_

#include <string>

class UserScore {
private:
    std::string name;
    int score;
public:
    UserScore(std::string name, int score) : name{name}, score{score} {};
    ~UserScore() = default;

    std::string getName() const {
        return name;
    }

    int getScore() const {
        return score;
    }
};

#endif