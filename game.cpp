#include "game.h"
#include <string>

game::game(){
    
}

game::game(std::string s1, float f1, gameSpec spec){
    gameName = s1;
    for (int i = 0; i < s1.length(); i++) s1[i] = tolower(s1[i]);
    searchName = s1;
    price = f1;

    specs = spec;
}

game::game(const game& newgame) {
    gameName = newgame.getName();
    searchName = newgame.getSearchName();
    price = newgame.getPrice();

    specs = newgame.getSpecs();
}

void game::setName(std::string name){
    gameName = name;
    for (int i = 0; i < name.length(); i++) name[i] = tolower(name[i]);
    searchName = name;
}

void game::setPrice(float p){
    price = p;
}

void game::setId(unsigned n) {
    id = n;
}

std::string game::getName() const{
    return gameName;
}

float game::getPrice() const{
    return price;
}

gameSpec game::getSpecs() const {
    return specs;
}

std::string getSearchName() const {
    retrun searchName;
}
