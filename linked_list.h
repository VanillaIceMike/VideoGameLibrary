#include "game.h"

class linked_list{
    private: 
        game *head, *tail;
        unsigned length = 0;

    public:
        linked_list();

        ~linked_list();

        bool isEmpty() const;
        unsigned listSize() const;
        game& operator[](int);

        void remove(int);
        void append(game);
};