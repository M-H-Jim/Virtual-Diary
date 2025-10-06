#include "../include/mainframe.h"
#include "../include/logindatadialog.h"
#include "../include/note.h"


#include <wx/aboutdlg.h>
#include <wx/datetime.h>
#include <wx/dir.h>



enum {
    ID_HELLO = wxID_HIGHEST + 1,
    ID_CHANGE_LOGIN_DATA,
    ID_EDIT
};





mainFrame::mainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    
    
    wxIcon appIcon;
    appIcon.LoadFile("img/favicon.png", wxBITMAP_TYPE_PNG);
    SetIcon(appIcon);
        
    
    
    
    
    menuFile = new wxMenu;
    menuFile->Append(wxID_NEW, "New Note\tCtrl+N", "Create a new entry");
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl+H", "Help String");
    //--------------------------------------------------------------
    menuFile->AppendSeparator();
    //--------------------------------------------------------------
    menuFile->Append(wxID_EXIT);
    
    /*--------------------------------------------------------------*/
    
    menuEdit = new wxMenu;
    menuEdit->Append(wxID_EDIT, "Edit note\tCtrl+E", "Edit current note");
    menuEdit->Append(wxID_SAVE, "Save\tCtrl+S", "Save the current file");
    
    
    
    
    
    /*--------------------------------------------------------------*/
    
    menuSettings = new wxMenu;
    menuSettings->Append(ID_CHANGE_LOGIN_DATA, "&Change Username or Password...\tCtrl-P", "Settings");
    
    
    
    /*--------------------------------------------------------------*/
    
    menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    
    
    menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    menuBar->Append(menuSettings, "&Settings");
    menuBar->Append(menuAbout, "&About");
    
    
    SetMenuBar(menuBar);
    
    
    
    noteBook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 
                                 wxAUI_NB_DEFAULT_STYLE & 
                                 ~(wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_CLOSE_ON_ACTIVE_TAB));
    
    diaryPanel = new wxPanel(noteBook);
    SetupDiaryUI(diaryPanel);
    
    phonebookPanel = new wxPanel(noteBook);
    SetupPhonebookUI(phonebookPanel);
    
    
    noteBook->AddPage(diaryPanel, "Diary");
    noteBook->AddPage(phonebookPanel, "Phonebook");
    
    
    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(noteBook, 1, wxEXPAND);
    this->SetSizer(sizer);
    
    
    
    LoadNotes();
    
    
    CreateStatusBar();
    SetStatusText("Welcome to Virtual Diary!");
    
    
    Binding();
    
}










void mainFrame::Binding() {
    
    Bind(wxEVT_MENU, &mainFrame::Editable, this, wxID_NEW);
    Bind(wxEVT_MENU, &mainFrame::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &mainFrame::OnAbout, this, wxID_ABOUT);
    
    
    
    Bind(wxEVT_MENU, &mainFrame::SaveNote, this, wxID_SAVE);
    Bind(wxEVT_MENU, &mainFrame::Editable, this, wxID_EDIT);
    
    
    Bind(wxEVT_LISTBOX, &mainFrame::OnNoteSelect, this, notesList->GetId());
    
    
    
    
    Bind(wxEVT_MENU, &mainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &mainFrame::OnChangeLoginData, this, ID_CHANGE_LOGIN_DATA);
    
    
    
    titleCtrl->Bind(wxEVT_LEFT_DCLICK, &mainFrame::OnTitleDoubleClick, this);
    locationCtrl->Bind(wxEVT_LEFT_DCLICK, &mainFrame::OnLocationDoubleClick, this);
    diaryText->Bind(wxEVT_LEFT_DCLICK, &mainFrame::OnDiaryDoubleClick, this);
    
    
    
    
    
    diaryText->Bind(wxEVT_KEY_DOWN, [=](wxKeyEvent& evt) {
                    
                    if(evt.ControlDown()) {
                        
                        switch(evt.GetKeyCode()) {
                            
                            case 'B':
                                diaryText->ApplyBoldToSelection();
                                return;
                            case 'I':
                                diaryText->ApplyItalicToSelection();
                                return;
                            case 'U':
                                diaryText->ApplyUnderlineToSelection();
                                return;
                            case 'T':
                                diaryText->ApplyTextEffectToSelection(wxTEXT_ATTR_EFFECT_STRIKETHROUGH);
                                return;
                        }
                    }
                    evt.Skip();
                });
    
}

