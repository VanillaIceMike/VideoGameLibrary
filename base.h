#ifndef __BASE_H // Make sure to only declare these classes once
#define __BASE_H
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
//#include <wx/searchctrl.h>
#include <wx/font.h>
#include <wx/notebook.h>
#include "catalogManager.h"
#include "genre_frame.h"

class VGLApp : public wxApp // MainApp is the class for our application
{ // MainApp just acts as a container for the window,
public: // or frame in MainFrame
    virtual bool OnInit();
};

class VGLFrame : public wxFrame // MainFrame is the class for our window,
{ // It contains the window and all objects in it
public:
    VGLFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void Quit(wxCommandEvent& event);
    void NewFile(wxCommandEvent& event);
    void OpenFile(wxCommandEvent& event);
    void SaveFile(wxCommandEvent& event);
    void SaveFileAs(wxCommandEvent& event);
    void CloseFile(wxCommandEvent& event);
    void OnGoButton(wxCommandEvent& event);
    void OnGameSelected(wxCommandEvent& event);
    void OnHomeButton(wxCommandEvent& event);
    void OnBlackListButton(wxCommandEvent& event);
    void OnWishListButton(wxCommandEvent& event);
    void LoadGames();


    wxTextCtrl* VGLEditBox;
    wxChoice* genreChoice;
    wxMenuBar* VGLMenu;
    // The Path to the file we have open
    wxString CurrentDocPath;
    wxButton* homeButton;
    wxButton* wishListButton;
    wxButton* blackListButton;
    wxButton* goButton;
    wxSearchCtrl* searchBar;
    CatalogManager catalogManager;
    wxListBox* gameListBox;
    wxNotebook* book;
    wxPanel* homePanel;
    wxPanel* wishlistPanel;
    wxPanel* blacklistPanel;
    DECLARE_EVENT_TABLE()
};

enum
{
    TEXT_Main = wxID_HIGHEST + 1, // declares an id which will be used to call our button
    MENU_New,
    MENU_Open,
    MENU_Close,
    MENU_Save,
    MENU_SaveAs,
    MENU_Quit,
    BUTTON_Home,
    BUTTON_WishList,
    BUTTON_BlackList,
    BUTTON_Go,
    LISTBOX_GameList

};

BEGIN_EVENT_TABLE(VGLFrame, wxFrame)
    EVT_MENU(MENU_New, VGLFrame::NewFile)
    EVT_MENU(MENU_Open, VGLFrame::OpenFile)
    EVT_MENU(MENU_Close, VGLFrame::CloseFile)
    EVT_MENU(MENU_Save, VGLFrame::SaveFile)
    EVT_MENU(MENU_SaveAs, VGLFrame::SaveFileAs)
    EVT_MENU(MENU_Quit, VGLFrame::Quit)
    EVT_BUTTON(BUTTON_Go, VGLFrame::OnGoButton)
    EVT_LISTBOX(LISTBOX_GameList, VGLFrame::OnGameSelected)
END_EVENT_TABLE()

#endif