#include "../include/virtualdiary.h"
#include "../include/mainframe.h"





wxIMPLEMENT_APP(virtualDiary);

bool virtualDiary::OnInit() {
    mainFrame *frame = new mainFrame("Virtual Diary");
    frame->SetClientSize(800, 600);
    frame->Show(true);
    
    return true;
}






