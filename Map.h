#pragma once
#include "globalStructures.h"
#include <vector>
class Map{
	Settings set;
	std::vector<bool> mine;
	std::vector<int> state; // 0 - closed, 1 - oppened, 2 - flag
	bool game_over = 0;
	int cell(int x, int y);
	void create_vectors();
	void create_mines();
	void clear_mines();
	void clear_map();
	void flag(int x, int y);
	bool on_map(int x, int y);
	int mines_around(int x, int y);
	void flag(int x, int y, char action);
	void open(int x, int y);
	void open_map();

public:
	void create(Settings _set);
	void process_tick(std::string action, int x, int y);
	std::vector<int> get_cell_signs();
	std::vector<int> get_current_state();
	bool is_game_over();
	bool win();
};