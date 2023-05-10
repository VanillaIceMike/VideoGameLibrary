#include "catalogManager.h"
#include <fstream>
#include <iostream>

void MergeSort(game**, int);
game* SortedMerge(game* a, game* b, int);
void FrontBackSplit(game* source, game** frontRef, game** backRef);

CatalogManager::CatalogManager() {
    std::ifstream infile;

    std::string name;
    std::string stringPrice;
    float price;
    std::string console;
    std::string genre;
    std::string esrbRating;
    std::string developer;

    infile.open("games.txt", std::ifstream::in);

    while (!infile.eof()) {
        std::getline(infile, name, '\t');
        std::getline(infile, stringPrice, '\t');
        std::getline(infile, console, '\t');
        std::getline(infile, genre, '\t');
        std::getline(infile, esrbRating, '\t');
        std::getline(infile, developer);

        price = stof(stringPrice);

        catalog.append(game(name, price, gameSpec(console, genre, esrbRating, developer)));
    }

    infile.close();
}

void CatalogManager::addToCatalog(game g) {
    catalog.append(g);
}

void CatalogManager::addToBlacklist(game g) {
    blacklist.append(g);
    for (unsigned j = 0; j < catalog.listSize(); j++) {
        if (catalog[j].getName() == g.getName()) {
            catalog.remove(j);
            return;
        }
    }
}

void CatalogManager::addToWishlist(game g) {
    wishlist.append(g);
}

linked_list& CatalogManager::getCatalog() {
    return catalog;
}

linked_list& CatalogManager::getBlacklist() {
    return blacklist;
}

linked_list& CatalogManager::getWishlist() {
    return wishlist;
}

void CatalogManager::sortAlpha() {
    game* head = &catalog[0];
    MergeSort(&head, 0);
    head = &blacklist[0];
    MergeSort(&head, 0);
    head = &wishlist[0];
    MergeSort(&head, 0);
    head = &filteredCatalog[0];
    MergeSort(&head, 0);
}

void CatalogManager::sortPrice() {
    game* head = &catalog[0];
    MergeSort(&head, 1);
    head = &blacklist[0];
    MergeSort(&head, 1);
    head = &wishlist[0];
    MergeSort(&head, 1);
    head = &filteredCatalog[0];
    MergeSort(&head, 1);
}

void CatalogManager::sortGenre() {
    game* head = &catalog[0];
    MergeSort(&head, 2);
    head = &blacklist[0];
    MergeSort(&head, 2);
    head = &wishlist[0];
    MergeSort(&head, 2);
    head = &filteredCatalog[0];
    MergeSort(&head, 2);
}

linked_list& CatalogManager::searchCatalog(std::string s) {
    filteredCatalog.clearList();
    unsigned end = catalog.listSize();
    for (unsigned i = 0; i < end; i++) {
        if (catalog[i].getSearchName().find(s) != std::string::npos) {
            filteredCatalog.append(catalog[i]);
        }
    }
    return filteredCatalog;
}

linked_list& CatalogManager::searchBlacklist(std::string s) {
    filteredCatalog.clearList();
    unsigned end = blacklist.listSize();
    for (unsigned i = 0; i < end; i++) {
        if (blacklist[i].getSearchName().find(s) != std::string::npos) {
            filteredCatalog.append(blacklist[i]);
        }
    }
    return filteredCatalog;
}

linked_list& CatalogManager::searchWishlist(std::string s) {
    filteredCatalog.clearList();
    unsigned end = wishlist.listSize();
    for (unsigned i = 0; i < end; i++) {
        if (wishlist[i].getSearchName().find(s) != std::string::npos) {
            filteredCatalog.append(wishlist[i]);
        }
    }
    return filteredCatalog;
}

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(game** headRef, int type)
{
    game* head = *headRef;
    game* a;
    game* b;

    /* Base case -- length 0 or 1 */
    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a, type);
    MergeSort(&b, type);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b, type);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
game* SortedMerge(game* a, game* b, int type)
{
    game* result = nullptr;

    /* Base cases */
    if (a == nullptr)
        return (b);
    else if (b == nullptr)
        return (a);

    /* Pick either a or b, and recur */
    bool compare;
    if (type == 0) compare = a->getSearchName() <= b->getSearchName();
    else if (type == 1) compare = a->getPrice() <= b->getPrice();
    else compare = a->getSpecs().getGenre() <= b->getSpecs().getGenre();

    if (compare) {
        result = a;
        result->next = SortedMerge(a->next, b, type);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next, type);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(game* source, game** frontRef, game** backRef)
{
    game* fast;
    game* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}