void mainFrame::OnHello(wxCommandEvent& evt) {
    wxLogMessage("Hello from virtual Diary");
}

void mainFrame::OnAbout(wxCommandEvent& evt) {
    
    wxAboutDialogInfo info;
    
    info.SetName("Virtual Diary");
    info.SetVersion("1.0.0");
    info.SetDescription(" A lightweight, personal diary app");
    info.SetCopyright("(c) 2025 M.H.Jim");
    info.SetWebSite("https://website.com", "Visit Project Website");
    info.AddDeveloper("M.H.Jim");

    wxAboutBox(info);
    
    
}

void mainFrame::OnExit(wxCommandEvent& evt) {
    Close(true);
}

void mainFrame::OnChangeLoginData(wxCommandEvent& evt) {
    loginDataDialog dlg("Change Username / Password");
    dlg.ShowModal();
}




void mainFrame::SetupDiaryUI(wxPanel *panel) {
    
    
    splitter = new wxSplitterWindow(panel, wxID_ANY);
    
    notesList = new wxListBox(splitter, wxID_ANY);
    
    
    wxPanel *diaryPanel = new wxPanel(splitter, wxID_ANY);
    wxBoxSizer *diarySizer = new wxBoxSizer(wxVERTICAL);
    
    
    //----------------------------------------
    
    titleBarSizer = new wxBoxSizer(wxHORIZONTAL);
    
    titleLabel = new wxStaticText(diaryPanel, wxID_ANY, "Title:");
    titleCtrl = new wxTextCtrl(diaryPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    
    locationLabel = new wxStaticText(diaryPanel, wxID_ANY, "Location: ");
    locationCtrl = new wxTextCtrl(diaryPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    
    dateLabel = new wxStaticText(diaryPanel, wxID_ANY, "Date: ");
    wxString today = wxDateTime::Now().FormatISODate();
    dateCtrl = new wxTextCtrl(diaryPanel, wxID_ANY, today, wxDefaultPosition, wxDefaultSize, 
                              wxTE_READONLY);
    
    
    
    
    
    
    
    titleBarSizer->Add(titleLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    titleBarSizer->Add(titleCtrl, 2, wxALL | wxEXPAND, 5);
    titleBarSizer->Add(locationLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    titleBarSizer->Add(locationCtrl, 2, wxALL | wxEXPAND, 5);
    titleBarSizer->Add(dateLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    titleBarSizer->Add(dateCtrl, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    
    
    //------------------------------------------------------------
    
    
    diaryText = new wxRichTextCtrl(diaryPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 
                                           wxTE_MULTILINE |
                                           wxVSCROLL |
                                           wxHSCROLL |
                                           wxWANTS_CHARS);

    
    
    diarySizer->Add(titleBarSizer, 0, wxALL | wxEXPAND, 5);
    diarySizer->Add(diaryText, 1, wxALL | wxEXPAND, 5);
    
    
    
    
    
    diaryPanel->SetSizer(diarySizer);
    
    splitter->SplitVertically(notesList, diaryPanel);

    
    splitter->SetSashPosition(200);
    splitter->SetMinimumPaneSize(200); 

    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(splitter, 1, wxEXPAND);
    panel->SetSizer(sizer);

}


void mainFrame::SetupPhonebookUI(wxPanel *panel) {
    
//    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
//
//    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Phonebook Tab");
//    sizer->Add(label, 0, wxALL | wxCENTER, 20);
//
//    panel->SetSizer(sizer);
    
    
    
    phonebookSplitter = new wxSplitterWindow(panel, wxID_ANY);
    
    
    peopleList = new wxListBox(phonebookSplitter, wxID_ANY);
    
    
    
    
    wxPanel *phonebookPanel = new wxPanel(phonebookSplitter, wxID_ANY);
    
    
    wxBoxSizer *phonebookSizer = new wxBoxSizer(wxVERTICAL);
    
    phonebookPanel->SetSizer(phonebookSizer);
    
    
    
    phonebookSplitter->SplitVertically(phonebookPanel, peopleList);

    
    phonebookSplitter->SetSashPosition(1200);
    phonebookSplitter->SetMinimumPaneSize(400); 
    
    
    
    wxBoxSizer* psizer = new wxBoxSizer(wxVERTICAL);
    psizer->Add(phonebookSplitter, 1, wxEXPAND);
    panel->SetSizer(psizer);
    
    
    
    
}


wxString mainFrame::GetNotesFolderPath() {
    
    wxFileName exePath(wxStandardPaths::Get().GetExecutablePath());
    wxString folder = exePath.GetPath() + "/notes";
    
    if(!wxDirExists(folder))
        wxMkdir(folder);
    
    return folder;
}



void mainFrame::SaveNote(wxCommandEvent& evt) {
    
    
    int c = wxMessageBox("Do you want to save the file?", "Confirm Save",
                          wxYES_NO | wxICON_QUESTION, this);
    
    if(c == wxYES) {
            
        wxString title = titleCtrl->GetValue();
        wxString location = locationCtrl->GetValue();
        wxString date = dateCtrl->GetValue();
        wxString text = diaryText->GetValue();
        
        
        Note note(title, location, date, text);
        wxString folder = GetNotesFolderPath();
        
        if(note.Save(folder)) {
            wxMessageBox("Note Saved Successfully!", "Success");
            notesList->Clear();
            LoadNotes();
        }
        else {
            wxMessageBox("Failed to save note.", "Error");
        }
    }
    
}


void mainFrame::LoadNotes() {
    
    wxString folder = GetNotesFolderPath();
    wxDir dir(folder);
    
    if(!dir.IsOpened()) return;
    
    wxString filename;
    bool c = dir.GetFirst(&filename, "*.txt");
    while(c) {
        notesList->AppendString(filename.BeforeLast('.'));
        c = dir.GetNext(&filename);
    }
    
}


void mainFrame::Editable(wxCommandEvent& evt) {
    
    int currentPage = noteBook->GetSelection();
    
    switch(currentPage) {
        
        case 0:
            EditableDiary(evt);
            break;
        
        
        
        
        default:
            break;
        
        
        
        
        
    }
    
    
}












void mainFrame::UneditableDiary() {
    
    titleCtrl->SetEditable(false);
    locationCtrl->SetEditable(false);
    diaryText->SetEditable(false);
    
    titleCtrl->SetBackgroundColour(wxColour(240, 240, 240));
    locationCtrl->SetBackgroundColour(wxColour(240, 240, 240));
    dateCtrl->SetBackgroundColour(wxColour(240, 240, 240));
    diaryText->SetBackgroundColour(wxColour(240, 240, 240));
    
    titleCtrl->Refresh();
    locationCtrl->Refresh();
    diaryText->Refresh();
        
}

void mainFrame::EditableDiary(wxCommandEvent& evt) {
    
    titleCtrl->SetEditable(true);
    locationCtrl->SetEditable(true);
    diaryText->SetEditable(true);
    
    titleCtrl->SetBackgroundColour(*wxWHITE);
    locationCtrl->SetBackgroundColour(*wxWHITE);
    dateCtrl->SetBackgroundColour(*wxWHITE);
    diaryText->SetBackgroundColour(*wxWHITE);
    
    titleCtrl->Refresh();
    locationCtrl->Refresh();
    diaryText->Refresh();
    
    if(evt.GetId() == wxID_NEW) {
        titleCtrl->Clear();
        locationCtrl->Clear();
        diaryText->Clear();
        
        wxString today = wxDateTime::Now().FormatISODate();
        dateCtrl->SetValue(today);
        
        
    }
        
}


void mainFrame::OnTitleDoubleClick(wxMouseEvent& evt) {
    
    titleCtrl->SetEditable(true);
    titleCtrl->SetFocus();
    titleCtrl->SetBackgroundColour(*wxWHITE);
    
    evt.Skip();
}

void mainFrame::OnLocationDoubleClick(wxMouseEvent& evt) {
    
    locationCtrl->SetEditable(true);
    locationCtrl->SetFocus();
    locationCtrl->SetBackgroundColour(*wxWHITE);
    
    evt.Skip();
}

void mainFrame::OnDiaryDoubleClick(wxMouseEvent& evt) {
    
    diaryText->SetEditable(true);
    diaryText->SetFocus();
    diaryText->SetBackgroundColour(*wxWHITE);
    
    evt.Skip();
    
}



void mainFrame::OnNoteSelect(wxCommandEvent& evt) {
    wxString filename = notesList->GetStringSelection();
    wxString folder = GetNotesFolderPath();
    
    Note note;
    if(note.Load(folder + "/" + filename + ".txt")) {
        titleCtrl->SetValue(note.GetT());
        locationCtrl->SetValue(note.GetL());
        dateCtrl->SetValue(note.GetD());
        diaryText->SetValue(note.GetText());
        
        
        UneditableDiary();
        
        
        
    }
}














