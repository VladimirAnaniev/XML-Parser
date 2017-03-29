#ifndef XML_PARSER_FILEMANAGER_H
#define XML_PARSER_FILEMANAGER_H

#include "File/File.h"


class FileManager {
    bool isOpen;
    File file;

public:
    /** Methods **/
    bool openFile(String path);

    bool closeFile();

    bool save();

    bool saveAs(char *path);
};


#endif //XML_PARSER_FILEMANAGER_H
