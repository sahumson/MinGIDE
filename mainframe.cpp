#include "mainframe.h"
#include <wx/treectrl.h>
#include <fstream>
#include "../resource/cpp.xpm"
#include "../resource/c.xpm"
#include "../resource/hxx.xpm"

enum
{
	ID_Open = 1,
	ID_Export,
	ID_Import,
	ID_Help,
	ID_About,
	ID_Quit,
	ID_MODE,
	ID_NEW,
	ID_Dir,
	ID_Compile,
	ID_Build,
	ID_ReBuild,
	ID_Clean,
	ID_START,
	ID_Delete,
	ID_DEBUG,
	ID_GDBSTOP,
	ID_STEP,
	ID_STEPINTO,
	ID_STEPOUT,
	ID_STEPOVER,
	ID_SYS,
	ID_PROGRID,
	ID_NewFile,
	Exec_Btn_Get,
	Exec_Btn_Close,
	TreeCtrlIcon_File,
	TreeCtrlIcon_Folder,
	TreeCtrlIcon_FolderOpened,
	TreeCtrlIcon_FolderSelected,
	TreeCtrlIcon_FileSelected,
	Tree_Ctrl_expand,
	Tree_Ctrl_editlable,
	Tree_Ctrl_delete,
	TreeDrag,
	ID_StartPage,
	Tree_Ctrl_Rdrag,
	Tree_Ctrl_enddrag,
	Tree_Ctrl_beginedit,
	Tree_Ctrl_expanding,
	wxID_FileProject,
	wxID_LoadProject,
	wxID_SaveProject,
	Tree_Ctrl_collapsed,
	Tree_Ctrl_collapsing,
	Tree_Ctrl_selchanged,
	Tree_Ctrl_selchanging,
	Tree_Ctrl_Treekeydown,
	Tree_Ctrl_ItemActivated,
	Tree_Ctrl_itemstate,
	Tree_Ctrl,
	ID_RENAME,
	wxID_DEBUG,
	TIMER_ID,
	ID_SAVEAS,
	ID_Tools,
	ID_CLOSE,
};


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Quit,                MyFrame::OnQuit)
	EVT_MENU (wxID_FileProject,      MyFrame::OnFileProject)
	EVT_MENU (wxID_LoadProject,      MyFrame::OnLoadProject)
	EVT_MENU (wxID_SaveProject,      MyFrame::OnSaveProject)
	EVT_MENU (ID_NewFile,            MyFrame::OnNewFile)
	EVT_MENU (wxID_OPEN,             MyFrame::OnFileOpen)
	EVT_MENU (myID_PROPERTIES,       MyFrame::OnProperties)
	EVT_MENU (wxID_SAVE,             MyFrame::OnFileSave)
	EVT_MENU (ID_SAVEAS,             MyFrame::OnFileSaveAs)
	EVT_MENU (ID_CLOSE,              MyFrame::OnFileClose)
	EVT_MENU (wxID_PRINT_SETUP,      MyFrame::OnPrintSetup)
	EVT_MENU (wxID_PREVIEW,          MyFrame::OnPrintPreview)
	EVT_MENU (wxID_PRINT,            MyFrame::OnPrint)
	EVT_MENU (wxID_EXIT,             MyFrame::OnExit)
	EVT_MENU (ID_Compile,            MyFrame::OnCompile)
	EVT_MENU (ID_Build,              MyFrame::OnBuild)
	EVT_MENU (ID_ReBuild,            MyFrame::OnReBuild)
	EVT_MENU (ID_Clean,              MyFrame::OnClean)
	EVT_MENU (ID_START,              MyFrame::OnStart)
	EVT_MENU (wxID_DEBUG,            MyFrame::OnDebug)
	EVT_MENU (ID_STEP,               MyFrame::OnStep)
	EVT_MENU (ID_GDBSTOP,			 MyFrame::OnGDBStop)
	EVT_MENU (ID_STEPINTO,           MyFrame::OnStepInto)
	EVT_MENU (ID_STEPOUT,            MyFrame::OnStepOut)
	EVT_MENU (ID_STEPOVER,           MyFrame::OnStepOver)
	EVT_MENU (ID_About,              MyFrame::OnAbout)
	EVT_MENU (wxID_CLEAR,            MyFrame::OnEdit)
	EVT_MENU (wxID_CUT,              MyFrame::OnEdit)
	EVT_MENU (wxID_COPY,             MyFrame::OnEdit)
	EVT_MENU (wxID_PASTE,            MyFrame::OnEdit)
	EVT_MENU (wxID_SELECTALL,        MyFrame::OnEdit)
	EVT_MENU (wxID_REDO,             MyFrame::OnEdit)
	EVT_MENU (wxID_UNDO,             MyFrame::OnEdit)
	EVT_MENU (wxID_FIND,             MyFrame::OnEdit)
	EVT_MENU (ID_RENAME,             MyFrame::OnRename)
	EVT_TOOL(ID_StartPage,           MyFrame::StartPage)
	EVT_TOOL (ID_PROGRID,            MyFrame::OnPropertyPage)
	EVT_MENU (ID_Delete,             MyFrame::OnDelete)
	EVT_BUTTON(Exec_Btn_Close,       MyFrame::OnBtnClose)
	EVT_TIMER(TIMER_ID,              MyFrame::OnTimer)
	EVT_TREE_ITEM_ACTIVATED(wxID_ANY, MyFrame::OnItemActivated)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, MyFrame::OnNotebookPageClosed)
	EVT_TREE_ITEM_MENU(wxID_ANY,     MyFrame::OnItemMenu)
	EVT_TREE_BEGIN_DRAG(wxID_ANY,    MyFrame::OnBeginDrag)
	EVT_TREE_END_DRAG(wxID_ANY,      MyFrame::OnEndDrag)
	EVT_CLOSE(MyFrame::OnClose)
	EVT_END_PROCESS(wxID_ANY,        MyFrame::OnProcessTerm)
	EVT_RIGHT_DCLICK(MyFrame::OnRMouseDClick)
	EVT_MENU_RANGE (myID_EDIT_FIRST, myID_EDIT_LAST,
	MyFrame::OnEdit)
	//EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, MyFrame::OnRightClickTab)
	//EVT_TREE_ITEM_RIGHT_CLICK(wxID_ANY, MyFrame::OnItemRClick)
	//EVT_TEXT_ENTER(wxID_ANY, MyPipeFrame::OnTextEnter)
	//EVT_TREE_BEGIN_RDRAG(wxID_ANY, MyFrame::OnBeginRDrag)
	//EVT_TREE_BEGIN_LABEL_EDIT(wxID_ANY, MyFrame::OnBeginLabelEdit)
	//EVT_TREE_END_LABEL_EDIT(wxID_ANY, MyFrame::OnEndLabelEdit)
	//EVT_TREE_DELETE_ITEM(wxID_ANY, MyFrame::OnDeleteItem)
	//EVT_TREE_GET_INFO(wxID_ANY, MyTreeCtrl::OnGetInfo)
	//EVT_TREE_SET_INFO(wxID_ANY, MyFrame::OnSetInfo)
	//EVT_TREE_ITEM_EXPANDED(wxID_ANY, MyFrame::OnItemExpanded)
	//EVT_TREE_ITEM_EXPANDING(wxID_ANY, MyFrame::OnItemExpanding)
	//EVT_TREE_ITEM_COLLAPSED(wxID_ANY, MyFrame::OnItemCollapsed)
	//EVT_TREE_ITEM_COLLAPSING(wxID_ANY, MyFrame::OnItemCollapsing)
	//EVT_TREE_SEL_CHANGED(wxID_ANY, MyFrame::OnSelChanged)
	//EVT_TREE_SEL_CHANGING(wxID_ANY, MyFrame::OnSelChanging)
	//EVT_TREE_KEY_DOWN(wxID_ANY, MyFrame::OnTreeKeyDown)
	//EVT_TREE_STATE_IMAGE_CLICK(wxID_ANY, MyFrame::OnItemStateClick)
	//EVT_TREE_ITEM_MENU(wxID_ANY, MyFrame::OnItemMenu)
	//B EVT_TREE_ITEM_RIGHT_CLICK(wxID_ANY, MyFrame::OnItemRClick)
	//EVT_RIGHT_DOWN(MyFrame::OnRMouseDown)
	//EVT_RIGHT_UP(MyFrame::OnRMouseUp)
	//EVT_BUTTON(Exec_Btn_Send,        MyFrame::OnBtnSend)
	//EVT_BUTTON(Exec_Btn_Get,         MyFrame::OnBtnGet)
	//EVT_TREE_ITEM_RIGHT_CLICK(wxID_ANY, OnItemRClick)
	//EVT_TREE_ITEM_MENU(ID_Dir,             MyFrame::OnBeginDrag)
	END_EVENT_TABLE();



