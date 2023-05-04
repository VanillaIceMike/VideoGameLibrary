#include "game.h"
#include <string>

game::game(){

}

game::game(std::string s1, float f1, std::string s2, std::string s3, std::string s4){
    gameName = s1;
    price = f1;

    specs.setConsole(s2);
    specs.setGenre(s3);
    specs.setEsrbRating(s4);
}

void game::setName(std::string name){
    gameName = name;
}

void game::setPrice(float p){
    price = p;
}

std::string game::getName(){
    return gameName;
}

float game::getPrice(){
    return price;
}