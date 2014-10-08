#include "NewFile.h"

//(*InternalHeaders(NewFile)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewFile)
const long NewFile::ID_PANEL1 = wxNewId();
const long NewFile::ID_TEXTCTRL4 = wxNewId();
const long NewFile::ID_TEXTCTRL1 = wxNewId();
const long NewFile::ID_TEXTCTRL3 = wxNewId();
const long NewFile::ID_TEXTCTRL2 = wxNewId();
const long NewFile::ID_BUTTON1 = wxNewId();
const long NewFile::ID_STATICTEXT1 = wxNewId();
const long NewFile::ID_STATICTEXT2 = wxNewId();
const long NewFile::ID_STATICTEXT3 = wxNewId();
const long NewFile::ID_STATICTEXT4 = wxNewId();
const long NewFile::ID_PANEL2 = wxNewId();
const long NewFile::ID_STATICTEXT5 = wxNewId();
const long NewFile::ID_PANEL3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewFile,wxDialog)
	//(*EventTable(NewFile)
	//*)
END_EVENT_TABLE()

NewFile::NewFile(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(NewFile)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1031,207));
	SetBackgroundColour(wxColour(188,199,216));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,152), wxSize(1032,56), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(42,58,87));
	Button2 = new wxButton(Panel1, wxID_OK, _("OK"), wxPoint(832,16), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	Button3 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxPoint(920,16), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,40), wxSize(1032,112), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel2->SetBackgroundColour(wxColour(188,199,216));
	TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxPoint(160,56), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(160,32), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxPoint(160,80), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxPoint(160,8), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(Panel2, ID_BUTTON1, _("Browse"), wxPoint(736,32), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Name:"), wxPoint(24,16), wxSize(128,16), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Location:"), wxPoint(24,40), wxSize(128,13), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Solution:"), wxPoint(24,64), wxSize(128,13), 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Solution name:"), wxPoint(24,88), wxSize(128,13), 0, _T("ID_STATICTEXT4"));
	Panel3 = new wxPanel(this, ID_PANEL3, wxPoint(0,0), wxSize(1032,40), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Panel3->SetBackgroundColour(wxColour(188,199,216));
	StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("New File"), wxPoint(0,0), wxSize(1032,40), 0, _T("ID_STATICTEXT5"));
	StaticText5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	StaticText5->SetBackgroundColour(wxColour(42,58,87));
	//*)
}

NewFile::~NewFile()
{
	//(*Destroy(NewFile)
	//*)
}

