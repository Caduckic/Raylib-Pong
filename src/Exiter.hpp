#ifndef _EXITER_HPP_
#define _EXITER_HPP_

class Exiter {
private:
    static Exiter instance;
    bool shouldClose;
    Exiter() : shouldClose{false} {};
public:
    Exiter(const Exiter&) = delete;
    static Exiter& Get() {
        return instance;
    }

    bool ShouldCloseGame() {
        return shouldClose;
    }

    void CloseGame() {
        shouldClose = true;
    }
    ~Exiter() = default;
};

Exiter Exiter::instance;


#endif