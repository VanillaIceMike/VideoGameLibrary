#include <string>
#include "gameSpec.h"
    
class game {
    private:
        std::string gameName;
        float price;
 
    public:
        game *next;  
        gameSpec specs;

        game();
        game(std::string, float, std::string, std::string, std::string);

        void setName(std::string);
        void setPrice(float);

        std::string getName();
        float getPrice();
};