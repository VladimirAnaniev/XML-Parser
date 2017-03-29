#ifndef XML_PARSER_FILE_H
#define XML_PARSER_FILE_H


#include "../../String/String.h"

class File {
    String path;
    String data;

public:
    /* Constructors */
    //Default constructor
    File();

    //Constructor with ith parameters
    File(String path, String data);

    //Copy constructor
    File(const File &file);

    //Destructor
    ~File();

    /* Methods */
    //Change the path of this file.
    void setPath(String path);

    //Change the data in the file
    void setData(String data);

    //Get the file's path
    String getPath() const;

    //get the file's data
    String getData() const;
};


#endif //XML_PARSER_FILE_H
