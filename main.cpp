#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>

#include "map.h"
#include "consoleDrawer.h"
#include "consolecer.h"
#include "settings.h"
 
class Game{
private:
    Map map;
    ConsoleDrawer drawer;
	ConsoleController controller;
	Settings set;
 
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
    Game(Settings _set){
        set = _set;
		set.mines = (set.size_x*set.size_y)*set.mines/100;
        map.create();
        drawer.draw();
        while(tick() == 0){}
    }
};
 
int main(){
    Settings set;
	std::cout << "size x: ";
	std::cin >> set.size_x;
	std::cout <<"size y: ";
	std::cin >> set.size_y;
	std::cout << "mines percent: ";
	std::cin >> set.mines;
	
    Game game(set);   
    return 0;
}
