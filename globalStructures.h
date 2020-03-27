#pragma once
#include <string>
struct Settings {
    int size_x = 15; // 15
    int size_y = 25; // 25
    int mines = 15; // 15
    int seed = 0; // 0
};

struct Command {
    std::string action = "NONE";
    int x = -1;
    int y = -1;
};