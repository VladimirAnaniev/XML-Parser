#ifndef XML_PARSER_FILE_H
#define XML_PARSER_FILE_H

#include "../../String/String.h"
#include "../../Node/Node.h"

class File {
    String path;
    String data;
    Node parent;

    //Change the path of this file.
    void setPath(String path);

    //Change the data in the file
    void setData(String data);

public:
    /** Methods **/
    //Get the file's path
    String getPath() const;

    //get the file's data
    String getData() const;

    //Open the file, parse the data and return if it is valid or not.
    bool parse(String path);
};


#endif //XML_PARSER_FILE_H
