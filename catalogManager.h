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
    void sortPrice();
    void sortGenre();
};