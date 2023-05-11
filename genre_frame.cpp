#include "genre_frame.h"

GenreFrame::GenreFrame(const wxString& title, const wxString& genre, CatalogManager& catalogManager)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)), genre(genre), catalogManager(catalogManager)
{
    SetTransparent(250);

    titleLabel = new wxStaticText(this, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, 0);
    Centre();

    gameListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(400, 350), 0, NULL, wxLB_SINGLE);
    LoadGamesByGenre();
}


void GenreFrame::LoadGamesByGenre() {
    linked_list catalog;
    catalog = catalogManager.getCatalog();
    unsigned catalogSize = catalog.listSize();

    for (unsigned i = 0; i < catalogSize; i++) {
        game currentGame = catalog[i];
        if (currentGame.getSpecs().getGenre() == genre) {
            gameListBox->Append(currentGame.getName());
        }
    }
}