//--------------------------------------------------------------------------------------------------------------------------
MyFrame::MyFrame(wxFrame *parent,
	const wxString& cmd,
	wxProcess *process)
	: wxFrame(parent, wxID_ANY, cmd),
	m_process(process),
	m_out(*process->GetOutputStream()),
	m_in(*process->GetInputStream()),
	m_err(*process->GetErrorStream()),m_timer( this,
	TIMER_ID)                     
{
	//-----------------------------------Title bar settings------------------------------------------------------------
	wxImage::AddHandler( new wxPNGHandler );
	wxTopLevelWindow::Maximize( true) ;
	wxIcon FrameIcon;
	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(wxT( "resource/mingw.ico"))));
	SetIcon((FrameIcon));

	//-----------------------------------All Pane Colors and Size settings Done here-----------------------------------
	m_mgr.SetManagedWindow( this);
	m_mgr.SetArtProvider( new wxAuiDefaultDockArt());
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_SASH_COLOUR, wxColour(wxColour(68,88,125)));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_BACKGROUND_COLOUR, wxColour(188,199,216));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_BORDER_COLOUR, wxColour(68,88,125));//wxColour(42,58,87)


	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR ,  wxColour(188,199,216));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR , wxColour(188,199,216));
	//m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR ,  wxColour(0,122,204));
	//m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR , wxColour(0,122,204));

	//m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR , wxColour(42,58,87));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR , wxColour(0,122,204));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR ,  wxColour(0,122,204));
	//m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR ,  wxColour(42,58,87));
	m_mgr.GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR , wxColour(255,255,255));

	//m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_CAPTION_FONT,22);
	m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 4);
	m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_CAPTION_SIZE, 21);
	//m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 4);


	//-----------------------------------Note book Declkared here-----------------------------------
	// initialize important variables
	m_edit = NULL;
	//
	// notify wxAUI which frame to use
	//m_mgr.SetManagedWindow(this);
	m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER|wxAUI_NB_CLOSE_BUTTON;
	m_notebook_theme = 0;
	//----------------------------------------------------------------------------------------------


	//-----------------------------------Menu bar starts here-----------------------------------
	wxMenu* Newp = new wxMenu;
	Newp->Append(wxID_FileProject, wxT( "Project..."));
	Newp->Append(wxID_ANY, wxT( "File ..."));
	Newp->Append(wxID_ANY, wxT( "Project from existing Code..." ));

	wxMenu* Openp = new wxMenu;
	Openp->Append(wxID_LoadProject, wxT( "Project..."));
	Openp->Append(wxID_ANY, wxT( "File ..."));
	Openp->Append(wxID_ANY, wxT( "Project from existing Code..." ));

	wxMenu* AddP = new wxMenu;
	AddP->Append(wxID_ANY, wxT( "New Project..."));
	AddP->Append(wxID_ANY, wxT( "New File ..."));
	AddP->Append(wxID_ANY, wxT( "Existing Project..."));

	//---File Menu--------------
	wxMenuBar* frame_1_menubar = new wxMenuBar();
	wxMenu* wxglade_tmp_menu_1 = new wxMenu();
	wxglade_tmp_menu_1->AppendSubMenu(Newp, wxT( "&New"));
	wxglade_tmp_menu_1->AppendSubMenu(Openp, wxT( "&Open"));
	wxglade_tmp_menu_1->AppendSeparator();
	wxglade_tmp_menu_1->AppendSubMenu(AddP, wxT( "&Add"));
	wxglade_tmp_menu_1->AppendSeparator();
	wxglade_tmp_menu_1->Append(wxID_OPEN, wxT( "&Open File\tCtrl+O"), wxEmptyString, wxITEM_NORMAL);
	wxglade_tmp_menu_1->Append (wxID_SaveProject, _( "&Save Project"));
	wxglade_tmp_menu_1->Append (wxID_SAVE, _( "&Save\tCtrl+S"));
	wxglade_tmp_menu_1->Append (ID_SAVEAS, _( "Save &as ..\tCtrl+Shift+S" ));
	wxglade_tmp_menu_1->Append (ID_CLOSE, _( "&Close\tCtrl+W"));
	wxglade_tmp_menu_1->AppendSeparator();
	wxglade_tmp_menu_1->Append (myID_PROPERTIES, _( "Proper&ties ..\tCtrl+I"));
	wxglade_tmp_menu_1->AppendSeparator();
	wxglade_tmp_menu_1->Append (wxID_PRINT_SETUP, _( "Print Set&up .."));
	wxglade_tmp_menu_1->Append (wxID_PREVIEW, _( "Print Pre&view\tCtrl+Shift+P"));
	wxglade_tmp_menu_1->Append (wxID_PRINT, _( "&Print ..\tCtrl+P"));
	wxglade_tmp_menu_1->AppendSeparator();

	frame_1_menubar->Append(wxglade_tmp_menu_1, wxT( "&File"));
	wxMenu* wxglade_tmp_menu_2 = new wxMenu();
	wxglade_tmp_menu_2->Append(ID_About, wxT( "&About"), wxEmptyString, wxITEM_NORMAL);

	//Feed import and bookmars --------------
	wxMenu *imp = new wxMenu;
	imp->Append(wxID_ANY, wxT( "Import newsfeed list..."));
	imp->Append(wxID_ANY, wxT( "Import bookmarks..."));
	imp->Append(wxID_ANY, wxT( "Import mail..."));

	wxglade_tmp_menu_1->AppendSubMenu(imp, wxT( "I&mport"));
	wxglade_tmp_menu_1->AppendSeparator();
	wxglade_tmp_menu_1->Append(ID_Quit, wxT( "&Exit"), wxEmptyString, wxITEM_NORMAL);
	wxglade_tmp_menu_1->AppendSeparator();

	//----Edit menu--------------------------------------------
	wxMenu *EditMenu = new wxMenu;
	EditMenu->Append (wxID_UNDO, _( "&Undo\tCtrl+Z"));
	EditMenu->Append (wxID_REDO, _( "&Redo\tCtrl+Shift+Z"));
	EditMenu->AppendSeparator();
	EditMenu->Append (wxID_CUT, _( "Cu&t\tCtrl+X"));
	EditMenu->Append (wxID_COPY, _( "&Copy\tCtrl+C"));
	EditMenu->Append (wxID_PASTE, _( "&Paste\tCtrl+V"));
	EditMenu->Append (wxID_CLEAR, _( "&Delete\tDel"));
	EditMenu->AppendSeparator();
	EditMenu->Append (wxID_FIND, _( "&Find\tCtrl+F"));
	EditMenu->Enable (wxID_FIND, false);
	EditMenu->Append (myID_FINDNEXT, _( "Find &next\tF3"));
	EditMenu->Enable (myID_FINDNEXT, false);
	EditMenu->Append (myID_REPLACE, _( "&Replace\tCtrl+H"));
	EditMenu->Enable (myID_REPLACE, false);
	EditMenu->Append (myID_REPLACENEXT, _( "Replace &again\tShift+F4"));
	EditMenu->Enable (myID_REPLACENEXT, false);
	EditMenu->AppendSeparator();
	EditMenu->Append (myID_BRACEMATCH, _( "&Match brace\tCtrl+M"));
	EditMenu->Append (myID_GOTO, _( "&Goto\tCtrl+G"));
	EditMenu->Enable (myID_GOTO, false);
	EditMenu->AppendSeparator();
	EditMenu->Append (myID_INDENTINC, _( "&Indent increase\tTab"));
	EditMenu->Append (myID_INDENTRED, _( "I&ndent reduce\tShift+Tab" ));
	EditMenu->AppendSeparator();
	EditMenu->Append (wxID_SELECTALL, _( "&Select all\tCtrl+A"));
	EditMenu->Append (myID_SELECTLINE, _( "Select &line\tCtrl+L"));

	// hilight submenu----------------------------------------
	wxMenu *menuHilight = new wxMenu;
	int Nr;
	for (Nr = 0; Nr < g_LanguagePrefsSize; Nr++) {
		menuHilight->Append (myID_HILIGHTFIRST + Nr,
			g_LanguagePrefs [Nr].name);
	}

	// charset submenu---------------------------------------
	wxMenu *menuCharset = new wxMenu;
	menuCharset->Append (myID_CHARSETANSI, _( "&ANSI (Windows)"));
	menuCharset->Append (myID_CHARSETMAC, _( "&MAC (Macintosh)"));

	// View menu---------------------------------------------
	wxMenu *ViewMenu = new wxMenu;
	ViewMenu->Append (myID_HILIGHTLANG, _( "&Hilight language .."), menuHilight);
	ViewMenu->AppendSeparator();
	ViewMenu->AppendCheckItem (myID_FOLDTOGGLE, _( "&Toggle current fold\tCtrl+T"));
	ViewMenu->AppendCheckItem (myID_OVERTYPE, _( "&Overwrite mode\tIns"));
	ViewMenu->AppendCheckItem (myID_WRAPMODEON, _( "&Wrap mode\tCtrl+U"));
	ViewMenu->AppendSeparator();
	ViewMenu->AppendCheckItem (myID_DISPLAYEOL, _( "Show line &endings"));
	ViewMenu->AppendCheckItem (myID_INDENTGUIDE, _( "Show &indent guides"));
	ViewMenu->AppendCheckItem (myID_LINENUMBER, _( "Show line &numbers"));
	ViewMenu->AppendCheckItem (myID_LONGLINEON, _( "Show &long line marker"));
	ViewMenu->AppendCheckItem (myID_WHITESPACE, _( "Show white&space"));
	ViewMenu->AppendSeparator();
	ViewMenu->Append (myID_USECHARSET, _( "Use &code page of .."), menuCharset);

	// Annotations menu--------------------------------------
	wxMenu* menuAnnotations = new wxMenu;
	menuAnnotations->Append(myID_ANNOTATION_ADD, _( "&Add or edit an annotation..."),
		_( "Add an annotation for the current line" ));
	menuAnnotations->Append(myID_ANNOTATION_REMOVE, _( "&Remove annotation"),
		_( "Remove the annotation for the current line" ));
	menuAnnotations->Append(myID_ANNOTATION_CLEAR, _( "&Clear all annotations"));

	wxMenu* menuAnnotationsStyle = new wxMenu;
	menuAnnotationsStyle->AppendRadioItem(myID_ANNOTATION_STYLE_HIDDEN, _("&Hidden"));
	menuAnnotationsStyle->AppendRadioItem(myID_ANNOTATION_STYLE_STANDARD, _("&Standard" ));
	menuAnnotationsStyle->AppendRadioItem(myID_ANNOTATION_STYLE_BOXED, _("&Boxed"));
	menuAnnotations->AppendSubMenu(menuAnnotationsStyle, "&Style");

	// change case submenu-----------------------------------
	wxMenu *menuChangeCase = new wxMenu;
	menuChangeCase->Append (myID_CHANGEUPPER, _( "&Upper case"));
	menuChangeCase->Append (myID_CHANGELOWER, _( "&Lower case"));

	// convert EOL submenu-------------------------------------
	wxMenu *menuConvertEOL = new wxMenu;
	menuConvertEOL->Append (myID_CONVERTCR, _( "CR (&Linux)"));
	menuConvertEOL->Append (myID_CONVERTCRLF, _( "CR+LF (&Windows)"));
	menuConvertEOL->Append (myID_CONVERTLF, _( "LF (&Macintosh)"));

	// Extra menu---------------------------------------------
	wxMenu *menuExtra = new wxMenu;
	menuExtra->AppendCheckItem (myID_READONLY, _( "&Readonly mode"));
	menuExtra->AppendSeparator();
	menuExtra->Append (myID_CHANGECASE, _( "Change &case to .."), menuChangeCase);
	menuExtra->AppendSeparator();
	menuExtra->Append (myID_CONVERTEOL, _( "Convert line &endings to .." ), menuConvertEOL);


	//---Add menu's here ------------------------------------
	wxMenu *WindowMenu = new wxMenu;
	wxMenu *ToolMenu = new wxMenu;
	WindowMenu->Append(wxID_DEBUG, _T( "&Start Debugging"));
	WindowMenu->AppendSeparator();
	WindowMenu->Append(ID_STEP, _T( "&Step"));
	WindowMenu->Append(ID_STEPINTO, _T( "&Step Into"));
	WindowMenu->Append(ID_STEPOUT, _T( "&Step Out"));
	WindowMenu->Append(ID_STEPOVER, _T( "&Step Over"));
	WindowMenu->AppendSeparator();
	WindowMenu->Append(wxID_ANY, _T( "&Toggle Breakpoint"));
	WindowMenu->Append(wxID_ANY, _T( "&New Breakpoint"));
	WindowMenu->Append(wxID_ANY, _T( "&Exceptions"));

	wxMenu *BuildMenu = new wxMenu;
	BuildMenu->Append(ID_Build, _T( "&Build Soulution"));
	BuildMenu->Append(ID_ReBuild, _T( "&Rebuild Solution"));
	BuildMenu->Append(ID_Clean, _T( "&Clean Solution"));
	BuildMenu->AppendSeparator();
	BuildMenu->Append(wxID_ANY, _T( "&Build Src"));
	BuildMenu->Append(wxID_ANY, _T( "&Rebuild Src"));
	BuildMenu->Append(wxID_ANY, _T( "&Clean Src"));
	BuildMenu->AppendSeparator();
	BuildMenu->Append(ID_Compile, _T( "&Compile"));
	//--------------------------------------------------------

	wxMenu *HelpMenu = new wxMenu;

	frame_1_menubar->Append(EditMenu, _T( "&Edit"));
	frame_1_menubar->Append(ViewMenu, _T( "&View"));
	//     frame_1_menubar->Append(ImageMenu, _T( "&Project"));
	frame_1_menubar->Append(ToolMenu, _T( "&Tools"));
	frame_1_menubar->Append (menuAnnotations, _( "&Annotations"));
	frame_1_menubar->Append (menuExtra, _( "E&xtra"));
	frame_1_menubar->Append(BuildMenu, _T( "&Build"));
	frame_1_menubar->Append(WindowMenu, _T( "&Debug"));
	frame_1_menubar->Append(wxglade_tmp_menu_2, wxT( "&About"));
	SetMenuBar(frame_1_menubar);
	frame_1_menubar->SetOwnBackgroundColour(wxColor(68,88,125));
	//-----------------------------------End of menu bar---------------------------------------------------------------

	//-----------------------------------All Pane Colors and Size settings Done here-----------------------------------
	wxStatusBar* statusbar = CreateStatusBar(2, 0);
	GetStatusBar()->SetStatusText(_( "Ready"));
	//-----------------------------------Status bar-----------------------------------

	SetMinSize(wxSize(400,300));
	// prepare a few custom overflow elements for the toolbars' overflow buttons

	//-----------------------------------Toolbar Starts here-----------------------------------
	//-------------------AUI tool bar added we can move the tool bar anywhere
	wxAuiToolBarItemArray prepend_items;
	wxAuiToolBarItemArray append_items;
	wxAuiToolBarItem item;
	item.SetKind(wxITEM_SEPARATOR);
	append_items.Add(item);
	item.SetKind(wxITEM_NORMAL);
	item.SetId(wxID_ANY);
	item.SetLabel(_( "Customize..."));
	append_items.Add(item);

	//Edit tool starts here
	wxBitmap Create_project(wxT( "resource/gtk-select-all.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Add_existing(wxT( "resource/gtk-add.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Emptyproj(wxT( "resource/gtk-file.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Open(wxT( "resource/gtk-open.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Save(wxT( "resource/gtk-floppy.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Saveall(wxT( "resource/gtk-save-as.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Cut(wxT( "resource/gtk-cut.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Copy(wxT( "resource/gtk-copy.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Undo(wxT( "resource/gtk-undo-ltr.png"), wxBITMAP_TYPE_PNG);
	wxBitmap Redo(wxT( "resource/gtk-redo-ltr.png"), wxBITMAP_TYPE_PNG);
	wxBitmap build(wxT( "resource/gtk-execute.png"), wxBITMAP_TYPE_PNG);

	wxBitmap pause_gtk(wxT( "resource/pause-gtk.png"), wxBITMAP_TYPE_PNG);
	wxBitmap start(wxT( "resource/start.png"), wxBITMAP_TYPE_PNG);
	wxBitmap gtk_stop(wxT( "resource/stop-gtk.png"), wxBITMAP_TYPE_PNG);
	wxBitmap step_into(wxT( "resource/step_into.png"), wxBITMAP_TYPE_PNG);
	wxBitmap step_out(wxT( "resource/step_out.png"), wxBITMAP_TYPE_PNG);
	wxBitmap step_over(wxT( "resource/step_over.png"), wxBITMAP_TYPE_PNG);
	wxBitmap breakpoint(wxT( "resource/breakpoint.png"), wxBITMAP_TYPE_PNG);

	wxBitmap gtk_start(wxT( "resource/gtk-start.png"), wxBITMAP_TYPE_PNG);
	wxBitmap start_page(wxT( "resource/start_page.png"), wxBITMAP_TYPE_PNG);
	wxBitmap propertywindow(wxT( "resource/propertywindow.png"), wxBITMAP_TYPE_PNG);
	wxBitmap solutionexe(wxT( "resource/solutionexe.png"), wxBITMAP_TYPE_PNG);
	wxBitmap commandwin(wxT( "resource/commandwin.png"), wxBITMAP_TYPE_PNG);
	wxBitmap toolbox(wxT( "resource/toolbox.png"), wxBITMAP_TYPE_PNG);
	wxBitmap resourcewin(wxT( "resource/resourcewin.png"), wxBITMAP_TYPE_PNG);
	wxBitmap objectbrowser(wxT( "resource/objectbrowser.png"), wxBITMAP_TYPE_PNG); 
	//-------------------------------------


	//Solution Propeties toolbar here-------------------------------------------------------------
	tb2 = new wxAuiToolBar(this , wxID_ANY, wxDefaultPosition, wxSize(10,10),
		wxAUI_TB_DEFAULT_STYLE);
	tb2->SetToolBitmapSize(wxSize(10,10));
	SetBackgroundColour(wxColour(42,58,87));
	tb2->SetToolBitmapSize(wxSize(10, 10));
	tb2->AddTool(wxID_FileProject, wxT( "&Create project\tCtrl+N"), Emptyproj,wxT("Create project" ));//&Save\tCtrl+S
	tb2->AddTool(wxID_LoadProject, wxT( "Add Exisiting Project"), Create_project,wxT( "Add Exisiting Project" ));
	tb2->AddTool(wxID_ANY, wxT( "Add Existing"),Add_existing,wxT( "Add Existing") );
	tb2->AddTool(wxID_OPEN, wxT( "Open"),Open,wxT( "Open" ) );
	tb2->AddSeparator();
	tb2->AddTool(wxID_SAVE, wxT( "Save"), Save,wxT( "Save" ));
	tb2->AddTool(wxID_ANY, wxT( "Save All"), Saveall,wxT( "Save All" ));
	tb2->AddSeparator();
	tb2->AddTool(wxID_CUT, wxT( "Cut"), Cut,wxT( "Cut" ));
	tb2->AddTool(wxID_COPY, wxT( "Copy"), Copy,wxT( "Copy" ));
	tb2->AddTool(wxID_UNDO, wxT( "Undo"), Undo,wxT( "Undo" ));
	tb2->AddTool(wxID_REDO, wxT( "Redo"), Redo,wxT( "Redo" ));
	tb2->SetCustomOverflowItems(prepend_items, append_items);
	tb2->EnableTool(wxID_ANY, false);

	// Separator Start and compilation tools--------------------------------
	//tb4->SetToolBitmapSize(wxSize(16,16));
	tb2->AddSeparator();
	tb2->AddTool(ID_START, wxT( "Start"), gtk_start,wxT("Start" ));
	wxComboBox* choice_derelease = new wxComboBox(tb2, ID_DEBUG, wxT("Debug" ),
		wxDefaultPosition, wxDefaultSize,0, NULL,0);
	//wxChoice* choice_derelease = new wxChoice(tb4, ID_DEBUG);
	choice_derelease->AppendString(wxT( "Debug"));
	choice_derelease->AppendString(wxT( "Release"));
	tb2->AddControl(choice_derelease);
	wxComboBox* choice_config = new wxComboBox(tb2, ID_SYS, wxT("mingw32" ),
		wxDefaultPosition, wxDefaultSize,0, NULL,0);
	//wxChoice* choice_config = new wxChoice(tb4, ID_SYS);
	choice_config->AppendString(wxT( "mingw32"));
	choice_config->AppendString(wxT( "Configuration Manager"));
	tb2->AddControl(choice_config);
	tb2->AddTool(wxID_ANY, wxT( "Solution explorer"), solutionexe,wxT("Solution explorer"));
	tb2->AddTool(ID_PROGRID, wxT( "Property window"), propertywindow, wxT("Property window" ));
	tb2->AddTool(wxID_ANY, wxT( "Tool box"), toolbox, wxT("Tool box" ));
	tb2->AddSeparator();
	tb2->AddTool(ID_StartPage, wxT( "Start Page"), start_page,wxT("Start Page"));
	tb2->AddTool(wxID_ANY, wxT( "Command window"), commandwin,wxT("Command window"));
	tb2->AddTool(wxID_ANY, wxT( "Resource view"), resourcewin,wxT("Resource view"));
	tb2->AddTool(wxID_ANY, wxT( "Object Browser"), objectbrowser,wxT("Object Browser"));
	tb2->SetBackgroundColour(wxColor(198,28,88));
	tb2->Realize();

	// Tool bar 3 Debugging toolbar--------------------------------------
	tb3 = new wxAuiToolBar(this , wxID_ANY, wxDefaultPosition, wxSize(10,10),
		wxAUI_TB_DEFAULT_STYLE);
	tb3->SetToolBitmapSize(wxSize(10,10));
	SetBackgroundColour(wxColour(42,58,87));
	tb3->AddTool(wxID_DEBUG, wxT( "Pause debugging"), pause_gtk, wxT("Pause debugging"));
	tb3->AddTool(wxID_DEBUG, wxT( "Start debugging"), start, wxT("Start debugging"));
	tb3->AddTool(ID_GDBSTOP, wxT( "Stop debugging"), gtk_stop,wxT("Stop debugging"));
	tb3->AddTool(wxID_ANY, wxT( "Breakpoint"), breakpoint, wxT("Breakpoints" ));
	tb3->AddSeparator();
	tb3->AddTool(ID_STEP, wxT( "Step"), step_into, wxT("Step" ));
	tb3->AddTool(ID_STEPINTO, wxT( "Step Into"), step_into, wxT("Step Into" ));
	tb3->AddTool(ID_STEPOUT, wxT( "Step Out"), step_out, wxT("Step Out" ));
	tb3->AddTool(ID_STEPOVER, wxT( "Step over"), step_over, wxT("Step over" ));
	tb3->AddSeparator();
	tb3->SetCustomOverflowItems(prepend_items, append_items);
	tb3->Realize();
	m_mgr.AddPane(tb2, wxAuiPaneInfo().
		Name(wxT( "tb2")).Caption(wxT("Run Toolbar" )).
		ToolbarPane().Top().Row(1));

	m_mgr.AddPane(tb3, wxAuiPaneInfo().
		Name(wxT( "tb3")).Caption(wxT("Debugging toolbar" )).
		ToolbarPane().Top().Row(1).Position(2));

	//----------------------------------------Tool bar Ends here---------------------------------------------------------------

	////////////////////////////////////////////////////////////////////////////////////////////
	// Here Starts the Panels
	///////////////////////////////////////////////////////////////////////////////////////////
	//                                                     Note book pane with editor
	//-------------------------------------------------------------------------------------------
	ctrl = new wxAuiNotebook(this , wxID_ANY,
		wxPoint(-1,-1),
		wxSize(430,200),
		wxAUI_NB_WINDOWLIST_BUTTON|wxAUI_NB_CLOSE_BUTTON|wxAUI_NB_TAB_SPLIT|wxAUI_NB_CLOSE_ON_ALL_TABS);
	ctrl->SetBackgroundColour(wxColour(68,88,125));
	//--------------------------------------------------------------------------------------------------------------------

	//-------------------------------------Start Page----------------------------------------------------------------------
	m_Html = new wxHtmlWindow(this );
	//m_Html -> SetRelatedFrame(this, _("HTML : %s"));
	m_Name = wxT( "resource/test.htm");
	m_Html -> LoadPage(m_Name);

	m_Prn = new wxHtmlEasyPrinting(_("Easy Printing Demo" ), this);
	m_Prn -> SetHeader(m_Name + wxT( "(@PAGENUM@/@PAGESCNT@)<hr>" ), wxPAGE_ALL);

	ctrl->AddPage(m_Html, wxT( "Start Page") , false , wxNullBitmap);
	ctrl->SetPageToolTip(0, "Start Page)");
	ctrl->GetArtProvider()->SetColour(wxColour(68,88,125));
	ctrl->GetArtProvider()->SetActiveColour(wxColour(68,88,125));
	//---------------------------------------------------------------------------------------------------------------------

	//---Solution expolorer tree menu starts here ---------------------------------
	wxPanel* Solutionexplorer = new wxPanel(this , wxID_ANY, wxPoint(0,0),wxSize(200,385));

	ctrl_tree = new wxAuiNotebook(Solutionexplorer , wxID_ANY,wxPoint(-1,-1),wxSize(200,385),
		wxAUI_NB_WINDOWLIST_BUTTON|wxAUI_NB_BOTTOM|wxAUI_NB_TAB_FIXED_WIDTH);

	list_ctrl_1 = new wxTreeCtrl(this , Tree_Ctrl, wxPoint(0,0), wxSize(200,385),wxTR_HAS_BUTTONS|wxTR_TWIST_BUTTONS|wxTR_LINES_AT_ROOT|wxTR_NO_LINES);//wxTR_HIDE_ROOT|
	root = list_ctrl_1->AddRoot( "Workspace", -1, -1, NULL);
	unsigned int indent = list_ctrl_1->GetIndent();
	if (indent < 100)
		list_ctrl_1->SetIndent( indent+10 );
	//SetItemFont(root, *wxITALIC_FONT);
	//wxTR_HIDE_ROOT
	ctrl_tree->AddPage(list_ctrl_1, wxT( "Solution explorer") , false , wxNullBitmap);
	ctrl_tree->SetPageToolTip(0, "Solution explorer)");

	list_ctrl_dir = new wxGenericDirCtrl( this , wxID_ANY, wxGetCwd(), wxDefaultPosition, wxSize(200, 385), wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER );
	tree = list_ctrl_dir->GetTreeCtrl();
	//list_ctrl_1->GetTreeCtrl()->Connect(wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler(MyFrame::OnBeginDrag), NULL, this);
	this->Connect(tree->GetId(),
		wxEVT_COMMAND_TREE_SEL_CHANGED,
		wxTreeEventHandler(MyFrame::OnTreeMenu));
	ctrl_tree->AddPage(list_ctrl_dir, wxT( "Dir explorer") , false , wxNullBitmap);
	ctrl_tree->SetPageToolTip(1, "Dir explorer)");

	wxSizer *sizerTopS = new wxBoxSizer(wxVERTICAL);
	sizerTopS->Add(ctrl_tree, 1, wxGROW | wxALL, 5);
	Solutionexplorer->SetSizer(sizerTopS);
	// Tree Ends here -------------------------------------------------------------


	//---------------------------------------Streaming command line inputs & ouputs------------------------------------------
	wxPanel* compileoutput = new wxPanel(this , wxID_ANY, wxPoint(0,0),wxSize(300,150));
	text2 = new wxTextCtrl(compileoutput, wxID_ANY, wxEmptyString,
		wxDefaultPosition, wxDefaultSize,
		wxTE_MULTILINE | wxTE_RICH);
	text2->SetEditable( false);

	wxSizer *sizerTopO = new wxBoxSizer(wxVERTICAL);
	sizerTopO->Add(text2, 1, wxGROW | wxALL, 5);
	compileoutput->SetSizer(sizerTopO);
	//------------------------------------------------------------------------
	//Set handles for debugger
	m_process->SetNextHandler( this);
	_Debug=false;
	wxPanel *debugctrl = new wxPanel(this , wxID_ANY);
	m_textIn = new wxTextCtrl(debugctrl, wxID_ANY, wxEmptyString,
		wxDefaultPosition, wxDefaultSize,
		wxTE_MULTILINE | wxTE_RICH);
	m_textIn->SetEditable( false);

	wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
	sizerTop->Add(m_textIn, 1, wxGROW | wxALL, 5);
	debugctrl->SetSizer(sizerTop);
	//---------------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//Set Handles for Breakpoint controls
	imglist = new wxImageList(16, 16, true , 4);
	wxBitmap cpp(wxT( "resource/cpp.png"), wxBITMAP_TYPE_PNG);
	wxBitmap hxx(wxT( "resource/hxx.png"), wxBITMAP_TYPE_PNG);
	imglist->Add(Create_project,wxSize(16,16));
	imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, wxSize(16,16)));
	imglist->Add(cpp, wxSize(16,16));
	imglist->Add(breakpoint,wxSize(16,16));
	list_ctrl_1->AssignImageList(imglist);

	wxPanel* breakpointctrl = new wxPanel(this , wxID_ANY);
	/*   text4 = new wxTextCtrl(breakpointctrl, wxID_ANY, wxEmptyString,
	wxDefaultPosition, wxDefaultSize,
	wxTE_MULTILINE | wxTE_RICH);
	text4->SetEditable( false);*/
	m_item_list = new wxListCtrl(breakpointctrl, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	m_item_list->SetImageList(imglist, wxIMAGE_LIST_SMALL);
	//m_item_list->AssignImageList(imglist,wxIMAGE_LIST_SMALL);
	// Add first column      
	wxListItem col0;
	col0.SetId(0);
	col0.SetText( _( "File Name") );
	col0.SetWidth(50);
	m_item_list->InsertColumn(0, col0);

	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText( _( "Line Number") );
	m_item_list->InsertColumn(1, col1);

	// Add thirs column    
	wxListItem col2;
	col2.SetId(2);
	col2.SetText( _( "Function") );
	m_item_list->InsertColumn(2, col2);

	// Add thirs column    
	wxListItem col3;
	col3.SetId(3);
	col3.SetText( _( "Address") );
	m_item_list->InsertColumn(3, col3);
	m_item_list->SetSingleStyle(wxLC_HRULES | wxLC_VRULES, true);

	// m_item_list->SetColumnWidth( 0, wxLIST_AUTOSIZE );
	//m_item_list->SetColumnWidth( 1, wxLIST_AUTOSIZE );
	//m_item_list->SetColumnWidth( 2, wxLIST_AUTOSIZE );

	wxSizer *sizerTopB = new wxBoxSizer(wxVERTICAL);
	sizerTopB->Add(m_item_list, 1, wxGROW | wxALL, 5);
	breakpointctrl->SetSizer(sizerTopB);
	//--------------------------------------------------------------------------------------
	//Property Grid Creation Done here
	wxPropertyGrid *pg = new wxPropertyGrid(this,-1,wxDefaultPosition,wxSize(200,385),
		wxPG_SPLITTER_AUTO_CENTER |
		wxPG_BOLD_MODIFIED );
	m_pg = pg;

	pg->Append( new wxStringProperty("String Property", wxPG_LABEL) );
	pg->Append( new wxIntProperty("Int Property", wxPG_LABEL) );
	pg->Append( new wxBoolProperty("Bool Property", wxPG_LABEL) );
	//--------------------------------------------------------------------------------------

	// add the panes to the manager
	m_mgr.AddPane(Solutionexplorer, wxAuiPaneInfo().Name(wxT( "SE" )).Caption(wxT("Solution Explorer" )).Left().LeftDockable(true ).Position(0).MaximizeButton( true).CloseButton( true ));
	m_mgr.AddPane(pg, wxAuiPaneInfo().Name(wxT( "PG" )).Caption(wxT("Property Grid" )).Right().RightDockable(true ).Position(0).MaximizeButton( true).CloseButton( true ));
	m_mgr.AddPane(compileoutput, wxAuiPaneInfo().Name(wxT( "OP" )).Caption(wxT("Output" )).Bottom().Position(1).MaximizeButton( true).CloseButton(true ));
	m_mgr.AddPane(breakpointctrl, wxAuiPaneInfo().Name(wxT( "Breakpoint" )).Caption(wxT("Breakpoint" )).Bottom().Position(1).MaximizeButton( true).CloseButton(true ));
	m_mgr.AddPane(debugctrl, wxAuiPaneInfo().Name(wxT( "Debug" )).Caption(wxT("Debug" )).Bottom().Position(2).MaximizeButton( true).CloseButton(true ));
	m_mgr.AddPane(ctrl, wxAuiPaneInfo().Name(wxT( "Code")).CenterPane().PaneBorder( true).MaximizeButton( true).CloseButton(true ));
	m_mgr.GetPane(wxT( "PG")).Hide();
	m_mgr.GetPane(wxT( "Debug")).Hide();
	m_mgr.GetPane(wxT( "Breakpoint")).Hide();
	m_mgr.GetPane(wxT( "tb3")).Hide();
	//--------------------------------------------------------------------------------------
	//Status bar color's
	//GetStatusBar()->SetBackgroundColour(wxColour(68,88,125));
	//GetStatusBar()->SetForegroundColour(wxColour(255,255,255));
	//GetStatusBar()->m_foregroundColour(wxColour(42,58,87));
	GetStatusBar()->SetBackgroundColour(wxColour(188,199,216));
	//--------------------------------------------------------------------------------------
	exe_path =(wxGetCwd().c_str()+ "\\Workspace");
	if(!wxDirExists(exe_path))
	{
		wxMkDir(exe_path);
		wxTextEntryDialog dialog( this,
			wxT( "Please set the workspace directory" ),
			wxT( "Workspace directory"),
			exe_path,
			wxOK | wxCANCEL);

		if (dialog.ShowModal() == wxID_OK)
		{
			wxMessageBox(dialog.GetValue(), wxT( "Path updated"), wxOK | wxICON_INFORMATION, this);
		}
		workspace_path = dialog.GetValue();}
	workspace_path = exe_path;
	tb2->EnableTool(ID_START,false);
	tb2->EnableTool(wxID_REDO, false);
	m_mgr.Update();
}
//------------------------------------------------------------Constructor ENDS here---------------------------------------------------


//-----------------------------------------Debugging Events Starts Here--------------------------------------------------------------
void MyFrame::OnDebug(wxCommandEvent& WXUNUSED(event))
{
	wxString currentDir = wxGetCwd();     
	m_mgr.GetPane(wxT( "Debug")).Show();
	//m_mgr.GetPane(wxT( "OP")).Hide();
	m_mgr.GetPane(wxT( "Breakpoint")).Show();
	m_mgr.GetPane(wxT( "tb3")).Show();
	m_mgr.Update();
	_Debug=true;

	//Load the symbols---------------------------------
	wxSetWorkingDirectory(projpath);
	list_ctrl_dir->SetPath(projpath);
	wxString cmdl=wxString::Format( "file %s.exe", list_ctrl_1->GetItemText(root));
	DoSend(cmdl);

}

void MyFrame::OnStepOver(wxCommandEvent& WXUNUSED(event))
{
	wxString _DebugStr = wxT("n");
	DoSend(_DebugStr);
	DoGet();
}

void MyFrame::OnGDBStop(wxCommandEvent& WXUNUSED(event))
{
	wxString _DebugStr = wxT("q");
	DoSend(_DebugStr);
	DoGet();
	m_mgr.GetPane(wxT( "Breakpoint")).Hide();
	m_mgr.GetPane(wxT( "tb3")).Hide();
	m_mgr.Update();
}

void MyFrame::OnStep(wxCommandEvent& WXUNUSED(event))
{
	//wxSetWorkingDirectory(projpath);
	wxString _DebugStr = wxT("n");
	DoSend(_DebugStr);
	DoGet();
}
void MyFrame::OnStepInto(wxCommandEvent& WXUNUSED(event))
{
	wxString _DebugStr = wxT("s");
	DoSend(_DebugStr);
	DoGet();
}

void MyFrame::OnStepOut(wxCommandEvent& WXUNUSED(event))
{

}

void MyFrame::DoGet()
{
	//wxSetWorkingDirectory(projpath);
	// we don't have any way to be notified when any input appears on the
	// stream so we have to poll it :-(
	//	//_DebugStr = cmdebug;
	DoGetFromStream(m_textIn, m_in);
	DoGetFromStream(m_textErr, m_err);
}

void MyFrame::DoGetFromStream(wxTextCtrl *text, wxInputStream& in)
{
	//wxSetWorkingDirectory(projpath);
	while ( in.CanRead() )
	{
		char buffer[4096];
		buffer[in.Read(buffer, WXSIZEOF(buffer) - 1).LastRead()] = '\0';

		m_textIn->AppendText(buffer);
	}
}

void MyFrame::DoSend(wxString _DebugStr)
{
	//wxSetWorkingDirectory(projpath);
	wxString s(_DebugStr);
	s += wxT('\n');
	m_out.Write(s, s.length());
	//m_textOut->Clear();
	DoGet();
}

void MyFrame::DoClose()
{
	m_process->CloseOutput();
	DisableInput();
}

void MyFrame::DisableInput()
{

}

void MyFrame::OnProcessTerm(wxProcessEvent& WXUNUSED(event))
{
	DoGet();
	wxDELETE(m_process);
	wxLogWarning(wxT( "The other process has terminated, closing" ));
	DisableInput();
	//DisableOutput();
}
//-----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------Solution Tree Starts Here----------------------------------------------------
// Solution Tree Events

void MyFrame::OnBeginDrag(wxTreeEvent& event )
{
	// need to explicitly allow drag
	if ( event .GetItem() != list_ctrl_1->GetRootItem() )
	{
		m_draggedItem = event.GetItem();

		wxPoint clientpt = event.GetPoint();
		wxPoint screenpt = ClientToScreen(clientpt);

		//wxLogMessage(wxT("OnBeginDrag: started dragging %s at screen coords (%i,%i)"),
		//list_ctrl_1->GetItemText(m_draggedItem).c_str(),
		//screenpt.x, screenpt.y);

		event.Allow();
	}
	else
	{
		//wxLogMessage(wxT("OnBeginDrag: this item can't be dragged."));
	}
}

void MyFrame::OnEndDrag(wxTreeEvent& event )
{
	wxTreeItemId itemSrc = m_draggedItem,
		itemDst = event.GetItem();
	m_draggedItem = (wxTreeItemId)0l;

	// where to copy the item?
	if ( itemDst.IsOk() && !list_ctrl_1->ItemHasChildren(itemDst) )
	{
		// copy to the parent then
		itemDst = list_ctrl_1->GetItemParent(itemDst);
	}

	if ( !itemDst.IsOk() )
	{
		//wxLogMessage(wxT("OnEndDrag: can't drop here."));

		return;
	}
	wxString text = list_ctrl_1->GetItemText(itemSrc);
	wxTreeItemId id = list_ctrl_1->AppendItem(itemDst, text, 2);

}

void MyFrame::OnRename(wxCommandEvent& WXUNUSED(event))
{
	wxTreeItemId item = list_ctrl_1->GetFocusedItem();
	list_ctrl_1->SetFocusedItem(item);

	// TODO demonstrate creating a custom edit control...
	( void)list_ctrl_1->EditLabel(item);
}

void MyFrame::OnItemMenu(wxTreeEvent& event )
{
	//list_ctrl_1->ClearFocusedItem ();
	wxTreeItemId item = list_ctrl_1->GetFocusedItem();
	list_ctrl_1->SetFocusedItem(item);
	list_ctrl_1->Refresh();

	wxTreeItemId itemId = event.GetItem();
	wxCHECK_RET( itemId.IsOk(), "should have a valid item" );

	wxPoint clientpt = event.GetPoint();
	wxPoint screenpt = ClientToScreen(clientpt);

	ShowMenu(itemId, clientpt);
	event.Skip();
}

void MyFrame::OnItemActivated(wxTreeEvent& event)
{
	// show some info about this item
	wxTreeItemId itemId = event.GetItem();

	//if ( !list_ctrl_1->GetItemData(itemId) == list_ctrl_1->GetRootItem() )
	if(!(itemId == list_ctrl_1->GetRootItem())& !(list_ctrl_1->ItemHasChildren(itemId)))
	{
		wxString fileOpen= list_ctrl_1->GetItemText(itemId) ;
		ofstream myfile;
		//wxString fname= frame_2->TextCtrl2->GetLineText(0);
		myfile.open (fileOpen.mb_str(),ios_base::out | ios_base::in);
		//if(myfile.is_open()){
		//wxMessageBox("File already opened");}
		//else
		{
			wxTreeItemId item = list_ctrl_1->GetFocusedItem();
			list_ctrl_1->SetFocusedItem(item);
			//list_ctrl_1->AppendItem(item,frame_2->TextCtrl2->GetLineText(0), 2);
			list_ctrl_1->ExpandAll();

			myfile.clear();
			myfile.open(fileOpen.mb_str(), ios_base::out);  // will create if necessary
			myfile.close();
			wxFileName w(fileOpen); w.Normalize(); fileOpen = w.GetFullPath();

			FileOpen (fileOpen);
			//wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
			OnCreateNotebook(fileOpen);
			if (!m_edit) return ;
			m_edit->LoadFile (fileOpen);
			list_ctrl_1->Expand(root);
			list_ctrl_1->ExpandAll();
			/*m_edit->LoadFile (fname);
			ctrl->SetPageText(0, w.GetFullName());*/
		}

		// wxLogMessage(wxT("OnItemActivated"));
	}
}

void MyFrame::OnRMouseDClick(wxMouseEvent& event)
{
	wxTreeItemId item = list_ctrl_1->GetFocusedItem();
	list_ctrl_1->SetFocusedItem(item);
	list_ctrl_1->Refresh();
	wxLogMessage(wxT( "No item under mouse"));
}

void MyFrame::ShowMenu(wxTreeItemId id, const wxPoint& pt)
{
	wxString title;
	if (id == list_ctrl_1->GetRootItem())
	{
#if wxUSE_MENUS
		if(list_ctrl_1->ItemHasChildren(list_ctrl_1->GetRootItem()))
		{
			//wxMenu* AddP = new wxMenu();
			//AddP->Append(wxID_FileProject, wxT( "New Project..."));
			///wxMenuItem *item = new wxMenuItem(AddP, wxID_ANY,
			///    wxT("Clear &log\tCtrl-L"));
			//wxBitmap prop(wxT("gtk-edit.png"), wxBITMAP_TYPE_PNG);
			//item->SetBitmap(prop);
			//AddP->Append(item);

			//wx.SetBitmap(Create_project);
			//AddP->Append(ID_NewFile, wxT( "New File ..."));
			//AddP->Append(wxID_ANY, wxT( "Existing Project..."));

			wxMenu menu;
			menu.Append(ID_Build, wxT( "&Build"));
			menu.AppendSeparator();
			menu.Append(ID_ReBuild, wxT( "&Rebuild"));
			menu.Append(ID_Clean, wxT( "&Clean"));
			menu.Append(ID_Delete, wxT( "&Delete"));
			menu.Append(ID_RENAME, wxT( "&Rename"));
			menu.AppendSeparator();
			menu.Append(wxID_ANY, wxT( "&Remove"));
			menu.AppendSeparator();
			menu.Append(wxID_ANY, wxT( "&Rescan Solution"));
			menu.AppendSeparator();
			menu.Append(wxID_ANY, wxT( "&Properties"));

			//wxMenu* wxglade_tmp_menu_1 = new wxMenu();
			//wxglade_tmp_menu_1->AppendSubMenu(Newp, wxT( "&New"));

			PopupMenu(&menu, pt);
#endif // wxUSE_MENUS
		}
	}
	else
	{
#if wxUSE_MENUS

		wxMenu* AddP = new wxMenu();
		wxMenuItem *item = new wxMenuItem(AddP, ID_NewFile,"New File ...");
		//wx.SetBitmap(Create_project);
		//AddP->Append(ID_NewFile, wxT("New File ..."));

		wxBitmap prop(wxT("gtk-edit.png"), wxBITMAP_TYPE_PNG);
		item->SetBitmap(prop);
		AddP->Append(item);
		AddP->Append(wxID_ANY, wxT("Existing File..."));
		AddP->Append(wxID_ANY, wxT("Add Class..."));

		wxMenu menu;
		menu.AppendSubMenu(AddP, wxT( "&Add"));
		menu.AppendSeparator();
		menu.Append(wxID_ANY, wxT( "&Cut"));
		menu.Append(wxID_ANY, wxT( "&Copy"));
		menu.Append(wxID_ANY, wxT( "&Paste"));
		menu.Append(ID_Delete, wxT( "&Delete"));
		menu.Append(ID_RENAME, wxT( "&Rename"));
		menu.AppendSeparator();
		menu.Append(wxID_ANY, wxT( "&Properties"));

		//wxMenu* wxglade_tmp_menu_1 = new wxMenu();
		//wxglade_tmp_menu_1->AppendSubMenu(Newp, wxT( "&New"));

		PopupMenu(&menu, pt);
#endif // wxUSE_MENUS
	}

}

void MyFrame::OnTreeMenu(wxTreeEvent &WXUNUSED(event)){

	/*     wxString fnameD=list_ctrl_1->GetFilePath();
	wxFileName w(fnameD);w.Normalize(); fnameD = w.GetFullPath();
	m_edit->LoadFile (fnameD);
	m_edit->SelectNone();
	ctrl->SetPageText(0, w.GetFullName());*/
}
//-------------------------------------------------Solution Tree Ends Here----------------------------------------------------


//-------------------------------------------------Code Editor Starts here-----------------------------------------------------
//-------Welcome Codeeditor Page---------------------------
void MyFrame::StartPage(wxCommandEvent& WXUNUSED(event))
{
	m_Html = new wxHtmlWindow(this );
	m_Name = wxT( "resource/test.htm");
	m_Html -> LoadPage(m_Name);

	m_Prn = new wxHtmlEasyPrinting(_("Easy Printing Demo" ), this);
	m_Prn -> SetHeader(m_Name + wxT( "(@PAGENUM@/@PAGESCNT@)<hr>" ), wxPAGE_ALL);

	ctrl->AddPage(m_Html, wxT( "Start Page") , false , wxNullBitmap);
	ctrl->SetPageToolTip(0, "Start Page)");
}

void MyFrame::OnPropertyPage(wxCommandEvent& WXUNUSED(event))
{
	m_mgr.GetPane(wxT( "PG")).Show();
	m_mgr.Update();
}

void MyFrame::OnDelete (wxCommandEvent &event ) {

	wxTreeItemId item = list_ctrl_1->GetFocusedItem();
	list_ctrl_1->SetFocusedItem(item);
	wxString fileRemove= list_ctrl_1->GetItemText(item) ;
	wxString fname= frame_2->TextCtrl2->GetLineText(0);

	if(wxFileExists(fname)){
		wxMessageBox( "Warning! Are you sure want to delete the file?" );
		wxRemoveFile(fileRemove);
		list_ctrl_1->Delete(item);

		int sel = ctrl->GetSelection();

		if (sel != wxNOT_FOUND)
		{
			ctrl->DeletePage(sel);
		}
	}
}

// file event handlers
void MyFrame::OnFileOpen (wxCommandEvent &WXUNUSED(event)) {
	//if (!m_edit) return ;
#if wxUSE_FILEDLG
	issolution= false;
	wxFileDialog dlg ( this, wxT("Open file" ), wxEmptyString, wxEmptyString, wxT("Any file (*)|*" ),
		wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
	if (dlg.ShowModal() != wxID_OK) return ;
	fname = dlg.GetPath ();
	FileOpen (fname);
	wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
	OnCreateNotebook(fname);
	if (!m_edit) return ;
	m_edit->LoadFile (fname);
#endif // wxUSE_FILEDLG
}

void MyFrame::FileOpen (wxString fname)
{

	//m_edit->LoadFile (fname);
	//m_edit->SelectNone();
}

void MyFrame::OnFileSave (wxCommandEvent &WXUNUSED(event)) {
	if (!m_edit) return ;
	if (!m_edit->Modified()) {
		wxMessageBox (_( "There is nothing to save!"), _("Save file" ),
			wxOK | wxICON_EXCLAMATION);
		return;
	}
	savedfile=true;
	m_edit->SaveFile ();
}

void MyFrame::OnFileSaveAs (wxCommandEvent &WXUNUSED(event)) {
	if (!m_edit) return ;
#if wxUSE_FILEDLG
	wxString filename = wxEmptyString;
	wxFileDialog dlg ( this, wxT("Save file" ), wxEmptyString, wxEmptyString, wxT("Any file (*)|*" ), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() != wxID_OK) return ;
	filename = dlg.GetPath();
	m_edit->SaveFile (filename);
#endif // wxUSE_FILEDLG
}

void MyFrame::OnFileClose (wxCommandEvent &WXUNUSED(event)) {
	if (!m_edit) return ;
	if (m_edit->Modified()) {
		if (wxMessageBox (_("Text is not saved, save before closing?" ), _("Close"),
			wxYES_NO | wxICON_QUESTION) == wxYES) {
				m_edit->SaveFile();
				if (m_edit->Modified()) {
					wxMessageBox (_( "Text could not be saved!"), _("Close abort"),
						wxOK | wxICON_EXCLAMATION);
					return;
				}
		}
	}
	m_edit->SetFilename (wxEmptyString);
	m_edit->ClearAll();
	m_edit->SetSavePoint();
}

// edit events
void MyFrame::OnEdit (wxCommandEvent &event ) {
	if (m_edit) m_edit->GetEventHandler()->ProcessEvent (event);
}

void MyFrame::OnPrint (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
	wxPrintDialogData printDialogData( *g_printData);
	wxPrinter printer (&printDialogData);
	EditPrint printout (m_edit);
	if (!printer.Print (this , &printout, true)) {
		if (wxPrinter::GetLastError() == wxPRINTER_ERROR) {
			wxMessageBox (_( "There was a problem with printing.\n\
							 Perhaps your current printer is not correctly?"),
							 _( "Previewing"), wxOK);
			return;
		}
	}
	(*g_printData) = printer.GetPrintDialogData().GetPrintData();
#endif // wxUSE_PRINTING_ARCHITECTURE
}

// common event handlers
void MyFrame::OnClose (wxCloseEvent &event ) {
	if ( m_process )
	{
		// we're not interested in getting the process termination notification
		// if we are closing it ourselves
		wxProcess *process = m_process;
		m_process = NULL;
		process->SetNextHandler(NULL);

		process->CloseOutput();
	}

	event.Skip();

	wxCommandEvent evt;
	OnFileClose (evt);
	if (m_edit && m_edit->Modified()) {
		if (event .CanVeto()) event.Veto ( true);
		return;
	}
	Destroy();
}

void MyFrame::OnPrintPreview (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
	wxPrintDialogData printDialogData( *g_printData);
	wxPrintPreview *preview =
		new wxPrintPreview (new EditPrint (m_edit),
		new EditPrint (m_edit),
		&printDialogData);
	if (!preview->IsOk()) {
		delete preview;
		wxMessageBox (_( "There was a problem with previewing.\n\
						 Perhaps your current printer is not correctly?"),
						 _( "Previewing"), wxOK);
		return;
	}
	wxRect rect = DeterminePrintSize();
	wxPreviewFrame *frame = new wxPreviewFrame (preview, this , _("Print Preview"));
	frame->SetSize (rect);
	frame->Centre(wxBOTH);
	frame->Initialize();
	frame->Show( true);
#endif // wxUSE_PRINTING_ARCHITECTURE
}

// print event handlers
void MyFrame::OnPrintSetup (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
	(*g_pageSetupData) = * g_printData;
	wxPageSetupDialog pageSetupDialog( this, g_pageSetupData);
	pageSetupDialog.ShowModal();
	(*g_printData) = pageSetupDialog.GetPageSetupData().GetPrintData();
	(*g_pageSetupData) = pageSetupDialog.GetPageSetupData();
#endif // wxUSE_PRINTING_ARCHITECTURE
}

// properties event handlers
void MyFrame::OnProperties (wxCommandEvent &WXUNUSED(event)) {
	if (!m_edit) return ;
	EditProperties dlg(m_edit, 0);
}

wxRect MyFrame::DeterminePrintSize () {

	wxSize scr = wxGetDisplaySize();

	// determine position and size (shifting 16 left and down)
	wxRect rect = GetRect();
	rect.x += 16;
	rect.y += 16;
	rect.width = wxMin (rect.width, (scr.x - rect.x));
	rect.height = wxMin (rect.height, (scr.x - rect.y));

	return rect;
}
//-----------------File Handling Section Ends here---------------------------------------------

void MyFrame::OnNotebookPageClosed(wxAuiNotebookEvent& event)
{
	event.Skip();
	wxAuiNotebook* ctrl = (wxAuiNotebook*)event.GetEventObject();

	//// selection should always be a valid index
	//wxASSERT_MSG( ctrl->GetSelection() < (int)ctrl->GetPageCount(),
	//              wxString::Format("Invalid selection %d, only %d pages left",
	//                               ctrl->GetSelection(),
	//                               (int)ctrl->GetPageCount()) );
	//wxCommandEvent evt;
	//OnFileClose (event);
	/*if (m_edit && m_edit->Modified()) {
	if (event.CanVeto()) event.Veto ( true);
	return;
	}*/
	//if (!m_edit) return ;
	//if (m_edit->Modified()) {
	//	if (wxMessageBox (_("Text is not saved, save before closing?" ), _("Close"),
	//		wxYES_NO | wxICON_QUESTION) == wxYES) {
	//			m_edit->SaveFile();
	//			if (m_edit->Modified()) {
	//				wxMessageBox (_( "Text could not be saved!"), _("Close abort"),
	//					wxOK | wxICON_EXCLAMATION);
	//				return;
	//			}
	//	}
	//}
	//m_edit->SetFilename (wxEmptyString);
	//m_edit->ClearAll();
	//m_edit->SetSavePoint();
}

void MyFrame::OnCreateNotebook(wxString FileName)
{
	m_timer.Start(1000);
	wxFileName f(FileName);
	if ( f.GetExt().Lower() == wxT("cpp" ) )
	{
		m_edit = new Edit (this , wxID_ANY);
		m_edit->SetFocus();
		//wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));
		wxFileName w(FileName); w.Normalize(); FileName = w.GetFullPath();
		ctrl->AddPage(m_edit, w.GetFullName() , true , wxIcon( cpp_xpm ));
		m_edit->SetMarginRight(80);
		m_edit->SelectNone();
		ctrl->SetPageToolTip(0, FileName);
		ctrl->GetArtProvider()->SetColour(wxColour(68,88,125));
		ctrl->GetArtProvider()->SetActiveColour(wxColour(68,88,125));
		ctrl->SetFocus();
		m_mgr.Update();
	}
	else if ( f.GetExt().Lower() == wxT("c") ){
		m_edit = new Edit (this , wxID_ANY);
		m_edit->SetFocus();
		//wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));
		wxFileName w(FileName); w.Normalize(); FileName = w.GetFullPath();
		ctrl->AddPage(m_edit, w.GetFullName() , true , c_xpm);
		m_edit->SetMarginRight(80);
		m_edit->SelectNone();
		ctrl->SetPageToolTip(0, FileName);
		ctrl->GetArtProvider()->SetColour(wxColour(68,88,125));
		ctrl->GetArtProvider()->SetActiveColour(wxColour(68,88,125));
		ctrl->SetFocus();
		m_mgr.Update();
	}
	else if ( f.GetExt().Lower() == wxT("h") ){
		m_edit = new Edit (this , wxID_ANY);
		m_edit->SetFocus();
		//wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));
		wxFileName w(FileName); w.Normalize(); FileName = w.GetFullPath();
		ctrl->AddPage(m_edit, w.GetFullName() , true , hxx_xpm);
		m_edit->SetMarginRight(80);
		m_edit->SelectNone();
		ctrl->SetPageToolTip(0, FileName);
		ctrl->GetArtProvider()->SetColour(wxColour(68,88,125));
		ctrl->GetArtProvider()->SetActiveColour(wxColour(68,88,125));
		ctrl->SetFocus();
		m_mgr.Update();
	}
	else{
		//SetIcon(wxIcon(page_white_xpm));}
	}
}
// ----------------------------------------Adding New File to the Solution file ---------------------------------
void MyFrame::OnNewFile(wxCommandEvent& WXUNUSED(event))
{
	ofstream solution;
	solution.open(list_ctrl_1->GetItemText(root).mb_str(), ios_base::out| std::ofstream::app);
	frame_2 = new NewFile(this );
	int dlg = frame_2->ShowModal();
	*text2 << frame_2->TextCtrl2->GetLabel()<< "\n";
	if ( dlg == wxID_OK )
	{
		//list_ctrl_1->GetRootItem();
		//wxTreeItemId itemId = list_ctrl_1->GetId();
		ofstream myfile;
		wxString fname= frame_2->TextCtrl2->GetLineText(0);
		myfile.open (fname.mb_str(),ios_base::out | ios_base::in);

		if(myfile.is_open()){
			wxMessageBox( "Warning, file already exists, proceed?" );
			myfile.close();}
		else
		{
			*text2 << frame_2->TextCtrl2->GetLineText(0) << "\n";
			solution <<  frame_2->TextCtrl2->GetLineText(0) << "\n";
			wxTreeItemId item = list_ctrl_1->GetFocusedItem();
			list_ctrl_1->SetFocusedItem(item);
			wxString itemtext = list_ctrl_1->GetItemText(item);
			if(itemtext==wxT("Source Files" ))
			{
				wxString cppfiles = frame_2->TextCtrl2->GetLineText(0);
				string cppfilesconv = cppfiles.c_str();
				filessrc.push_back(cppfilesconv);

				//cpp = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none"), wxT("Source Files"));
				list_ctrl_1->AppendItem(item,frame_2->TextCtrl2->GetLineText(0), 2);
				list_ctrl_1->ExpandAll();
			} else if (itemtext==wxT("Header Files")){
				wxString headerfiles = frame_2->TextCtrl2->GetLineText(0);
				string hfilesconv = headerfiles.c_str();
				filesh.push_back(hfilesconv);

				//cpp = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none"), wxT("Source Files"));
				list_ctrl_1->AppendItem(item,frame_2->TextCtrl2->GetLineText(0), 2);
				list_ctrl_1->ExpandAll();
			}
			myfile.clear();
			myfile.open(fname.mb_str(), ios_base::out);  // will create if necessary

			wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();

			FileOpen (fname);
			//wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
			OnCreateNotebook(fname);
			if (!m_edit) return ;
			m_edit->LoadFile (fname);
			list_ctrl_1->Expand(root);
			list_ctrl_1->ExpandAll();
			tb2->EnableTool(wxID_REDO, true);
			/*m_edit->LoadFile (fname);
			ctrl->SetPageText(0, w.GetFullName());*/
			myfile.close();
			solution.close();
		}
	}

	m_mgr.Update();
	list_ctrl_dir->Refresh();
}

//------------------------------Project Solution file Created here ----------------------------
void MyFrame::OnFileProject(wxCommandEvent& WXUNUSED(event))
{

	frame_1 = new NewDialog(this );
	frame_1->TextCtrl1->SetLabelText(workspace_path);
	int dlg = frame_1->ShowModal();
	//*text2 << frame_1->TextCtrl2->GetLabel()<<"\n";

	if ( dlg == wxID_OK )
	{
		frame_1->Refresh();
		//*text2 <<"------ Build started: Project: " << frame_1->TextCtrl4->GetLabel();

		*text2 << frame_1->TextCtrl2->GetLineText(0)<< "\n";
		if(wxDirExists(workspace_path)) //Checks if directory exists
		{
			wxString propath=wxString::Format(workspace_path+ "\\" +frame_1->TextCtrl2->GetLineText(0));
			wxFileName::Mkdir( propath, 0777, wxPATH_MKDIR_FULL ); // creates the directory
			wxSetWorkingDirectory(propath);
			list_ctrl_dir->SetPath(propath);
			projpath=propath;
		}

		list_ctrl_1->SetItemText(root,frame_1->TextCtrl2->GetLineText(0));
		//wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		//wxFONTWEIGHT_BOLD, false);
		list_ctrl_1->SetItemBold(root, true);
		//list_ctrl_1->SetItemFont(root, font);
		list_ctrl_1->SetItemImage(root, 0, wxTreeItemIcon_Expanded);

		//wxArrayTreeItemIds items;
		//list_ctrl_1->SetItemBold(root, bold);
		itemsolutionid.Add(list_ctrl_1->AppendItem(root, wxT( "Source Files"), 1));
		itemsolutionid.Add(list_ctrl_1->AppendItem(root, wxT( "Header Files"), 1));
		list_ctrl_1->Expand(root);
		//wxTreeItemIdValue cookie;
		//wxTreeItemId id = GetFirstChild(root, cookie);
		//SetItemTextColour(id, *wxBLUE);
		list_ctrl_1->SetWindowStyle(wxTR_TWIST_BUTTONS);
		m_mgr.Update();
	}
}

void MyFrame::LoadTreeNodeState(wxXmlNode * node)
{  
	if(!node) return ;    
	wxXmlNode * child_node = node->GetChildren();
	while(child_node)
	{
		//check for from and subject
		if(child_node->GetName()==wxT("src" ))
		{
			wxXmlNode * child = child_node->GetChildren();
			//get children and set new value
			wxString cppstr= child_node->GetChildren()->GetContent();
			srcid=list_ctrl_1->AppendItem(root, wxT( "Source Files"), 1);
		}
		else if (child_node->GetName()==wxT("header"))
		{
			//get children and set new value
			wxString hstr= child_node->GetChildren()->GetContent();
			hid=list_ctrl_1->AppendItem(root, wxT( "Header Files"), 1);
		}
		else if (child_node->GetName()==wxT("cpp")){
			wxString cppstr= child_node->GetChildren()->GetContent();
			list_ctrl_1->AppendItem(srcid, cppstr, 2);
		}
		else if (child_node->GetName()==wxT("h")){
			wxString hstr= child_node->GetChildren()->GetContent();
			list_ctrl_1->AppendItem(hid, hstr, 2);
		}
		//get next child
		child_node = child_node->GetNext();
	}
}


void MyFrame::SaveTreeNodeState(wxTreeItemId id, wxXmlNode * node)
{
	//if(!node) return ;
	//if(!id.IsOk()) return ;
	//node->AddProperty(wxT( "Expanded"), wxString::Format(wxT("%u" ), !!list_ctrl_1->IsExpanded(id)));
	//wxTreeItemIdValue cookie;
	//wxTreeItemId child = list_ctrl_1->GetFirstChild(id, cookie);
	//wxXmlNode * child_node;
	//while(child.IsOk())
	//{
	//	child_node = new wxXmlNode(wxXML_ELEMENT_NODE, wxT("Item" ));
	//	node->AddChild(child_node);
	//	SaveTreeNodeState(child, child_node);
	//	if(child == list_ctrl_1->GetLastChild(id)) break;
	//	child = list_ctrl_1->GetNextChild(id, cookie);
	//	child_node = child_node->GetNext();
	//}
}

void MyFrame::GetItemsRecursively(const wxTreeItemId& idParent,
	wxTreeItemIdValue cookie)
{

	wxTreeItemId id;

	if ( !cookie )
		id = list_ctrl_1->GetFirstChild(idParent, cookie);
	else
		id = list_ctrl_1->GetNextChild(idParent, cookie);

	if ( !id.IsOk() )
		return;

	wxString text = list_ctrl_1->GetItemText(id);
	*text2 << text<< "\n";
	string texmp =text.mb_str();
	soultionfilevec.push_back(texmp);

	if (list_ctrl_1->ItemHasChildren(id))
		GetItemsRecursively(id);

	GetItemsRecursively(idParent, cookie);

}

void MyFrame::OnSaveProject(wxCommandEvent & event)
{
	if(list_ctrl_1->ItemHasChildren(root)){
		//wxTreeItemId root_item = list_ctrl_1->GetRootItem();
		wxString readsrc=wxString::Format(list_ctrl_1->GetItemText(root));
		//Create New document to hold things together
		wxXmlDocument doc;
		//create root node
		wxXmlNode* root = new  wxXmlNode(wxXML_ELEMENT_NODE, readsrc);
		//add it to document
		doc.SetRoot(root);
		//add other documents
		//add from
		srcnode = new  wxXmlNode(wxXML_ELEMENT_NODE, wxT("src"));
		//add value i.e fromme@example.com
		wxXmlNode* srctext = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none" ), wxT("Source Files" ));
		srcnode->AddChild(srctext);
		//add to root node
		root->AddChild(srcnode);

		for (size_t i=0; i < filessrc.size(); i++)
		{
			// wxIfNodeListManager will concatenate the <cmd> node
			// to the previous <if>, if possible
			cpp = new  wxXmlNode(wxXML_ELEMENT_NODE, wxT("cpp"));
			wxXmlNode *newnode1 = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none"),filessrc[i]);
			cpp->AddChild(newnode1);
			root->AddChild(cpp);
		}
		//add to
		headernode = new  wxXmlNode(wxXML_ELEMENT_NODE, wxT("header"));
		//add value i.e tome@example.com
		wxXmlNode* headertext = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none" ), wxT("Header Files" ));
		headernode->AddChild(headertext);
		//add to root node
		root->AddChild(headernode);

		for (size_t i=0; i < filesh.size(); i++)
		{
			// wxIfNodeListManager will concatenate the <cmd> node
			// to the previous <if>, if possible
			header = new  wxXmlNode(wxXML_ELEMENT_NODE, wxT("h"));
			wxXmlNode *newnode2 = new  wxXmlNode(wxXML_TEXT_NODE, wxT("none"),filesh[i]);
			header->AddChild(newnode2);
			root->AddChild(header);
		}

		//save document
		wxString solxml=wxString::Format( "%s.xml",readsrc);
		doc.Save(solxml);
	}
}

void MyFrame::OnLoadProject(wxCommandEvent& WXUNUSED(event))
{
	list_ctrl_1->DeleteAllItems();
	root = list_ctrl_1->AddRoot( "Workspace", -1, -1, NULL);
	wxFileDialog dlg( this, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString,
		_( "XML Files (*.xml)|*.xml"), wxFD_OPEN);
	if(dlg.ShowModal() == wxID_OK)
	{
		wxXmlDocument document(dlg.GetPath());
		if(document.IsOk())
		{
			wxXmlNode * node = document.GetRoot();
			wxString rootname = document.GetRoot()->GetName();
			list_ctrl_1->SetItemText(root,rootname);
			list_ctrl_1->SetItemBold(root, true);
			list_ctrl_1->SetItemImage(root, 0, wxTreeItemIcon_Expanded);
			LoadTreeNodeState(node);

			if(wxDirExists(dlg.GetDirectory())) //Checks if directory exists
			{
				projpath=wxString::Format(dlg.GetDirectory());
				// wxFileName::Mkdir( propath, 0777, wxPATH_MKDIR_FULL ); // creates the directory
				wxSetWorkingDirectory(projpath);
				list_ctrl_dir->SetPath(projpath);
			}
		}
	}

}

MyFrame::~MyFrame()
{
	// deinitialize the frame manager
	wxDELETE(m_Prn);
	//if(m_edit==NULL)wxDELETE(m_edit);
	m_mgr.UnInit();
	m_timer.Stop();


	if ( m_process )
	{
		// we're not interested in getting the process termination notification
		// if we are closing it ourselves
		wxProcess *process = m_process;
		m_process = NULL;
		process->SetNextHandler(NULL);

		process->CloseOutput();
	}

	Destroy();
}

void
	MyFrame::OnQuit(wxCommandEvent&
	WXUNUSED( event))
{

	//OnSaveSolution(root);
	Close( true);

}

void MyFrame::OnSaveSolution(wxTreeItemId root)
{
	GetItemsRecursively(root); 
	ofstream solutionfile;
	wxString slfilename=wxString::Format( "%s.mprj",list_ctrl_1->GetItemText(root));
	int i, count;std::vector<string> solutionid;
	for (i = 0, count = itemsolutionid.Count(); i < count; ++i)
	{
		wxTreeItemId id = itemsolutionid.Item(i);

		int i = list_ctrl_1->GetChildrenCount( id );
		wxString text = list_ctrl_1->GetItemText(id);
		string texmp =text.mb_str();
		solutionid.push_back(texmp);
	}

	solutionfile.open( slfilename.mb_str(), ios::binary);

	if (solutionfile.is_open()){
		for(int j=0; j < solutionid.size(); j++)
		{
			solutionfile<<solutionid[j].c_str()<< "\n";
		}}
	else { *text2<<"Unable to open the file" ;}
	solutionfile.close();
}

void MyFrame::OnExit (wxCommandEvent &WXUNUSED(event)) {

	//OnSaveSolution(root);
	//m_treeCtrl->DeleteAllItems();
	Close ( true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxT( "MinGW visual studio\n")
		wxT( "(c) Sricharan Amarnath 2014, MGWSRI++" ),
		wxT( "MinGW visual studio - Express Edition 2014" ),
		wxOK | wxICON_INFORMATION, this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------Compiler Section Starts Here-----------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------Single File compilation------------------------------
void MyFrame::OnCompile (wxCommandEvent &WXUNUSED(event)) {

	//g++ -Wall -g -o Hello.exe Hello.cpp
	wxTreeItemId item = list_ctrl_1->GetFocusedItem();

	//CHECK_ITEM( item );

	int i = list_ctrl_1->GetChildrenCount( item );

	*text2 << wxT( "No of children: ")<<i;

	//wxString cmdl=wxString::Format("C:\\MinGW\\bin\\g++.exe %s -o %s",w.GetFullName(),fname.c_str(),TargetExe);
	if(!issolution){
		//------ Build started: Project: stctest, Configuration: Debug Win32 ------
		text2->Clear();
		*text2 << "------ Build started: Project: " << "src" << ", Configuration: Debug Win32 ------"<< "\n";
		*text2 << "Compiling ........"<<"\n" ;
		*text2 <<ctrl->GetPageText(0)<< "........"<<"\n" ;
		wxString currentDir = wxGetCwd();
		wxSetWorkingDirectory(currentDir);

		wxFileName w(fname); w.Normalize();fname = w.GetFullPath();
		//wxString Filenamesrc = w.Normalize().c_str();
		wxString TargetExe=(w.GetName());
		m_edit->LoadFile (fname);
		ctrl->SetPageText(0, w.GetFullName());
		wxString cmdl=wxString::Format( "..\\MinGW\\bin\\g++.exe %s -o %s",w.GetFullName(),TargetExe);
		wxString cmdd=wxT("D:/Tools/wxWidgets-3.0.0/samples/stc/MinGW/bin/g++.exe main.cpp -o zmingw");
		//int i=system("D:/Projects/Express Edition/MinGW/bin/g++.exe main.cpp -o zmingw");
		int i=system(cmdl);
		//text2->AppendText(i);
		if(!i)
		{
			*text2 << "Linking......... "<<"\n" ;
			*text2 << "========== Build:  " << 1 << " succeeded" << "  0 skipped ========== "<< "\n";

		} else
		{
			*text2 << "Linking Failed......... "<<"\n" ;
			*text2 << "========== Build:  " << 0 << " succeeded" << "  1 failed ========== "<< "\n";
		}
		//========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
	}
}

//------------------------------Solution File compilation------------------------
void MyFrame::OnBuild (wxCommandEvent &WXUNUSED(event)) {


	//g++ -Wall -g -o Hello.exe Hello.cpp
	wxTreeItemId item = list_ctrl_1->GetFocusedItem();
	ofstream solution1;
	solution1.open( "Makefile", ios_base::out);
	solution1<< "# Auto generated make file  using Mingw visual studio\n" ;

	int array_size = 1024; // define the size of character array
	char * array = new char[array_size]; // allocating an array of 1kb
	int position = 0; //this will be used incremently to fill characters in the array
	wxString readsrc=wxString::Format(list_ctrl_1->GetItemText(root));
	ifstream fin(readsrc.mb_str()); //opening an input stream for file test.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
	stream could not be opened.*/
	if(fin.is_open())
	{
		//file opened successfully so we are here
		*text2 << "Solution File Opened successfully!!!. Build in process" << "\n";
		//this loop run until end of file (eof) does not occur
		while(!fin.eof() && position < array_size)
		{
			fin.get( array[position]); //reading one character from file to array
			position++;
		}
		array[position-1] = '\0' ; //placing character array terminating character

		//*text2 << "Displaying Array..." << "\n"<<"\n";
		wxString temp_src=wxString::Format( "SRC=");
		solution1<<wxString::FromAscii(temp_src);
		//this loop display all the charaters in array till \0
		for(int i = 0; array[i] != '\0'; i++)
		{
			if(array [i] == '\n')
			{
				*text2 << '\t';
				solution1<<wxString::FromAscii( '\t');
			}
			else
			{
				*text2 << array[i];
				solution1<<wxString::FromAscii( array[i]);}
		}     
	}
	else //file could not be opened
	{
		*text2 << "Solution File could not be opened." << "\n";
	}
	solution1<< '\n';
	wxString temp2=wxString::Format( "EXE=%s.exe\n" ,list_ctrl_1->GetItemText(root));
	solution1<< "OBJ=$(SRC:.cxx=.o) # replaces the .cpp from SRC with .o\n" ;
	solution1<<temp2<< "\n";
	const char * text_build =
		"CC=gcc\n"
		"CFLAGS=-Wall -O3\n"
		"LDFLAGS=-mwindows\n"
		"RM=rm\n"
		"\n"
		"%.o: %.cxx         # combined w/ next line will compile recently changed .c files\n"
		"\t $(CXX) $(CXXFLAGS) -g -o $@ -c $<\n"
		"\n"
		".PHONY : all     # .PHONY ignores files named all\n"
		"all: $(EXE)      # all is dependent on $(EXE) to be complete\n"
		"\n"
		"$(EXE): $(OBJ)   # $(EXE) is dependent on all of the files in $(OBJ) to exist\n"
		"\t $(CXX) $(OBJ) $(LDFLAGS) -g -o $@\n"
		"\n"
		".PHONY : clean   # .PHONY ignores files named clean\n"
		"clean:\n"
		"\t-$(RM) $(OBJ) core    # '-' causes errors not to exit the proces\n";
	//solution1<<wxString::FromAscii(text_build);
	solution1<<text_build;
	solution1.close();

	wxString cmd_build=wxString::Format( "\\MinGW\\bin\\mingw32-make.exe" );
	text2->Clear();
	//int i=system(cmd_build);
	if ( !cmd_build )
	{
		return;
	}
	if ( true )
	{


		*text2<<wxString::Format( "\"%s\" is running please wait...\n" , cmd_build.c_str());

		wxStopWatch sw;

		wxArrayString output, errors;
		int code = wxExecute(cmd_build.mb_str(), output, errors);

		*text2<<( "Command \"%s\" terminated after %ldms; exit code %d.\n" ,
			cmd_build, sw.Time(), code);

		ShowOutput(cmd_build.mb_str(), output, wxT( "Output"));
		ShowOutput(cmd_build.mb_str(), errors, wxT( "Errors"));
		//*text2 << "Linking......... "<<"\n" ;
		//*text2 << "========== Build:  " << 1 << " succeeded" << "  0 skipped ========== "<<"\n";
		start= true;
		tb2->EnableTool(ID_START,true);


	}
	else
	{
		wxMessageBox( "there were build errors.");
		*text2 << "Linking Failed......... "<<"\n" ;
		*text2 << "========== Build:  " << 0 << " succeeded" << "  1 failed ========== "<<"\n";
		start= false;
	}

}

//---------------------------------REbuild the solution file-----------------------------------------
void MyFrame::OnReBuild (wxCommandEvent &WXUNUSED(event)) {

}


//-----------------------------------Clean Solution file---------------------------------------------
void MyFrame::OnClean (wxCommandEvent &WXUNUSED(event)) {

	wxString cmd_build=wxString::Format( "\\MinGW\\bin\\mingw32-make.exe clean");
	text2->Clear();
	//int i=system(cmd_build);
	if ( !cmd_build )
	{
		return;
	}
	if ( true )
	{


		*text2<<wxString::Format( "\"%s\" is running please wait...\n" , cmd_build.c_str());

		wxStopWatch sw;

		wxArrayString output, errors;
		int code = wxExecute(cmd_build.mb_str(), output, errors);

		*text2<<( "Command \"%s\" terminated after %ldms; exit code %d.\n" ,
			cmd_build, sw.Time(), code);

		ShowOutput(cmd_build.mb_str(), output, wxT( "Output"));
		ShowOutput(cmd_build.mb_str(), errors, wxT( "Errors"));
		*text2 << "Linking......... "<<"\n" ;
		*text2 << "========== Build:  " << 1 << " succeeded" << "  0 skipped ========== "<<"\n";
		start= true;

	}
	else
	{
		wxMessageBox( "there were build errors.");
		*text2 << "Linking Failed......... "<<"\n" ;
		*text2 << "========== Build:  " << 0 << " succeeded" << "  1 failed ========== "<<"\n";
		start= false;
	}
}

//------------------------------------Run the Program -------------------------------------------
void MyFrame::OnStart (wxCommandEvent &event )
{
	if(start)
	{
		wxString cmd_start=wxString::Format( "%s.exe" ,list_ctrl_1->GetItemText(root));
		*text2<<(wxGetCwd().c_str());
		if ( !cmd_start )
		{
			return;
		}
		if ( true )
		{
			*text2<<wxString::Format( "\"%s\" is running please wait...\n", cmd_start);

			wxStopWatch sw;

			wxArrayString output, errors;
			int code = wxExecute(cmd_start, output, errors);

			*text2<<( "Command \"%s\" terminated after %ldms; exit code %d.\n",
				cmd_start, sw.Time(), code);

			ShowOutput(cmd_start, output, wxT( "Output"));
			ShowOutput(cmd_start, errors, wxT( "Errors"));

			if(!projpath.IsEmpty()){
				wxString cmdl=wxString::Format( "cd %s", projpath);
				DoSend(cmdl);
			}
		}
		else
		{
			wxMessageBox( "there were build errors.");
		}
	}
}

//--------------------------Console Output Starts Here -----------------------------------------------
void MyFrame::ShowOutput(const wxString& cmd,
	const wxArrayString& output,
	const wxString& title)
{
	size_t count = output.GetCount();
	if ( !count )
		return;

	*text2<<(wxString::Format(wxT( "========== Output: %s of '%s' ==========:\n"),
		title.c_str(), cmd.c_str()));

	for ( size_t n = 0; n < count; n++ )
	{
		*text2<<(output[n])<< "\n";
	}

	*text2<<(wxString::Format(wxT( "========== End of %s ==========\n" ),
		title.Lower().c_str()));
}
//-------------------------------Compilere Section ENDS here ---------------------------------------------------

// Timer Needs to be fine tuned yet---------------------
void MyFrame::OnTimer(wxTimerEvent& event )
{
	//	int selPageId=ctrl->GetSelection();
	//	modt = ctrl->GetPageText(selPageId);
	////--------------------File Modification text ------------------
	//if (m_edit->Modified())
	//{
	//	m_edit->Modified()==false;
	//	wxString modname = wxString::Format(wxT("%s*"),modt);
	//	ctrl->SetPageText(selPageId,modname);
	//}
	//else if(savedfile)
	//{
	//int selPageId=ctrl->GetSelection();
	//	//wxString modt = ctrl->GetPageText(selPageId);
	//	wxString modname = wxString::Format(modt);
	//}

	//---------------------------------------------------
	if (m_edit->breakpoint_flag==true && !(m_edit==NULL))
	{
		wxString breakfilenmae= m_edit->GetFilename(); // Adding Curr File Name under Brakpoint panel
		wxFileName w(breakfilenmae);
		// m_item_list->SetItem(0, 0, breakfilenmae);
		for(int j=0; j < m_edit->breakpointsvec.size(); j++){
			//long itemIndex = WxListCtrl1->InsertItem(0, "1"); //want this for col. 1
			wxString mystring = wxString::Format(wxT( "%i"), m_edit->breakpointsvec[j]);// Adding Breakpoint line number under Breakpoint panel
			// m_item_list->InsertItem(j, mystring);
			//long tmp = m_item_list->InsertItem(j, mystring);
			//m_item_list->SetItemData(tmp, j);
			//buf.Printf(wxT("This is item %d"), i);

			long tmp = m_item_list->InsertItem(j, w.GetFullName(),3);
			m_item_list->SetColumnWidth(tmp, wxLIST_AUTOSIZE ); 
			//m_item_list->SetItemColumnImage(tmp, 0, 4);
			//m_item_list->SetItemData(mystring, j);
			//m_item_list->SetItem(j, 0, mystring);
			//m_item_list->SetItem(0, j, mystring);
			//long tmp = m_item_list->SetItem(0, 0, breakfilenmae);
			m_item_list->SetItem(tmp, 1, mystring);
		}
		m_edit->breakpoint_flag=false;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Application Class Starts here-----------------------------------------------------------------
//
/////////////////////////////////////////////////////////////////////////////////////////////////
class MyApp : public wxApp {
public:



	bool OnInit()
	{
		wxInitAllImageHandlers();
		wxImage::AddHandler( new wxPNGHandler);
		//g_printData = new wxPrintData;
		//g_pageSetupData = new wxPageSetupDialogData;
		//wxString cmdl=wxString::Format("D:\\ExpressEditionV1.0\\MinGW\\bin\\gdb.exe");
		wxString cmdl=wxString::Format( "..\\MinGW\\bin\\gdb.exe");
		wxProcess* process = wxProcess::Open(cmdl);
		if ( !process )
		{
			wxLogError(wxT( "Failed to launch the command." ));
			return false;
		}
		wxLogVerbose(wxT( "PID of the new process: %ld"), process->GetPid());

		wxOutputStream *out = process->GetOutputStream();
		if ( !out )
		{
			wxLogError(wxT( "Failed to connect to child stdin" ));
			return false;
		}
		wxInputStream *in = process->GetInputStream();
		if ( !in )
		{
			wxLogError(wxT( "Failed to connect to child stdout" ));
			return false;
		}

		if(process){
			//MyFrame* frame_1 = new MyFrame(NULL, wxEmptyString, NULL);
			MyFrame* frame_1=  new MyFrame(NULL, _("MinG++ IDE - 2014"), process);
			//MyFrame* frame_1 = new MyFrame(NULL, wxID_ANY, wxEmptyString);
			SetTopWindow(frame_1);
			frame_1->Show();;
			return true ;} 
		return true;
	}
};

DECLARE_APP(MyApp);
IMPLEMENT_APP(MyApp);


