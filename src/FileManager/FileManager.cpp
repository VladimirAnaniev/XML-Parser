#include "FileManager.h"
#include "../Console/Console.h"
#include "../Utils/Globals.h"
#include "../Parser/Parser.h"
#include "../Utils/Exception.h"

using namespace Globals;

File *FileManager::file = nullptr;

File &FileManager::getFile() {
    if (file) return *file;

    throw Exception(NO_FILE);
}

bool FileManager::close() {
    if (file) {
        Console::writeLine(CLOSED_FILE + file->getPath());
        delete file;
        file = nullptr;
        return true;
    }

    Console::writeLine(CANNOT_CLOSE);
    return false;
}

bool FileManager::open(String path) {
    if (file) {
        Console::writeLine(ALREADY_OPEN);
        return false;
    }

    try {
        file = new File(path);
        Console::writeLine(OPENED_FILE + file->getPath());
        return true;
    } catch (Exception ex) {
        Console::writeLine(ex.what());
        return false;
    }
}

bool FileManager::save() {
    if (file) {
        std::ofstream f(file->getPath());
        f << Parser::nodeTreeToString(file->getParent());
        f.close();
        Console::writeLine(SAVED_FILE + file->getPath());
        return true;
    }

    Console::writeLine(CANNOT_SAVE);
    return false;
}

bool FileManager::saveAs(String path) {
    if (file) {
        file->setPath(path);
        FileManager::save();
        return true;
    }

    Console::writeLine(CANNOT_SAVE);
    return false;
}

bool FileManager::print() {
    if (file) {
        Console::writeLine(Parser::nodeTreeToString(file->getParent()));
        return true;
    }

    Console::writeLine(CANNOT_PRINT);
    return false;
}