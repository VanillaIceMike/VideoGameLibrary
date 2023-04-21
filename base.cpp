#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "base.h"



IMPLEMENT_APP(VGLApp) // Initializes the MainApp class and tells our program
// to run it
bool VGLApp::OnInit()
{
    VGLFrame* VGLWin = new VGLFrame(wxT("Hello World!"), wxPoint(1, 1),
        wxSize(300, 200)); // Create an instance of our frame, or window
    VGLWin->Show(TRUE); // show the window
    SetTopWindow(VGLWin);// and finally, set it as the main window

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

	VGLEditBox = new wxTextCtrl(
		this, TEXT_Main, _("Hi!"), wxDefaultPosition, wxDefaultSize,
		wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);

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