#include "linked_list.h"
#include <string>

linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list() {
    game* runner;

    while(head != nullptr){
        runner = head;
        head = head->next;
        delete runner;
    }
}

bool linked_list::isEmpty() const {
    if(head){
        return false;
    }

    return true;
}

unsigned linked_list::listSize() const {
    if(!head){
        return 0;
    }
    
    game *runner = head;
    int count = 1;

    while(runner != tail){
        runner = runner->next;
        count++;
    }

    return count;
}

void linked_list::append(std::string gameName, float price, std::string console, std::string genre, std::string esrbRating) {
    if(!head){
        head = new game(gameName, price, console, genre, esrbRating);
        tail = head;
    }
    else{
        tail->next = new game(gameName, price, console, genre, esrbRating);
        tail = tail->next;
    }

    return;
}
