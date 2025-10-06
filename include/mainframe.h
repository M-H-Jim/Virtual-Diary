#ifndef MAINFRAME_H
#define MAINFRAME_H



#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/splitter.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

class mainFrame : public wxFrame {
    
    public:
        
        mainFrame(const wxString& title);
    
    private:
        
        // MenuBar START
        
        wxMenu *menuFile;
        wxMenu *menuAbout;
        wxMenu *menuSettings;
        wxMenu *menuEdit;
        
        wxMenuBar *menuBar;
        
        // MenuBar END
        
        
        
        wxSplitterWindow* splitter;
        
        
        
        
        
        // Notebook START
        
        //for title
        wxStaticText *titleLabel;
        wxTextCtrl *titleCtrl;
        
        wxStaticText *locationLabel;
        wxTextCtrl *locationCtrl;
        
        wxStaticText *dateLabel;
        wxTextCtrl *dateCtrl;
        
        
        
        wxBoxSizer *titleBarSizer;
        
        
        wxRichTextCtrl *diaryText;
        
        
        
        
        
        wxListBox* notesList;
        
        
        
        
        wxAuiNotebook *noteBook;
        wxPanel *diaryPanel;
        wxPanel *phonebookPanel;
        
        
        
        
        
        
        
        
        void SetupDiaryUI(wxPanel *panel);
        void SetupPhonebookUI(wxPanel *panel);
        
        
        // Notebook END
        
        
        
        wxBoxSizer *sizer;
        

        
        
        void OnHello(wxCommandEvent& evt);
        void OnExit(wxCommandEvent& evt);
        void OnAbout(wxCommandEvent& evt);
        void OnChangeLoginData(wxCommandEvent& evt);
        
        
        
        
        
        wxString GetNotesFolderPath();
        void SaveNote(wxCommandEvent& evt);
        void LoadNotes();
        void OnNoteSelect(wxCommandEvent& evt);
        
        
        void Editable(wxCommandEvent& evt);
        
        
        void EditableDiary(wxCommandEvent& evt);
        void UneditableDiary();
        
        
        void OnTitleDoubleClick(wxMouseEvent& evt);
        void OnLocationDoubleClick(wxMouseEvent& evt);
        void OnDiaryDoubleClick(wxMouseEvent& evt);
        
        
        // Phonebook start
        
        
        wxSplitterWindow *phonebookSplitter;
        
        
        wxListBox *peopleList;
        
        
        
        
        
        // Phonebook end
        
        
        
        void Binding();
    
    
};






#endif // MAINFRAME_H
