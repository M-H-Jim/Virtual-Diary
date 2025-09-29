#include "../include/mainframe.h"
#include "../include/logindatadialog.h"


#include <wx/datetime.h>



enum {
    ID_HELLO = wxID_HIGHEST + 1,
    ID_CHANGE_LOGIN_DATA
};





mainFrame::mainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    
    
    menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H", "Help String");
    //--------------------------------------------------------------
    menuFile->AppendSeparator();
    //--------------------------------------------------------------
    menuFile->Append(wxID_EXIT);
    
    
    
    /*--------------------------------------------------------------*/
    
    menuSettings = new wxMenu;
    menuSettings->Append(ID_CHANGE_LOGIN_DATA, "&Change Username or Password...\tCtrl-S", "Settings");
    
    
    
    /*--------------------------------------------------------------*/
    
    menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    
    
    menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
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
    
    
    
    
    
    
    CreateStatusBar();
    SetStatusText("Welcome to Virtual Diary!");
    
    
    Binding();
    
}










void mainFrame::Binding() {
    
    Bind(wxEVT_MENU, &mainFrame::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &mainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &mainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &mainFrame::OnChangeLoginData, this, ID_CHANGE_LOGIN_DATA);
    
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
                        }
                    }
                    evt.Skip();
                });
    
}

void mainFrame::OnHello(wxCommandEvent& evt) {
    wxLogMessage("Hello from virtual Diary");
}

void mainFrame::OnAbout(wxCommandEvent& evt) {
    wxMessageBox("This is my Uni Project", "About ME", wxOK | wxICON_INFORMATION);
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
    
    wxListBox* notesList = new wxListBox(splitter, wxID_ANY);
    notesList->AppendString("2025-09-25: My first note");
    notesList->AppendString("2025-09-26: Another entry");
    notesList->AppendString("2025-09-27: Today's note");
    
    
    
    
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
    splitter->SetMinimumPaneSize(400); 

    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(splitter, 1, wxEXPAND);
    panel->SetSizer(sizer);

}


void mainFrame::SetupPhonebookUI(wxPanel *panel) {
    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Phonebook Tab");
    sizer->Add(label, 0, wxALL | wxCENTER, 20);

    panel->SetSizer(sizer);
    
}










