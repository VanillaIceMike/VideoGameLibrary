#include "genre_frame.h"

GenreFrame::GenreFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    titleLabel = new wxStaticText(this, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, 0);
    Centre();
}