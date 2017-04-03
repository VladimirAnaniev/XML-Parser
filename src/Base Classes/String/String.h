#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <fstream>

class String {
    char *str;
    int length;

    //Make the string double the size
    void resize(int newCells);

public:
    /** Constructors **/
    //Default constructor
    String(const char *str = "");

    //Copy constructor
    String(const String &string);

    //Desctuctor
    ~String();

    /** Methods **/
    //concatenates a string after the current value
    void concat(const char *str);

    //Returns the string as a char*
    const char *get() const;

    //Override the current string
    void set(const char *str);

    /** Operators **/
    //Concats two strings together and produces new String
    String operator+(const String &str) const;

    //Concats the new string onto this one
    String &operator+=(const String &str);

    //Assignment
    String &operator=(const String &str);

    //Compare strings
    bool operator==(const String &str) const;

    ////Parse to char* FROM STACKOVERFLOW
    operator const char *() const { return this->str; }

    //Get char at index
    const char operator[](int index) const;

};

//Input
std::ifstream &operator>>(std::ifstream &in, String str);

//Output
std::ostream &operator<<(std::ostream &out, String str);


#endif //XML_PARSER_STRING_H
