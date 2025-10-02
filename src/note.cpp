#include "../include/note.h"



#include <fstream>



Note::Note() {}

Note::Note(const wxString& t, const wxString& l, const wxString& d, const wxString& te) :
    title(t), location(l), date(d), text(te) {};



wxString Note::GetFileName() const {
    wxString formattedTitle = title;
    formattedTitle.Replace(" ", "_");
    return date + "_" + formattedTitle + ".txt";
}


bool Note::Save(const wxString& folderPath) const {
    wxString filePath = folderPath + "/" + GetFileName();
    
    std::ofstream file(filePath.ToStdString());
    if(!file.is_open()) return false;
    
    file << title.ToStdString() << std::endl;
    file << location.ToStdString() << std::endl;
    file << date.ToStdString() << std::endl;
    file << text.ToStdString() << std::endl;
    
    file.close();
    
    return true;
    
}


bool Note::Load(const wxString& filePath) {
    std::ifstream file(filePath.ToStdString());
    if(!file.is_open()) return false;
    
    std::string line, body;
    
    std::getline(file, line);
    title = wxString(line);
    
    std::getline(file, line);
    location = wxString(line);
    
    std::getline(file, line);
    date = wxString(line);
    
    
    while(std::getline(file, line)) {
        body += line + "\n";
    }
    text = wxString(body);
    
    return true;
}






















