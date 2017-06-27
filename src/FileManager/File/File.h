#ifndef XML_PARSER_FILE_H
#define XML_PARSER_FILE_H

#include "../../XML Tree/XML_Node.h"
#include "../../Data Structures/String/String.h"

class File {
    String path;
    String data;
    XML_Node *root;

    //Change the data in the file
    void setData(String data);

public:
    ////Constructor
    File(String path);

    //Copy
    File(const File &file);

    /** Methods **/
    //Get the file's path
    String getPath() const;

    //get the file's data
    String getData() const;

    //get the file's XML Tree tree
    XML_Node *getParent() const;

    //Change the path of this file.
    void setPath(String path);

    //parse the data
    void parse();

    /** Operators **/
    File &operator=(const File &file);

    ////Destructor
    ~File();
};


#endif //XML_PARSER_FILE_H
