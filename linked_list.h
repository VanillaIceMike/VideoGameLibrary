#include "game.h"

class linked_list{
    private: 
        game *head, *tail;
        unsigned length = 0;

    public:
        linked_list();

        virtual ~linked_list();

        bool isEmpty() const;
        unsigned listSize() const;
        game& operator[](int);

<<<<<<< HEAD
=======
        void remove(unsigned);
>>>>>>> a2ae984c5e20d2eafe7e5f146127829d0b178d91
        void append(game);
        void remove(int r);
};