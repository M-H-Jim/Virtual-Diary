#ifndef MAINFRAME_H
#define MAINFRAME_H



#include <wx/wx.h>

class mainFrame : public wxFrame {
    
    public:
        
        mainFrame(const wxString& title);
    
    private:
        
        // MenuBar
        
        wxMenu *menuFile;
        wxMenu *menuAbout;
        wxMenu *menuSettings;
        
        wxMenuBar *menuBar;
        
        
        
        
        
        
        
        
        
        
        
        void OnHello(wxCommandEvent& evt);
        void OnExit(wxCommandEvent& evt);
        void OnAbout(wxCommandEvent& evt);
        void OnChangeLoginData(wxCommandEvent& evt);
        
        
        
        
        
        
        
        
        
        
        
        void Binding();
    
    
};






#endif // MAINFRAME_H
