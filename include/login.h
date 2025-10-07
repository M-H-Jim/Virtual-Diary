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
