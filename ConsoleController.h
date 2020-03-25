#pragma once
#include <vector>
#include "globalStructures.h"
class ConsoleController{
	Settings set;
	std::vector<std::string> decompose_command(std::string input);
	Command analyse_command(std::vector<std::string> command);
public:
	void create(Settings _set);
	Command get_input();
};