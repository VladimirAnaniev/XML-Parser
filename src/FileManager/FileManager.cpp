#include "FileManager.h"
#include "../Console/Console.h"
#include "../Parser/Parser.h"

Console c;
Parser parser;

void FileManager::open(String path) {
    if (this->isOpen) {
        c.writeLine("A file is already open, close it first before opening another.");
    } else {
        this->file.setPath(path);
        this->file.parse();
        this->isOpen = true;
    }
}

FileManager::FileManager() : isOpen(false) {}

void FileManager::close() {
    if (this->isOpen) {
        this->isOpen = false;
        c.writeLine(this->file.getPath() + " was closed.");
    } else c.writeLine("You cannot close when you haven't opened a file.");
}


void FileManager::save() {
    if (this->isOpen) {
        std::ofstream file(this->file.getPath());
        file.clear(); //Is this what i think?
        file << parser.nodeTreeToString(this->file.getParent());
        file.close();

        c.writeLine(this->file.getPath() + " was saved.");

        this->close();
    } else {
        c.writeLine("You cannot save when you haven't opened a file.");
    }
}

void FileManager::saveAs(String path) {
    this->file.setPath(path);
    this->save();
}


