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
