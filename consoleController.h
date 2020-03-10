#include "settings.h"

// controller
class ConsoleController{
private:
	std::vector<std::string> command;

public:
    void use(std::string input){
        std::cout << "USE\n";
		std::stringstream ss(input);
		while(!ss.eof()){
			ss >> command.back();
		}
		
		if(command[0] == "flag") std::cout << command[0];
    }
};
