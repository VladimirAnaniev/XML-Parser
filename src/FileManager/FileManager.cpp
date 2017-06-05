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
        Console::log(CLOSED_FILE + file->getPath());
        delete file;
        file = nullptr;
        return true;
    }

    Console::log(CANNOT_CLOSE);
    return false;
}

bool FileManager::open(String path) {
    if (file) {
        Console::log(ALREADY_OPEN);
        return false;
    }

    try {
        file = new File(path);
        Console::log(OPENED_FILE + file->getPath());
        return true;
    } catch (Exception ex) {
        Console::log(ex.what());
        return false;
    }
}

bool FileManager::save() {
    if (file) {
        std::ofstream f(file->getPath());
        f << Parser::nodeTreeToString(file->getParent());
        f.close();
        Console::log(SAVED_FILE + file->getPath());
        return true;
    }

    Console::log(CANNOT_SAVE);
    return false;
}

bool FileManager::saveAs(String path) {
    if (file) {
        file->setPath(path);
        FileManager::save();
        return true;
    }

    Console::log(CANNOT_SAVE);
    return false;
}

bool FileManager::print() {
    if (file) {
        Console::log(Parser::nodeTreeToString(file->getParent()));
        return true;
    }

    Console::log(CANNOT_PRINT);
    return false;
}