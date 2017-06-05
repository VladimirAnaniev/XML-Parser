#ifndef XML_PARSER_FILEMANAGER_H
#define XML_PARSER_FILEMANAGER_H

#include "File/File.h"

class FileManager {
    static File *file;

    //Private Constructor
    FileManager() {}

public:
    /** Methods **/
    //Open a file and read its data
    static bool open(String path);

    //Close the file without saving
    static bool close();

    //Save the file at its current path
    static bool save();

    //Save the file at a new path
    static bool saveAs(String path);

    //Print the contents of the file on the console, formatted
    static bool print();

    // Returns the opened file
    static File &getFile();
};


#endif //XML_PARSER_FILEMANAGER_H
