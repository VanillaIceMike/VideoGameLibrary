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

game& linked_list::operator[](int n) {
    game* runner = head;
    for (int i = 0; i < n; i++) runner = runner->next;
    return *runner;
}

void linked_list::append(game newgame) {
    if(!head){
        head = new game(newgame);
        tail = head;
    }
    else{
        tail->next = new game(newgame);
        tail = tail->next;
    }
    tail->setId(length);
    length++;
}


void linked_list::remove(unsigned r) {
    if (r > length) return;

    length--;

    game* runner = head;
    game* prev = nullptr;
    for (int i = 0; i < r; i++) {
    for (unsigned i = 0; i < r; i++) {
        prev = runner;
        runner = runner->next;
    }

    if (runner == head) {
        if (head == tail) tail = nullptr;
        head = head->next;
        delete runner;
        return;
    }

    if (runner == tail) {
        prev->next = nullptr;
        delete runner;
        tail = prev;
        return;
    }

    prev->next = runner->next;
    delete runner;
}
