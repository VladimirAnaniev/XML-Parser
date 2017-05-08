#ifndef XML_PARSER_FILEMANAGER_H
#define XML_PARSER_FILEMANAGER_H

#include "File/File.h"

class FileManager {
    bool isOpen;
    File file;

public:
    /** Constructors **/
    FileManager();

    /** Methods **/
    //Open a file and read its data
    bool open(String path);

    //Close the file without saving
    bool close();

    //Save the file at its current path
    bool save();

    //Save the file at a new path
    bool saveAs(String path);

    //Print the contents of the file on the console, formatted
    bool print();

//    // Returns the opened file
//    File &getFile();
};


#endif //XML_PARSER_FILEMANAGER_H
