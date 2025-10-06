#ifndef LOGIN_H
#define LOGIN_H



#include <wx/wx.h>

class loginDialog : public wxDialog {
    public:
        
        loginDialog(const wxString& title);
        
        wxString GetUsername() const;
        wxString GetPassword() const;
        
    private:
        
        wxBoxSizer *sizer;
        
        
        
        wxStaticText *usernameStatic;
        wxStaticText *passwordStatic;
        
        wxTextCtrl *usernameCtrl;
        wxTextCtrl *passwordCtrl;
        
        
        
        
        wxBoxSizer *buttonSizer;
        
        wxButton *loginButton;
        wxButton *cancelButton;
        
        
        wxStaticBitmap *logobitmap;
        
        
        
        void OnLogin(wxCommandEvent& evt);
        void OnCancel(wxCommandEvent& evt);
        
        
        
        
        void Binding();
        
        
};






#endif // LOGIN_H
