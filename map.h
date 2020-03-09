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