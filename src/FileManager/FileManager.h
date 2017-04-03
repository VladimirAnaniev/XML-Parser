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

    //Save the file at its current path
    bool save();

    //Save the file at a new path
    bool saveAs(String path);
};


#endif //XML_PARSER_FILEMANAGER_H
