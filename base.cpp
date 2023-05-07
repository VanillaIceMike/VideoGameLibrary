#include <wx/wxprec.h>
#include <wx/image.h>
#include <wx/wx.h>
#include <wx/srchctrl.h>
#ifndef WX_PRECOMP
#endif

#include "base.h"
#include "genre_frame.h"




IMPLEMENT_APP(VGLApp) // Initializes the MainApp class and tells our program
// to run it
bool VGLApp::OnInit()
{
	VGLFrame* VGLWin = new VGLFrame(wxT("The Video Game Library"), wxPoint(1, 1),
		wxSize(300, 200)); // Create an instance of our frame, or window
	VGLWin->Show(TRUE); // show the window
	SetTopWindow(VGLWin);// and finally, set it as the main window

	// Load the icon and set it for the frame
	wxIcon myIcon;
	myIcon.LoadFile("Icon/icon.ico", wxBITMAP_TYPE_ICO);
	VGLWin->SetIcon(myIcon);

	return TRUE;
}

VGLFrame::VGLFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame((wxFrame*)NULL, -1, title, pos, size)
{
	CreateStatusBar(2);

	VGLMenu = new wxMenuBar();
	wxMenu* FileMenu = new wxMenu();

	FileMenu->Append(MENU_New,
		_("&New"), _("Create a new file"));

	FileMenu->AppendSeparator();
	FileMenu->Append(MENU_Open,
		_("&Open"), _("Open an existing file"));
	FileMenu->Append(MENU_Close,
		_("&Close"), _("Close the current document"));

	FileMenu->AppendSeparator();
	FileMenu->Append(MENU_Save,
		_("&Save"), _("Save the current document"));
	FileMenu->Append(MENU_SaveAs,
		_("Save &As"), _("Save the current document under a new file  name"));

	FileMenu->AppendSeparator();
	FileMenu->Append(MENU_Quit,
		_("&Quit"), _("Quit the editor"));

	VGLMenu->Append(FileMenu, _("&File"));
	SetMenuBar(VGLMenu);

	// Create a wxBoxSizer for vertical alignment of widgets
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	// Load the custom font
	wxFont customFont;
	customFont.AddPrivateFont("Fonts/PressStart2P.ttf");
	wxFont titleFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Press Start 2P"));

	// Create the title with the desired font
	wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, wxT("Video Game Library"), wxDefaultPosition, wxDefaultSize, 0);
	titleLabel->SetFont(titleFont);
	mainSizer->Add(titleLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

	// Create the Home button and add it to the mainSizer
	homeButton = new wxButton(this, BUTTON_Home, wxT("Home"), wxDefaultPosition, wxDefaultSize, 0);
	mainSizer->Add(homeButton, 0, wxALL, 5);

	// Create a wxBoxSizer for horizontal alignment of genre label and dropdown menu
	wxBoxSizer* genreSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create the static text for "Genres of Video Games" and add it to the genreSizer
	wxStaticText* genreLabel = new wxStaticText(this, wxID_ANY, wxT("Genres of Video Games:"), wxDefaultPosition, wxDefaultSize, 0);
	genreSizer->Add(genreLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	// Create the genre choice and add it to the genreSizer
	genreChoice = new wxChoice(this, wxID_ANY);
	genreChoice->Append("Shooter");
	genreChoice->Append("Action/Adventure");
	genreChoice->Append("Simulation");
	genreChoice->Append("MOBA");
	genreChoice->Append("Strategy");
	genreChoice->Append("Fighting");
	genreChoice->Append("Racing");
	genreSizer->Add(genreChoice, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	// Add the genreSizer to the mainSizer
	mainSizer->Insert(1, genreSizer, 0, wxALL | wxALIGN_LEFT, 10);

	// Set the sizer for the frame
	SetSizer(mainSizer);


	// Add the Go button
	goButton = new wxButton(this, BUTTON_Go, wxT("Select Genre"), wxDefaultPosition, wxDefaultSize, 0);
	genreSizer->Add(goButton, 0, wxALL, 5);

	// Add the search control
	wxSearchCtrl* searchBar = new wxSearchCtrl(this, wxID_ANY);
	genreSizer->Add(searchBar, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	Maximize(); // Maximize the window
}

void VGLFrame::NewFile(wxCommandEvent& WXUNUSED(event))
{
	// Clear the edit box
	VGLEditBox->Clear();
	// reset the path of our current open file
	CurrentDocPath = wxT("C:/");
	// Set the Title to reflect the file open
	SetTitle(_("Edit - untitled *"));
}

void VGLFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
		_("Text files (*.txt)|*.txt|") +
		_("C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|") +
		_("C Source files(*.c)|*.c|") +
		_("C header files(*.h)|*.h"),
		wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
	{
		CurrentDocPath = OpenDialog->GetPath();

		// Sets our current document to the file the user selected
		VGLEditBox->LoadFile(CurrentDocPath); //Opens that file
		// Set the Title to reflect the  file open
		SetTitle(wxString("Edit - ") << OpenDialog->GetFilename());
	}
}

void VGLFrame::CloseFile(wxCommandEvent& WXUNUSED(event))
{
	// Clear the Text Box
	VGLEditBox->Clear();
	// Reset the current File being edited
	CurrentDocPath = wxT("C:/");
	// Set the Title to reflect the file open
	SetTitle(_("Edit - untitled *"));
}

void VGLFrame::SaveFile(wxCommandEvent& WXUNUSED(event))
{
	// Save to the already-set path for the document
	VGLEditBox->SaveFile(CurrentDocPath);
}

void VGLFrame::SaveFileAs(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog* SaveDialog = new wxFileDialog(
		this, _("Save File As _?"), wxEmptyString, wxEmptyString,
		_("Text files (*.txt)|*.txt|") +
		_("C++ Source Files (*.cpp)|*.cpp|") +
		_("C Source files(*.c)|*.c|") +
		_("C header files(*.h)|*.h"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
		CurrentDocPath = SaveDialog->GetPath();
		// set the path of our current document to the file the user chose to save under
		VGLEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path
		// Set the Title to reflect the file open
		SetTitle(wxString("Edit - ") << SaveDialog->GetFilename());
	}

	// Clean up after ourselves
	SaveDialog->Destroy();
}

void VGLFrame::Quit(wxCommandEvent& WXUNUSED(event))
{
	Close(TRUE); // Close the window
}

void VGLFrame::OnGoButton(wxCommandEvent& WXUNUSED(event))
{
	wxString genre = genreChoice->GetStringSelection();

	if (!genre.IsEmpty())
	{
		wxString title = genre + wxT(" Page");
		GenreFrame* genrePage = new GenreFrame(title);
		genrePage->Show(true);
	}
	else
	{
		wxMessageBox(wxT("Please select a genre."), wxT("Error"), wxICON_ERROR | wxOK);
	}
}
