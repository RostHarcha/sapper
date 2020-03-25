#include <vector>
#include "Map.h"

int Map::cell(int x, int y) {
    return y * set.size_x + x;
}

void Map::create_vectors() {
    auto m_size = set.size_x * set.size_y;
    mine.resize(m_size);
    state.resize(m_size);
}

void Map::create_mines() {
    int mines_planted = 0;
    while (mines_planted <= set.mines) {
        int rand_cell = rand() % (set.size_x * set.size_y);
        if (mine[rand_cell] == 0) {
            mine[rand_cell] = 1;
            mines_planted++;
        }
    }
}

void Map::clear_mines() {
    for (int i = 0; i < mine.size(); i++) mine[i] = false;
}

void Map::clear_map() {
    for (int i = 0; i < state.size(); i++) state[i] = 0;
}

void Map::flag(int x, int y) {
    state[cell(x, y)] = 2;
}
void Map::create(Settings _set) {
        set = _set;
        create_vectors();
        clear_map();
        clear_mines();
        create_mines();
 }

std::vector<int> Map::get_current_state() {
    return state;
}

bool Map::on_map(int x, int y) {
    if (x < set.size_x and x >= 0 and y < set.size_y and y >= 0) return 1;
    else return 0;
}

int Map::mines_around(int _x, int _y) {
    int output = 0;
    for (int x = _x - 1; x < _x + 1; x++) {
        for (int y = _y - 1; y < _y + 1; y++) {
            if (on_map(x, y)) if (mine[cell(x, y)]) output++;
        }
    }
    return output;
}

std::vector<int> Map::get_cell_signs() {
    std::vector<int> output;
    for (int x = 0; x < set.size_x; x++) 
        for (int y = 0; y < set.size_y; y++) 
            output.push_back(mines_around(x, y));
    return output;
}