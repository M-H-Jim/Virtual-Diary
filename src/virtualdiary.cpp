#include "../include/virtualdiary.h"
#include "../include/mainframe.h"
#include "../include/login.h"





wxIMPLEMENT_APP(virtualDiary);

bool virtualDiary::OnInit() {
    
    loginDialog *login = new loginDialog("Login");
    
    if(login->ShowModal() == wxID_OK) {
            
        mainFrame *frame = new mainFrame("Virtual Diary");
        SetTopWindow(frame);
        frame->SetClientSize(800, 600);
        frame->Show(true);
        delete login;
        
        return true;
    
    }
    delete login;

    return false;
}






