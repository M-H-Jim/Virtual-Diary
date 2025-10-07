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












