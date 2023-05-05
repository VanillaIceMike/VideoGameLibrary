#include "game.h"
#include <string>

game::game(){
    
}

game::game(std::string s1, float f1, gameSpec spec){
    for (int i = 0; i < s1.length(); i++) s1[i] = tolower(s1[i]);
    gameName = s1;
    price = f1;

    specs = spec;
}

game::game(const game& newgame) {
    gameName = newgame.getName();
    price = newgame.getPrice();

    specs = newgame.specs;
}

void game::setName(std::string name){
    for (int i = 0; i < name.length(); i++) name[i] = tolower(name[i]);
    gameName = name;
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