#include "NewDialog.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(NewDialog)
#include <wx/settings.h>
//#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewDialog)
const long NewDialog::ID_TREECTRL1 = wxNewId();
const long NewDialog::ID_LISTCTRL1 = wxNewId();
const long NewDialog::ID_TEXTCTRL5 = wxNewId();
const long NewDialog::ID_PANEL1 = wxNewId();
const long NewDialog::ID_TEXTCTRL4 = wxNewId();
const long NewDialog::ID_TEXTCTRL1 = wxNewId();
const long NewDialog::ID_TEXTCTRL3 = wxNewId();
const long NewDialog::ID_TEXTCTRL2 = wxNewId();
const long NewDialog::ID_BUTTON1 = wxNewId();
const long NewDialog::ID_STATICTEXT1 = wxNewId();
const long NewDialog::ID_STATICTEXT2 = wxNewId();
const long NewDialog::ID_STATICTEXT3 = wxNewId();
const long NewDialog::ID_STATICTEXT4 = wxNewId();
const long NewDialog::ID_PANEL2 = wxNewId();
const long NewDialog::ID_STATICTEXT5 = wxNewId();
const long NewDialog::ID_PANEL3 = wxNewId();
//*)

static const int NUM_ICONS = 9;
BEGIN_EVENT_TABLE(NewDialog,wxDialog)
	//(*EventTable(NewDialog)
	//*)
END_EVENT_TABLE()

NewDialog::NewDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(NewDialog)
	Create(parent, wxID_ANY, wxT("New Project"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE| wxOK , _T("wxID_ANY"));
	SetClientSize(wxSize(1031,693));
	SetBackgroundColour(wxColour(188,199,216));
	TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxPoint(0,40), wxSize(272,472), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	//ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxPoint(280,40), wxSize(464,472), 0, wxDefaultValidator, _T("ID_LISTCTRL1"));
	//ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1,  wxPoint(280,40), wxSize(464,472), wxLC_REPORT|wxLC_MASK_TYPE|);
	ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1,  wxPoint(280,40),  wxSize(464,472), wxLC_SMALL_ICON);
	
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("Select and Enter the name of Project \n Enter a valid Project name"), wxPoint(752,40), wxSize(280,472), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,640), wxSize(1032,56), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(42,58,87));
	Button2 = new wxButton(Panel1, wxID_OK, _("OK"), wxPoint(832,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxPoint(920,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,512), wxSize(1032,128), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel2->SetBackgroundColour(wxColour(188,199,216));
	TextCtrl4 = new wxTextCtrl(Panel2, ID_TEXTCTRL4, _("<Enter_name>"), wxPoint(160,56), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("c:/users/sricharan/documents/visual studio 2010/Projects"), wxPoint(160,32), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, _("Create a New solution"), wxPoint(160,80), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, _("<Enter_name>"), wxPoint(160,8), wxSize(560,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(Panel2, ID_BUTTON1, _("Browse"), wxPoint(736,32), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Name:"), wxPoint(24,16), wxSize(128,16), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Location:"), wxPoint(24,40), wxSize(128,13), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Solution:"), wxPoint(24,64), wxSize(128,13), 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Solution name:"), wxPoint(24,88), wxSize(128,13), 0, _T("ID_STATICTEXT4"));
	Panel3 = new wxPanel(this, ID_PANEL3, wxPoint(0,0), wxSize(1032,40), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Panel3->SetBackgroundColour(wxColour(188,199,216));
	StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("New Project"), wxPoint(0,0), wxSize(1032,40), 0, _T("ID_STATICTEXT5"));
	StaticText5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	StaticText5->SetBackgroundColour(wxColour(42,58,87));


	m_imageListSmall = new wxImageList(50, 50, false);
	
	//wxMessageBox(wxGetCwd());
	wxBitmap cpp(wxT( "resource/cpp2.png"), wxBITMAP_TYPE_PNG);
	wxBitmap wx(wxT( "resource/wx.png"), wxBITMAP_TYPE_PNG);
	wxBitmap vtk(wxT( "resource/vtk.png"), wxBITMAP_TYPE_PNG);
	wxBitmap itk(wxT( "resource/itkj.png"), wxBITMAP_TYPE_PNG);
	wxBitmap opengl(wxT( "resource/opengl.png"), wxBITMAP_TYPE_PNG);
	wxBitmap NVIDIA(wxT( "resource/NVIDIA.png"), wxBITMAP_TYPE_PNG);
	wxBitmap opencv(wxT( "resource/opencv.png"), wxBITMAP_TYPE_PNG);
	wxBitmap matlab(wxT( "resource/matlab.png"), wxBITMAP_TYPE_PNG);
	wxBitmap python(wxT( "resource/python.png"), wxBITMAP_TYPE_PNG);

	m_imageListSmall->Add(cpp,wxSize(50,50));
	m_imageListSmall->Add(wx,wxSize(50,50) );
    m_imageListSmall->Add(vtk,wxSize(50,50));
    m_imageListSmall->Add(itk,wxSize(50,50) );
    m_imageListSmall->Add( opengl,wxSize(50,50));
    m_imageListSmall->Add( NVIDIA,wxSize(50,50) );
    m_imageListSmall->Add( opencv,wxSize(50,50) );
    m_imageListSmall->Add( matlab,wxSize(50,50));
    m_imageListSmall->Add( python,wxSize(50,50) );
	

	ListCtrl1->InsertItem(0, wxT("C++"), 0);
	ListCtrl1->InsertItem(1, wxT("wxWidgets"), 1);
	ListCtrl1->InsertItem(2, wxT("VTK"), 2);
	ListCtrl1->InsertItem(3, wxT("ITK"), 3);
	ListCtrl1->InsertItem(4, wxT("OpenGL"), 4);
	ListCtrl1->InsertItem(5, wxT("NVIDIA"), 5);
	ListCtrl1->InsertItem(6, wxT("OpenCV"), 6);
	ListCtrl1->InsertItem(7, wxT("Python"), 8);
	ListCtrl1->InsertItem(8, wxT("Matlab MEX"), 7);
	ListCtrl1->SetImageList(m_imageListSmall, wxIMAGE_LIST_SMALL);
	//InitWithIconItems(true, false);
	//ListCtrl1->InsertItem(0, wxT("Wx"), 1);
}

NewDialog::~NewDialog()
{
	//(*Destroy(NewDialog)
	//*)
}


void NewDialog::InitWithIconItems(bool withText, bool sameIcon)
{
    //ListCtrl1->SetImageList(m_imageListSmall, wxIMAGE_LIST_SMALL);

    //for ( int i = 0; i < NUM_ICONS; i++ )
    //{
    //    int image = sameIcon ? 0 : i;

    //    if ( withText )
    //    {
    //        // Make labels of different widths to test the layout.
    //        wxString label;
    //        if ( !(i % 5) )
    //            label.Printf("Longer label %d", i);
    //        else
    //            label.Printf("Label %d", i);

    //        ListCtrl1->InsertItem(i, label, image);
    //    }
    //    else
    //    {
    //        ListCtrl1->InsertItem(i, image);
    //    }
    //}
}