//#include "wx/app.h"
#include "wx/grid.h"
#include "wx/treectrl.h"
#include "wx/spinctrl.h"
#include "wx/artprov.h"
#include "wx/clipbrd.h"
#include "wx/image.h"
#include "wx/colordlg.h"
#include "wx/wxhtml.h"
#include "wx/imaglist.h"
#include "wx/dataobj.h"
#include "wx/dcclient.h"
#include "wx/bmpbuttn.h"
#include "wx/menu.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include <wx/dirctrl.h>
#include <wx/aboutdlg.h>
#include "wx/aui/aui.h"
#include "wx/image.h"
#include "wx/html/htmlwin.h"
#include "wx/html/htmprint.h"
#include "wx/cmdline.h"
#include <wx/mimetype.h>
#include <wx/utils.h>
#include "wx/generic/treectlg.h"
#include "wx/txtstrm.h"
#include "wx/numdlg.h"
#include "wx/textdlg.h"
#include "wx/ffile.h"
#include "wx/scopedptr.h"
#include "wx/stopwatch.h"
#include "wx/process.h"
#include "wx/mimetype.h"
#include <wx/statline.h>
#include <wx/xml/xml.h>

//! wxWidgets headers
#include "wx/config.h"     // configuration support
#include "wx/filedlg.h"    // file dialog support
#include "wx/filename.h" // filename support
#include "wx/notebook.h" // notebook support
#include "wx/settings.h" // system settings
#include "wx/string.h"     // strings support
#include "wx/image.h"      // images support
#include "defsext.h"        // Additional definitions
#include "edit.h"           // Edit module
#include "prefs.h"          // Prefs
#include <string>
#include <vector>
#include <algorithm>
#include "wx/filename.h"
#include "wx/dir.h"

#include <map>
#include <memory>
#include <wx/sstream.h>
#include <wx/wfstream.h>
// Main propertygrid header.
#include <wx/propgrid/propgrid.h>

// Extra property classes.
#include <wx/propgrid/advprops.h>

// This defines wxPropertyGridManager.
#include <wx/propgrid/manager.h>

//#include "PropertyGrid.h"
#include <wx/popupwin.h>

#include "NewFile.h"
#include "NewDialog.h"
//----------------------------------------------------------------------------
//! global application name
wxString *g_appname = NULL;

#if wxUSE_PRINTING_ARCHITECTURE

//! global print data, to remember settings during the session
wxPrintData *g_printData = (wxPrintData*) NULL;
wxPageSetupDialogData *g_pageSetupData = (wxPageSetupDialogData*) NULL;

#endif // wxUSE_PRINTING_ARCHITECTURE

using namespace std;


//class MyTreeItemData : public wxTreeItemData
//{
//public:
//     MyTreeItemData(const wxString& desc) : m_desc(desc) { }
//
//     void ShowInfo(wxTreeCtrl *tree);
//     const wxChar *GetDesc() const { return m_desc.c_str(); }
//
//private:
//     wxString m_desc;
//};

// ----------------------------------------------------------------------------
// MyPipeFrame: allows the user to communicate with the child process
// ----------------------------------------------------------------------------



