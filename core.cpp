#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>

#include "map.h"
#include "consoleDrawer.h"
#include "consolecer.h"

struct Settings{
    int size_x = 5;
    int size_y = 10;
    int mines = 40;
}set;
 
class Game{
private:
    Map map;
    ConsoleDrawer drawer;
    ConsoleController controller;
 
    int tick(){
        std::string input;
        std::cin >> input;
        if(input == "stop") return -1;
        else controller.use(input);
       
        //controller.manipulate();
        //map.update();
        //drawer.draw();
       
        return 0;
    }
   
public:
    void new_game(){
        map.create();
        drawer.draw();
        while(tick() == 0){}
    }
};
 
int main(){
    Game game; 
	
	std::string auto_game;
	std::cin >> auto_game;
	if(auto_game != "auto"){
		std::cout << "size x: ";
		std::cin >> set.size_x;
		std::cout <<"size y:";
		std::cin >> set.size_y;
	}
    game.new_game();
   
    return 0;
}