#include <string>
#include "gameSpec.h"
    
class game {
    private:
        std::string gameName;
        float price;
        unsigned id;
 
    public:
        game *next;  
        gameSpec specs;

        game();
        game(std::string, float, gameSpec);
        game(const game&);

        void setName(std::string);
        void setPrice(float);
        void setId(unsigned);

        std::string getName() const;
        float getPrice() const;
};