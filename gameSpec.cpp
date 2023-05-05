#include "gameSpec.h"
#include <string>

gameSpec::gameSpec(){

}

gameSpec::gameSpec(std::string x, std::string y, std::string z, std::string dev){
    console = x;
    genre = y;
    esrbRating = z;
    developer = dev;
}

void gameSpec::operator=(const gameSpec& RHS) {
    console = RHS.getConsole();
    genre = RHS.getGenre();
    esrbRating = RHS.getEsrbRating();
    developer = RHS.getDeveloper();
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

std::string gameSpec::getConsole() const {
    return console;
}

std::string gameSpec::getGenre() const {
    return genre;
}

std::string gameSpec::getEsrbRating() const {
    return esrbRating;
}

std::string gameSpec::getDeveloper() const {
    return developer;
}