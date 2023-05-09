#ifndef GAME_H
#define GAME_H

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

        void operator=(const game&);

        void setName(std::string);
        void setPrice(float);
        void setId(unsigned);

        std::string getName() const;
        float getPrice() const;
        gameSpec getSpecs() const;
        std::string getSearchName() const;
        unsigned getId() const;
};

#endif // GAME_H