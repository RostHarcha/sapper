#include <iostream>
#include "globalStructures.h"
#include "ConsoleDrawer.h"
#include "Map.h"
#include "ConsoleController.h"

constexpr auto DEBUG_MODE = 1;

class Game {
private:
    Map map;
    ConsoleDrawer drawer;
    ConsoleController controller;
    Settings set;

    int tick() {
        std::string input;
        std::cin >> input;
        if (input == "stop") return -1;
        //else controller.use();

        else {

        }

        //controller.manipulate();
        //map.update();
        //drawer.draw();

        return 0;
    }

public:
    Game(Settings _set) {
        set = _set;
        set.mines = (set.size_x * set.size_y) * set.mines / 100;

        map.create(set);
        controller.create(set);
        drawer.create(set, map.get_cell_signs());

        drawer.draw(map.get_current_state());
        while (tick() == 0) {}
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