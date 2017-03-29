#include "FileManager.h"

#include <fstream>

bool FileManager::openFile(String path) {
    if(this->isOpen) {
        //TODO: ERR
    } else {
        this->file.setPath(path);
        std::ifstream fs;
        fs.open(path);
        

    }
}