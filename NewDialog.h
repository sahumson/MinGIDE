#ifndef NEWDIALOG_H
#define NEWDIALOG_H

//(*Headers(NewDialog)
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include "wx/imaglist.h"
#include "wx/timer.h"           // for wxStopWatch
#include "wx/colordlg.h"        // for wxGetColourFromUser
#include "wx/sysopt.h"
#include "wx/numdlg.h"

//*)

class NewDialog: public wxDialog
{
	public:

		NewDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewDialog();

		//(*Declarations(NewDialog)
		wxTextCtrl* TextCtrl4;
		wxListCtrl* ListCtrl1;
		wxStaticText* StaticText2;
		wxString Test; 
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxPanel* Panel3;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxTextCtrl* TextCtrl2;
		wxTreeCtrl* TreeCtrl1;
		wxTextCtrl* TextCtrl1;
		wxPanel* Panel2;
		wxTextCtrl* TextCtrl5;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		  wxImageList *m_imageListSmall;
		void InitWithIconItems(bool withText, bool sameIcon);
		bool FileSelect;

		void FileSelected(wxCommandEvent& WXUNUSED(event));
		void OnCancel(wxCommandEvent& WXUNUSED(event));
		//*)

	protected:

		//(*Identifiers(NewDialog)
		static const long ID_TREECTRL1;
		static const long ID_LISTCTRL1;
		static const long ID_TEXTCTRL5;
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

		//(*Handlers(NewDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
