#ifndef LOGIN_DATA_DIALOG_H
#define LOGIN_DATA_DIALOG_H


#include <wx/wx.h>
#include <string>


class loginDataDialog : public wxDialog {
    public:
        
        loginDataDialog(const wxString& title);
        
    private:
        
        
        wxBoxSizer *sizer;
        
        
        
        wxStaticText *oldUserNameStatic;
        wxStaticText *newUserNameStatic;
        wxStaticText *oldPasswordStatic;
        wxStaticText *newPasswordStatic;
        wxStaticText *confirmPasswordStatic;
        
        
        
        wxTextCtrl *oldUserNameCtrl;
        wxTextCtrl *newUserNameCtrl;
        wxTextCtrl *oldPasswordCtrl;
        wxTextCtrl *newPasswordCtrl;
        wxTextCtrl *confirmPasswordCtrl;
        
        
        
        
        wxBoxSizer *buttonSizer;
        
        wxButton *saveButton;
        wxButton *cancelButton;
        
        
        void OnSave(wxCommandEvent& evt);
        void OnCancel(wxCommandEvent& evt);
        
        void LoadInformation();
        bool CheckOldInformation(const wxString& oldUserName, const wxString& oldPassword);
        void SaveInformation(const wxString& newUserName, const wxString& newPassword);
        
        static wxString GetLoginDataPath();
        
        
        
        void Binding();
        
};









#endif // LOGIN_DATA_DIALOG_H
