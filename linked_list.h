#include "game.h"

class linked_list{
    private: 
        game *head, *tail;

    public:
        linked_list();

        virtual ~linked_list();

        bool isEmpty() const;
        unsigned listSize() const;

        void append(std::string, float, std::string, std::string, std::string);
};