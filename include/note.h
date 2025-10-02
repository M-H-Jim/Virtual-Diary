#ifndef NOTE_H
#define NOTE_H

#include <wx/wx.h>


class Note {
    
        wxString title;
        wxString location;
        wxString date;
        wxString text;
        
    public:
        
        wxString GetT() { return title; }
        wxString GetL() { return location; }
        wxString GetD() { return date; }
        wxString GetText() { return text; }
        
            
        Note();
        Note(const wxString& t, const wxString& l, const wxString& d, const wxString& te);
        
        wxString GetFileName() const;
        
        bool Save(const wxString& folderPath) const;
        bool Load(const wxString& filePath);
        
        
        
        
        
};










#endif // NOTE_H
