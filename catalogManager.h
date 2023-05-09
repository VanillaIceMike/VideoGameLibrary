#ifndef CATALOGMANAGER_H
#define CATALOGMANAGER_H

#include "linked_list.h"

class CatalogManager {
private:
    linked_list catalog;
    linked_list blacklist;
    linked_list wishlist;
public:
    CatalogManager();
    void addToCatalog(game);
    void addToBlacklist(game);
    void addToWishlist(game);
    void sortAlpha();
    void sortPrice();
    void sortGenre();
    linked_list& search(std::string);
    linked_list& getCatalog();
    linked_list& getBlacklist();
    linked_list& getWishlist();
};

#endif // CATALOGMANAGER_H