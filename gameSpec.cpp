#include "gameSpec.h"
#include <string>

gameSpec::gameSpec(){

}

gameSpec::gameSpec(std::string x, std::string y, std::string z){
    console = x;
    genre = y;
    esrbRating = z;
}

void gameSpec::setConsole(std::string x){
    console = x;
}

void gameSpec::setGenre(std::string y){
    genre = y;
}

void gameSpec::setEsrbRating(std::string z){
    esrbRating = z;
}

std::string gameSpec::getConsole(){
    return console;
}

std::string gameSpec::getGenre(){
    return genre;
}

std::string gameSpec::getEsrbRating(){
    return esrbRating;
}