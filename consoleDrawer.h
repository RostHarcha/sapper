#include "settings.h"

// view
class ConsoleDrawer{
private:
   Settings set;
public:
	void set(Settings _set){
		set = _set;
	}
	
    void draw(){
        for(int y = 0; y < set.size_y; y++){
            for(int x = 0; x < set.size_x; x++){
                std::cout << "0" << '\t';
            }
            std::cout << std::endl;
        }
    }
};
