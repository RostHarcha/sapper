#pragma once
#include "globalStructures.h"
#include <vector>
class ConsoleDrawer{
	Settings set;
	std::vector<int> cell_sign;
	int cell(int x, int y);
	void draw_cell(int x, int y, std::vector<int> state);
public:
	void create(Settings _set, std::vector<int> _cell_sign);
	void draw(std::vector<int> state);
};