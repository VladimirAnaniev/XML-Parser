#ifndef XML_PARSER_FILE_H
#define XML_PARSER_FILE_H


class File {
    char *path;
    char *data;

public:
    /* Constructors */
    //Default constructor & Constructor with parameters
    File(const char* path = "", const char* data = "");

    File(const File& file);

    //Destructor
    ~File();

    /* Methods */
    //Change the path of this file.
    void setPath(const char *path);

    //Change the data in the file
    void setData(const char *data);

    //Get the file's path
    const char *getPath() const;

    //get the file's data
    const char *getData() const;
};


#endif //XML_PARSER_FILE_H
