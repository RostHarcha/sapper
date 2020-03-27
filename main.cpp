#include <iostream>
#include "globalStructures.h"
#include "ConsoleDrawer.h"
#include "Map.h"
#include "ConsoleController.h"

constexpr auto DEBUG_MODE = 0;

class Game {
private:
    Map map;
    ConsoleDrawer drawer;
    ConsoleController controller;
    Settings set;
    bool game_over = 0;
    bool win = 0;

    bool is_game_over(std::string action) {
        win = map.win();
        if (win) return 1;
        if (action == "stop") return 1;
        if (map.is_game_over()) return 1;
        return 0;
    }

    void help() {
        std::cout << "General view of the command: [action] <x> <y>\n";
        std::cout << "|help" << "\t\t" << "call for help\n";
        std::cout << "|stop" << "\t\t" << "stop the game\n";
        std::cout << "|open <x> <y>" << "\t" << "open the cell\n";
        std::cout << "|flag <x> <y>" << "\t" << "flag the cell\n";
        std::cout << "|-flag <x> <y>" << "\t" << "remove flag from the cell\n";
    }

    int tick() {
        //system("cls");
        Command input = controller.get_input();
        map.process_tick(input.action, input.x, input.y);
        drawer.draw(map.get_current_state());

        if (input.action == "help") help();
        
        game_over = is_game_over(input.action);
        return 0;
    }

public:
    Game(Settings _set) {
        set = _set;
        set.mines = (set.size_x * set.size_y) * set.mines / 100;
        srand(set.seed);

        map.create(set);
        controller.create(set);
        drawer.create(set, map.get_cell_signs());

        drawer.draw(map.get_current_state());
        for (;!game_over;) tick();
        if(win) std::cout << "\n###Congrats! You won this game!###\n";
        else std::cout << "\nGame over!\n";
        
    }
};

int main() {
    if (DEBUG_MODE) std::cout << "DEBUG MODE\n";
    Settings set;
    if (!DEBUG_MODE) {
        std::cout << "size x: ";
        std::cin >> set.size_x;
        std::cout << "size y: ";
        std::cin >> set.size_y;
        std::cout << "mines percent: ";
        std::cin >> set.mines;
    }

    Game game(set);
	return 0;
}