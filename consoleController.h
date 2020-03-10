#include "settings.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// controller
class ConsoleController{
private:
	std::vector<std::string> command;

public:
    void use(){
        std::string input;
        std::getline(std::cin, input);
        
		std::stringstream ss(input);
		
		std::string buffer;
		while(ss >> buffer) command.push_back(buffer)
		
		if(command[0] == "flag") std::cout << command[0];
    }
};

int main(){
    ConsoleController controller;
    
    controller.use();
    return 0;
}
