// view
class ConsoleDrawer{
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