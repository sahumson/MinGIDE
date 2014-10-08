#ifndef NewFile_H
#define NewFile_H

//(*Headers(NewFile)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class NewFile: public wxDialog
{
	public:

		NewFile(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewFile();

		//(*Declarations(NewFile)
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxPanel* Panel3;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxPanel* Panel2;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(NewFile)
		static const long ID_PANEL1;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT5;
		static const long ID_PANEL3;
		//*)

	private:

		//(*Handlers(NewFile)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
