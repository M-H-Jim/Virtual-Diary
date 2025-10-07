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



#ifndef MAINFRAME_H
#define MAINFRAME_H



#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/splitter.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextstyles.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>


#include <wx/colour.h>
#include <wx/font.h>


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
        

        
        
        void OnExit(wxCommandEvent& evt);
        void OnAbout(wxCommandEvent& evt);
        void OnChangeLoginData(wxCommandEvent& evt);
        
        
        
        
        
        wxString GetNotesFolderPath();
        void SaveNote(wxCommandEvent& evt);
        void MoveFileToTrash(const wxString& filePath);
        void OnDeleteNote(wxCommandEvent& evt);
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
