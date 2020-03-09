#include <iostream>
#include <ctime>
#include <string>
#include <vector>
 
struct Settings{
    int size_x = 5;
    int size_y = 10;
    int mines = 40;
}set;
 
// model
class Map{
private:
    std::vector<bool> mine;
    std::vector<int> state; // 0 - closed, 1 - oppened, 2 - flag
   
    int cell(int x, int y){
        return y * set.size_x + x;
    }
   
    void create_arrays(){
        mine.reserve(set.size_x*set.size_y);
        state.reserve(set.size_x*set.size_y);
    }
   
    void create_mines(){
        int mines_planted = 0;
        while(mines_planted <= set.mines){
            int rand_cell = rand()%(set.size_x*set.size_y);
            if(mine[rand_cell] == 0){
                mine[rand_cell] = 1;
                mines_planted++;
            }
        }
    }
 
    void close_all_cells(){
        for(int i = 0; i < state.size(); i++) state[i] = 0;
    }
 
public:
    void create(){
        create_arrays();
        create_mines();
        close_all_cells();
    }
};
 
// view
class ConcoleDrawer{
private:
   
public:
   
    void draw(){       
        for(int y = 0; y < set.size_y; y++){
            for(int x = 0; x < set.size_x; x++){
                std::cout << "0" << '\t';
            }
            std::cout << std::endl;
        }
    }
};
 
// controller
class ConcoleController{
public:
    void use(std::string input){
       
    }
};
 
class Game{
private:
    Map map;
    ConcoleDrawer drawer;
    ConcoleController controller;
 
    int tick(){
        std::string input;
        std::cin >> input;
        if(input == "stop") return -1;
        else controller.use(input);
       
        controller.manipulate();
        map.update();
        drawer.draw();
       
        return 0;
    }
   
public:
    void new_game(){
        std::cout << "NG\n";
        map.create();
        std::cout << "CREATED\n";
        drawer.draw();
        while(tick() == 0){}
    }
};
 
int main(){
    Game game; 
   
    std::cout << "size x: ";
    std::cin >> set.size_x;
    std::cout <<"size y:";
    std::cin >> set.size_y;
   
    game.new_game();
   
    return 0;
}
