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
    void open(String path);

    //Close the file without saving
    void close();

    //Save the file at its current path
    void save();

    //Save the file at a new path
    void saveAs(String path);

    File &getFile();
};


#endif //XML_PARSER_FILEMANAGER_H
