#include "linked_list.h"
#include <string>

linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

linked_list::~linked_list() {
    length = 0;
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

void linked_list::clearList() {
    int end = length + 1;
    for (int i = 0; i < end; i++) {
        remove(0);
    }
}

game& linked_list::operator[](int n) const {
    if (n > length) return;
    game* runner = head;
    for (int i = 0; i < n; i++) runner = runner->next;
    return *runner;
}

void linked_list::operator=(const linked_list& l) {
    unsigned end = l.listSize() + 1;
    for (unsigned i = 0; i < end; i++) {
        append(l[i]);
    }
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

void linked_list::swap(unsigned first, unsigned second) {
    if (first > length || second > length) return;

    game temp = (*this)[first];
    (*this)[first] = (*this)[second];
    (*this)[second] = temp;
}