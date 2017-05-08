#include "FileManager.h"
#include "../Console/Console.h"
#include "../Parser/Parser.h"

Console console;

void FileManager::open(String path) {
    if (this->isOpen) {
        console.writeLine("A file is already open, close it first before opening another.");
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
        console.writeLine(this->file.getPath() + " was closed.");
    } else console.writeLine("You cannot close when you haven't opened a file.");
}


void FileManager::save() {
    if (this->isOpen) {
        Parser parser;

        std::ofstream file(this->file.getPath());
        file.clear(); //Is this what i think?
        file << parser.nodeTreeToString(this->file.getParent());
        file.close();

        console.writeLine(this->file.getPath() + " was saved.");

        this->close();
    } else {
        console.writeLine("You cannot save when you haven't opened a file.");
    }
}

void FileManager::saveAs(String path) {
    this->file.setPath(path);
    this->save();
}

File& FileManager::getFile() {
    return this->file;
}


