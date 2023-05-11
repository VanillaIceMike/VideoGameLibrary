#ifndef __GENRE_FRAME_H
#define __GENRE_FRAME_H

#include <wx/frame.h>
#include <wx/stattext.h>

class GenreFrame : public wxFrame
{
public:
    GenreFrame(const wxString& title);

private:
    wxStaticText* titleLabel;
};

#endif // __GENRE_FRAME_H
