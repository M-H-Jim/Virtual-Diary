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






#include "../include/virtualdiary.h"
#include "../include/mainframe.h"
#include "../include/login.h"



wxIMPLEMENT_APP(virtualDiary);

bool virtualDiary::OnInit() {
    
    loginDialog *login = new loginDialog("Login");
    login->Center();
    
    if(login->ShowModal() == wxID_OK) {
            
        mainFrame *frame = new mainFrame("Virtual Diary");
        SetTopWindow(frame);
        frame->SetClientSize(800, 600);
        frame->SetMinSize(wxSize(800, 600));
        frame->Show(true);
        delete login;
        
        return true;
    
    }
    delete login;

    return false;
}






