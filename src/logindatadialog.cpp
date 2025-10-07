/* 
 * Copyright (C) 2025 M.H.Jim
 *
 * This file is part of Virtual Diary.
 *
 * Virtual Diary is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Virtual Diary is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Virtual Diary; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */








#include "../include/logindatadialog.h"


#include <fstream>
#include <wx/stdpaths.h>
#include <wx/filename.h>


enum {
    ID_SAVE = wxID_HIGHEST + 1,
    ID_CANCEL
};


loginDataDialog::loginDataDialog(const wxString& title) : wxDialog(NULL, wxID_ANY, title, 
                                                                  wxDefaultPosition, 
                                                                  wxSize(600, 500)) {
                                                                    
    sizer = new wxBoxSizer(wxVERTICAL);
    
    oldUserNameStatic = new wxStaticText(this, wxID_ANY, "Old Username: ");
    newUserNameStatic = new wxStaticText(this, wxID_ANY, "New Username: ");
    oldPasswordStatic = new wxStaticText(this, wxID_ANY, "Old Password: ");
    newPasswordStatic = new wxStaticText(this, wxID_ANY, "New Password: ");
    confirmPasswordStatic = new wxStaticText(this, wxID_ANY, "Confirm Password: ");
    
    
    oldUserNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    newUserNameCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    oldPasswordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    newPasswordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    confirmPasswordCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    
    
    
    
    
    
    
    
    sizer->Add(oldUserNameStatic, 0, wxALL, 5);
    sizer->Add(oldUserNameCtrl, 0, wxEXPAND | wxALL, 5);
    
    sizer->Add(newUserNameStatic, 0, wxALL, 5);
    sizer->Add(newUserNameCtrl, 0, wxEXPAND | wxALL, 5);
    
    
    
    sizer->Add(oldPasswordStatic, 0, wxALL, 5);
    sizer->Add(oldPasswordCtrl, 0, wxEXPAND | wxALL, 5);
    
    sizer->Add(newPasswordStatic, 0, wxALL, 5);
    sizer->Add(newPasswordCtrl, 0, wxEXPAND | wxALL, 5);
    
    sizer->Add(confirmPasswordStatic, 0, wxALL, 5);
    sizer->Add(confirmPasswordCtrl, 0, wxEXPAND | wxALL, 5);
    
    
    
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    saveButton = new wxButton(this, ID_SAVE, "Save");
    cancelButton = new wxButton(this, ID_CANCEL, "Cancel");
    
    buttonSizer->Add(saveButton, 1, wxALL, 5);
    buttonSizer->Add(cancelButton, 1, wxALL, 5);
    
    
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER);
    
    SetSizer(sizer);
    
    
    LoadInformation();
    
    Binding();
    
    
}


void loginDataDialog::OnSave(wxCommandEvent& evt) {
    
    wxString oldUserName = oldUserNameCtrl->GetValue();
    wxString newUserName = newUserNameCtrl->GetValue();
    wxString oldPassword = oldPasswordCtrl->GetValue();
    wxString newPassword = newPasswordCtrl->GetValue();
    wxString confirmPassword = confirmPasswordCtrl->GetValue();
    
    
    if(!CheckOldInformation(oldUserName, oldPassword)) {
        wxMessageBox("Old username or password is incorrect.", "Error", wxOK | wxICON_ERROR);
        return;
    }
    
    if(newPassword != confirmPassword) {
        wxMessageBox("New password and confirmation do not match.", "Error", wxOK | wxICON_ERROR);
        return;
    }
    
    SaveInformation(newUserName, newPassword);
    
    wxMessageBox("Login data updated successfully!", "Success", wxOK | wxICON_INFORMATION);
    
    EndModal(wxID_OK);
  
}

void loginDataDialog::OnCancel(wxCommandEvent& evt) {
    EndModal(wxID_CANCEL);
}


void loginDataDialog::LoadInformation() {
    
    std::ifstream file(GetLoginDataPath().ToStdString());
    
    if(file.is_open()) {
        
        std::string username, password;
        std::getline(file, username);
        std::getline(file, password);
        
        oldUserNameCtrl->SetValue(username);
        oldPasswordCtrl->SetValue(password);
        
        file.close();
    }
    else wxMessageBox("could not open", "Error");
}




bool loginDataDialog::CheckOldInformation(const wxString& oldUsername, const wxString& oldPassword) {
    
    std::ifstream file(GetLoginDataPath().ToStdString());
    if(!file.is_open()) return false;
    
    std::string storedUserName, storedPassword;
    std::getline(file, storedUserName);
    std::getline(file, storedPassword);
    
    file.close();
    
    return (oldUsername.ToStdString() == storedUserName && oldPassword.ToStdString() == storedPassword);
}

void loginDataDialog::SaveInformation(const wxString& newUserName, const wxString& newPassword) {
    std::ofstream file(GetLoginDataPath().ToStdString());
    if(file.is_open()) {
        file << newUserName.ToStdString() << std::endl;
        file << newPassword.ToStdString() << std::endl;
        file.close();
    }
}


void loginDataDialog::Binding() {
    Bind(wxEVT_BUTTON, &loginDataDialog::OnCancel, this, ID_CANCEL);
    Bind(wxEVT_BUTTON, &loginDataDialog::OnSave, this, ID_SAVE);
    
}



wxString loginDataDialog::GetLoginDataPath() {
    
    wxString exeDir = wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetPath();

    wxFileName fileName(exeDir, "logindata.txt");
    fileName.AppendDir("info");
    
    return fileName.GetFullPath();
    
}











