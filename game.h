#include <string>
#include "gameSpec.h"
    
class game {
    private:
        std::string gameName;
        std::string searchName;
        float price;
        unsigned id;
        gameSpec specs;
 
    public:
        game *next;

        game();
        game(std::string, float, gameSpec);
        game(const game&);

        void setName(std::string);
        void setPrice(float);

        std::string getName() const;
        float getPrice() const;
        gameSpec getSpecs() const;
        std::string getSearchName() const;
        unsigned getId() const;
};