class MyFrame: public wxFrame
{

public:
       ~MyFrame();
       wxPanel* panel_2;
       wxTimer *timer;
	   wxAuiToolBar* tb2;
	   wxAuiToolBar* tb3;
        bool issolution;
        bool start,_Debug,savedfile;
       wxXmlNode* srcnode;
       wxXmlNode* headernode;
       wxXmlNode* cpp;wxXmlNode* header;
       vector<string> filessrc;
       vector<string> filesh;
       Edit *m_edit;
       wxTimer                                  m_timer;
       vector<string> soultionfilevec;
       wxArrayTreeItemIds itemsolutionid;
       wxString fname,modt;
        //wxBitmap page_bmp;
       wxAuiNotebook* ctrl ;
       wxAuiNotebook* ctrl_tree ;
       NewDialog* frame_1;
       NewFile*      frame_2;
       wxString workspace_path;
       wxString exe_path,projpath;
        //wxGenericDirCtrl* list_ctrl_1;
       wxTreeCtrl *tree;
       wxTextCtrl* text2;
       wxTextCtrl* text3;
       wxTextCtrl* text4;
       wxTreeCtrl* list_ctrl_1;
       wxGenericDirCtrl* list_ctrl_dir;
       wxImageList* imglist;
       wxHtmlWindow *m_Html;
       wxTreeItemId hid,srcid;
       wxHtmlEasyPrinting *m_Prn;
       wxString m_Name;
       wxTreeItemId m_lastItem,                // for OnEnsureVisible()
              m_draggedItem;             // item being dragged right now
        long m_notebook_style;
        long m_notebook_theme;
        static bool ms_logText;
        static bool ms_logFocus;
        void GetItemsRecursively(const wxTreeItemId& idParent,
              wxTreeItemIdValue cookie = 0);
       wxTreeItemId root;
       wxArrayTreeItemIds items;
        void AddTestItemsToTree(size_t numChildren, size_t depth);
        void OnSaveSolution(wxTreeItemId solution);
        void FileOpen (wxString fname);
		void OnNotebookPageClosed(wxAuiNotebookEvent &event);
        void OnFileNew (wxCommandEvent &event );
        void OnItemRClick(wxTreeEvent& event );
        void OnNewFile(wxCommandEvent &event );
        void OnFileProject (wxCommandEvent &event );
        void OnLoadProject (wxCommandEvent &event );
        void OnSaveProject (wxCommandEvent &event );
        void OnFileNewFrame (wxCommandEvent &event );
        void OnFileOpen (wxCommandEvent &event );
        void OnFileOpenFrame (wxCommandEvent &event );
        void OnFileSave (wxCommandEvent &event );
        void OnFileSaveAs (wxCommandEvent &event );
        void OnFileClose (wxCommandEvent &event );
        void OnExit (wxCommandEvent &event );
        void OnAbout(wxCommandEvent &event );
        void OnCompile (wxCommandEvent &event ) ;
        void OnBuild(wxCommandEvent &event ) ;
        void OnReBuild (wxCommandEvent &event );
        void OnClean (wxCommandEvent &event );
        void OnStart(wxCommandEvent &event ) ;
        void OnDebug(wxCommandEvent& WXUNUSED(event ));
        void OnClose (wxCloseEvent &event );
        void OnTimer(wxTimerEvent& event );
        //! properties
        void OnProperties (wxCommandEvent &event );
        void StartPage (wxCommandEvent &event );
		void OnPropertyPage(wxCommandEvent &event);
        void OnQuit(wxCommandEvent& event );
        void OnPrintSetup (wxCommandEvent &event );
        void OnPrintPreview (wxCommandEvent &event );
        void OnPrint (wxCommandEvent &event );
        void OnTreeMenu(wxTreeEvent &event );
        void OnCreateNotebook(wxString FileName);
        void OnRename(wxCommandEvent &event );
        void OnDelete(wxCommandEvent &event );
        void OnItemMenu(wxTreeEvent& event );
        void ShowMenu(wxTreeItemId id, const wxPoint& pt);
        void OnBeginDrag(wxTreeEvent& event );
        void OnBeginRDrag(wxTreeEvent& event );
        void OnEndDrag(wxTreeEvent& event );
        void OnBeginLabelEdit(wxTreeEvent& event );
        void OnEndLabelEdit(wxTreeEvent& event );
        void OnDeleteItem(wxTreeEvent& event );
        void OnContextMenu(wxContextMenuEvent& event );
        //void OnItemMenu(wxTreeEvent& event);
        void OnGetInfo(wxTreeEvent& event );
        void OnSetInfo(wxTreeEvent& event );
        void OnItemExpanded(wxTreeEvent& event );
        void OnItemExpanding(wxTreeEvent& event );
        void OnItemCollapsed(wxTreeEvent& event );
        void OnItemCollapsing(wxTreeEvent& event );
        void OnSelChanged(wxTreeEvent& event );
        void OnSelChanging(wxTreeEvent& event );
        void OnTreeKeyDown(wxTreeEvent& event );
        void LoadTreeNodeState(wxXmlNode * node);
        void SaveTreeNodeState(wxTreeItemId id, wxXmlNode * node);
        void OnItemActivated(wxTreeEvent& event );
        void OnItemStateClick(wxTreeEvent& event );
        void OnRMouseDown(wxMouseEvent& event );
        void OnRMouseUp(wxMouseEvent& event );
        void OnRMouseDClick(wxMouseEvent& event );
        void OnProcessTerm(wxProcessEvent& event );
        void ShowOutput(const wxString& cmd,
               const wxArrayString& output,
               const wxString& title);
        //! edit events
        void OnEdit (wxCommandEvent &event );
        typedef wxTreeItemId (wxTreeCtrl::*TreeFunc0_t)() const;
        void DoShowFirstOrLast(TreeFunc0_t pfn, const wxString& label);

        typedef wxTreeItemId (wxTreeCtrl::*TreeFunc1_t)( const wxTreeItemId&) const ;
        void DoShowRelativeItem(TreeFunc1_t pfn, const wxString& label);

       wxRect DeterminePrintSize ();
        void AddItemsRecursively(const wxTreeItemId& idParent,
              size_t nChildren,
              size_t depth,
              size_t folder);

        //MyFrame(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);
       MyFrame(wxFrame *parent,
               const wxString& cmd,
              wxProcess *process);
        //CustomDialog(const wxString& title);

       DECLARE_EVENT_TABLE();

       wxAuiManager m_mgr;
	    wxPropertyGrid* m_pg;
        //void DoGetFromStream(wxString text, wxInputStream& in);
		 void DoGetFromStream(wxTextCtrl *text, wxInputStream& in);
        void DisableInput();
        void DisableOutput();

	   wxProcess *process;
       wxProcess  *m_process;
       wxListCtrl *m_item_list;  
       wxOutputStream &m_out;
       wxInputStream  &m_in,
                              &m_err;

       wxTextCtrl *m_textOut,
                     *m_textIn,
                     *m_textErr;
       wxString _DebugStr;
       wxString cmdebug;

protected:
        //void OnTextEnter(wxCommandEvent& WXUNUSED(event)) { DoSend(wxString _DebugStr); }
        //void OnBtnSend(wxCommandEvent& WXUNUSED(event)) { DoSend(_DebugStr); DoGet();}
        //void OnBtnSend(wxCommandEvent& WXUNUSED(event)) ;
        //void OnBtnGet(wxCommandEvent& WXUNUSED(event)) { DoGet(); }
        void OnBtnClose(wxCommandEvent& WXUNUSED(event)) { DoClose(); }
        void OnStep(wxCommandEvent& WXUNUSED(event )) ;
        void OnStepInto(wxCommandEvent& WXUNUSED(event)) ;
		void OnGDBStop(wxCommandEvent& WXUNUSED(event));
        void OnStepOut(wxCommandEvent& WXUNUSED(event )) ;
        void OnStepOver(wxCommandEvent& WXUNUSED(event)) ;
        //void OnClose(wxCloseEvent& event);
        void DoSend(wxString);
		//void DoSend();
        //void DoSend()
        //{
        //    wxString s(m_textOut->GetValue());
        //    s += wxT('\n');
        //    m_out.Write(s.c_str(), s.length());
        //    m_textOut->Clear();

        //    DoGet();
        //}

        void DoGet();
        void DoClose();
};
  
