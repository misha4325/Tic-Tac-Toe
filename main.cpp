#include "game_engine.hpp"
#include <iostream>

int main() {
    GameEngine engine;
    engine.Init();
    engine.Run();
    std::cout<<"Ended";
    return 0;
}