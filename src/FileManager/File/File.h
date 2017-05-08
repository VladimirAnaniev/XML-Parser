#ifndef XML_PARSER_FILE_H
#define XML_PARSER_FILE_H

#include "../../Node/Node.h"
#include "../../Base Classes/String/String.h"

class File {
    String path;
    String data;
    Node *parent;

    //Change the data in the file
    void setData(String data);

    //Checks if the current path is valid
    bool isValid() const;

public:
    /** Methods **/
    //Get the file's path
    String getPath() const;

    //get the file's data
    String getData() const;

    //get the file's Node tree
    Node *getParent() const;

    //Change the path of this file.
    bool setPath(String path);

    //parse the data
    void parse();
};


#endif //XML_PARSER_FILE_H
