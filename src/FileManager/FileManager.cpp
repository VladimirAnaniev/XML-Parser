#include "FileManager.h"

#include <fstream>
#include <iostream>


bool FileManager::open(String path) {
    if(this->isOpen) {
        //TODO: ERR
    } else {
        this->isOpen = this->file.parse(path);
    }
}

FileManager::FileManager(): isOpen(false) {
}