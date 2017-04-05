#include "FileManager.h"

#include <fstream>
#include <iostream>
#include <functional>


void FileManager::open(String path) {
    if (this->isOpen) {
        std::cout << "A file is already open, close it first before opening another." << std::endl;
    } else {
        this->isOpen = this->file.parse(path);
    }
}

FileManager::FileManager() : isOpen(false) {}

void FileManager::close() {
    if (this->isOpen) this->isOpen = false;
    else std::cout << "You cannot close when you haven't opened a file" << std::endl;
}

