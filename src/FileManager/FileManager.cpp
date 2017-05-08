#include "FileManager.h"
#include "../Console/Console.h"
#include "../Parser/Parser.h"

#include "../Globals.h"

using namespace Globals;

bool FileManager::open(String path) {
    if (this->isOpen) {
        console.writeLine("A file is already open, close it first before opening another.");
        return false;
    }

    bool valid = this->file.setPath(path);
    if (!valid) {
        console.writeLine("Invalid file path, please try again.");
        return true;
    }

    this->file.parse();
    this->isOpen = true;

    console.writeLine("Successfully opened file: " + path);
    return true;
}

FileManager::FileManager() : isOpen(false) {}

bool FileManager::close() {
    if (this->isOpen) {
        this->isOpen = false;
        console.writeLine("File closed: " + this->file.getPath());
        return true;
    }

    console.writeLine("You cannot close when you haven't opened a file.");
    return false;
}


bool FileManager::save() {
    if (this->isOpen) {
        Parser parser;

        std::ofstream file;
        file.open(this->file.getPath(), std::ios_base::out | std::ios_base::trunc);
        file << parser.nodeTreeToString(this->file.getParent());
        file.close();

        console.writeLine("File saved: " + this->file.getPath());
        return true;
    }

    console.writeLine("You cannot save when you haven't opened a file.");
    return false;
}

bool FileManager::saveAs(String path) {
    this->file.setPath(path);

    return this->save();
}

//File &FileManager::getFile() {
//    if(this->isOpen) return this->file;
//
//    //Throw error
//    //What to return as default??
//}

bool FileManager::print() {
    if (this->isOpen) {
        console.writeLine(parser.nodeTreeToString(this->file.getParent()));
        return true;
    } else {
        console.writeLine("You cannot print when you haven't opened a file");
        return false;
    }
}


