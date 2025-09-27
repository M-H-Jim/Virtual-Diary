#include "../include/mainframe.h"
#include "../include/logindatadialog.h"


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
    
    CreateStatusBar();
    SetStatusText("Welcome to Virtual Diary!");
    
    
    Binding();
    
}










void mainFrame::Binding() {
    
    Bind(wxEVT_MENU, &mainFrame::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &mainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &mainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &mainFrame::OnChangeLoginData, this, ID_CHANGE_LOGIN_DATA);
    
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






