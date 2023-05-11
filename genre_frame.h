#ifndef __GENRE_FRAME_H
#define __GENRE_FRAME_H

#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
//#include <wx/searchctrl.h>
#include <wx/font.h>
#include "catalogManager.h"

class GenreFrame : public wxFrame
{
public:
    GenreFrame(const wxString& title, const wxString& genre, CatalogManager& catalogManager);
    void LoadGamesByGenre();

private:
    wxStaticText* titleLabel;
    wxString genre;
    wxListBox* gameListBox;
    CatalogManager& catalogManager;

};

#endif // __GENRE_FRAME_H
