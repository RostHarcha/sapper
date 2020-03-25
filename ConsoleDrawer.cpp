#include <vector>
#include <iostream>

#include "ConsoleDrawer.h"
#include "globalStructures.h"

int ConsoleDrawer::cell(int x, int y) {
	return y * set.size_x + x;
}

void ConsoleDrawer::draw_cell(int x, int y, std::vector<int> state) {
    if (state[cell(x, y)] == 1) std::cout << "[" << cell_sign[cell(x, y)] << "]";
    else if (state[cell(x, y)] == 2) std::cout << "[F]";
    else std::cout << "[ ]";
    //std::cout << "[" << state[cell(x, y)] << "]";

}

void ConsoleDrawer::create(Settings _set, std::vector<int> _cell_sign) {
    set = _set;
    cell_sign = _cell_sign;
}

void ConsoleDrawer::draw(std::vector<int> state) {
    std::cout << "\t ";
    for (int i = 0; i < set.size_x; i++) {
        if (i < 10) std::cout << i << "   ";
        if (9 < i and i < 100) std::cout << i << "  ";
    }
    std::cout << std::endl;
    for (int y = 0; y < set.size_y; y++) {
        std::cout << y << '\t';
        for (int x = 0; x < set.size_x; x++) {
            draw_cell(x, y, state);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}