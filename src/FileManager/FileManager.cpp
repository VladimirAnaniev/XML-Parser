#include "FileManager.h"
#include "../Console/Console.h"
#include "../Parser/Parser.h"

#include "../Utils/Globals.h"
#include "../Utils/Exception.h"

using namespace Globals;

bool FileManager::open(String path) {
    if (this->isOpen) {
        Console::writeLine(ALREADY_OPEN);
        return false;
    }

    bool valid = this->file.setPath(path);
    if (!valid) {
        Console::writeLine(INVALID_PATH);
        return true;
    }

    this->file.parse();
    this->isOpen = true;

    Console::writeLine(OPENED_FILE + path);
    return true;
}

FileManager::FileManager() : isOpen(false) {}

bool FileManager::close() {
    if (this->isOpen) {
        this->isOpen = false;
        Console::writeLine(CLOSED_FILE + this->file.getPath());
        return true;
    }

    Console::writeLine(CANNOT_CLOSE);
    return false;
}


bool FileManager::save() {
    if (this->isOpen) {
        Parser parser;

        std::ofstream file;
        file.open(this->file.getPath(), std::ios_base::out | std::ios_base::trunc);
        file << parser.nodeTreeToString(this->file.getParent());
        file.close();

        Console::writeLine(SAVED_FILE + this->file.getPath());
        this->close();
        return true;
    }

    Console::writeLine(CANNOT_SAVE);
    return false;
}

bool FileManager::saveAs(String path) {
    this->file.setPath(path);

    return this->save();
}

File &FileManager::getFile() {
    if(this->isOpen) return this->file;

    //Throw error
    //What to return as default??
    throw Exception(NO_FILE);
}

bool FileManager::print() {
    if (this->isOpen) {
        Console::writeLine(this->file.getParent()->toString());
        return true;
    } else {
        Console::writeLine(CANNOT_PRINT);
        return false;
    }
}


