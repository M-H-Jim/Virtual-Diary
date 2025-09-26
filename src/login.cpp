#include "../include/login.h"



loginDialog::loginDialog(const wxString& title) : wxDialog(NULL, wxID_ANY, "Login", 
                                                           wxDefaultPosition, wxSize(600, 400), 
                                                           wxDEFAULT_DIALOG_STYLE & 
                                                           ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
                                                           
    
    sizer = new wxBoxSizer(wxVERTICAL);
    
    usernameStatic = new wxStaticText(this, wxID_ANY, "Username: ");
    usernameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    passwordStatic = new wxStaticText(this, wxID_ANY, "Password: ");
    passwordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    
    
    sizer->Add(usernameStatic, 0, wxALL, 5);
    sizer->Add(usernameCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(passwordStatic, 0, wxALL, 5);
    sizer->Add(passwordCtrl, 0, wxEXPAND | wxALL, 5);
    
    
    
    
    
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    
    
    
    
    loginButton = new wxButton(this, wxID_OK, "Login");
    cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
    
    
    buttonSizer->Add(loginButton, 1, wxALL, 5);
    buttonSizer->Add(cancelButton, 1, wxALL, 5);
    
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER);
    
    
    
    
    SetSizerAndFit(sizer);
    
    
    Binding();
    
}



wxString loginDialog::GetUsername() const {
    return usernameCtrl->GetValue();
}

wxString loginDialog::GetPassword() const {
    return passwordCtrl->GetValue();
}

void loginDialog::OnLogin(wxCommandEvent& evt) {
    
    if(GetUsername() == "f" && GetPassword() == "5") {
        EndModal(wxID_OK);
    }
    else {
        wxMessageBox("Invalid username or password", "Error", wxOK | wxICON_ERROR);
    }
    
}

void loginDialog::OnCancel(wxCommandEvent& evt) {
    EndModal(wxID_CANCEL);
}

void loginDialog::Binding() {
    loginButton->Bind(wxEVT_BUTTON, &loginDialog::OnLogin, this);
    cancelButton->Bind(wxEVT_BUTTON, &loginDialog::OnCancel, this);
}








