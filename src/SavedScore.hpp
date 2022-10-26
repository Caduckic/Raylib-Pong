#ifndef _SAVEDSCORE_HPP_
#define _SAVEDSCORE_HPP_

#include <string>

class SavedScore {
private:
    std::string name;
    int score;
public:
    SavedScore(std::string name, int score) : name{name}, score{score} {};
    ~SavedScore() = default;

    std::string getText() const {
        return name + " " + std::to_string(score);
    }

    bool operator<(const SavedScore &rhs) const {
        return (score < rhs.score);
    }

    bool operator>(const SavedScore &rhs) const {
        return (score > rhs.score);
    }
};

#endif