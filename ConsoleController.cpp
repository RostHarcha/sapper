#include "ConsoleController.h"
#include <sstream>
#include <iostream>
#include <string>

std::vector<std::string> ConsoleController::decompose_command(std::string input) {
    std::vector<std::string> output;
    std::stringstream ss(input);
    std::string buffer;
    while (ss >> buffer) output.push_back(buffer);
    return output;
}

Command ConsoleController::analyse_command(std::vector<std::string> command) {
    Command output;

    switch (command.size()) {
    case 1:
        output.action = command[0];
        if (command[0] == "stop") command[0] = "game_over";
        return output;
    case 3:
        output = { command[0], std::atoi(command[1].c_str()), std::atoi(command[2].c_str()) };
        break;
    default:
        return output;
    }
    return output;
}

void ConsoleController::create(Settings _set) {
    set = _set;
}

Command ConsoleController::get_input() {
    std::string input;
    std::getline(std::cin, input);

    return analyse_command(decompose_command(input));
}