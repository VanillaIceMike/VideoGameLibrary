#include "catalogManager.h"
#include <fstream>
#include <iostream>

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

<<<<<<< HEAD
        price = stof(stringPrice);
=======
        try {
            price = stof(stringPrice);
        }
        catch (const std::invalid_argument& e) {
            // You can print the error message and continue with the next iteration or exit the program
            std::cerr << "Invalid price format: " << stringPrice << " (Error: " << e.what() << ")" << std::endl;
            continue;
        }
>>>>>>> a5f19de1318f9c745333c6dcb485fe6c2cd4c591

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
    
}

void CatalogManager::sortPrice() {

}

void CatalogManager::sortGenre() {
    
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