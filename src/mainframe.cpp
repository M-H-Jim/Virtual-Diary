#include "../include/mainframe.h"


enum {
    ID_HELLO = 1
};





mainFrame::mainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    
    menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H", "Help String");
    //--------------------------------------------------------------
    menuFile->AppendSeparator();
    //--------------------------------------------------------------
    menuFile->Append(wxID_EXIT);
    
    
    menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    
    
    menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuAbout, "&About");
    
    
    SetMenuBar(menuBar);
    
    CreateStatusBar();
    SetStatusText("Welcome to Virtual Diary!");
    
    
    binding();
    
}










void mainFrame::binding() {
    
    Bind(wxEVT_MENU, &mainFrame::OnHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &mainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &mainFrame::OnExit, this, wxID_EXIT);
    
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








