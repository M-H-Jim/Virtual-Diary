#ifndef NOTE_H
#define NOTE_H

#include <wx/wx.h>


class Note {
    
        wxString title;
        wxString location;
        wxString date;
        wxString text;
        
    public:
            
        Note();
        Note(const wxString& t, const wxString& l, const wxString& d, const wxString& te);
        
        wxString GetFileName() const;
        
        bool Save(const wxString& folderPath) const;
        bool Load(const wxString& filePath);
        
        
        
        
        
};










#endif // NOTE_H
