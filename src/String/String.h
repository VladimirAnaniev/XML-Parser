#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <iostream>

class String {
    char *str;
    int length;

    //Make the string double the size
    void resize(int newCells);

public:
    /* Constructors */
    //Default constructor
    String(const char *str = "\0");

    //Copy constructor
    String(const String &string);

    //Desctuctor
    ~String();

    /* Methods */
    //concatenates a string after the current value
    void concat(const char *str);

    void concat(String str);

    //returns the string
    const char *get() const;

    void set(const char *str);

    /* Operators */
    //Concats two strings together and produces new String
    String operator+(const String &str) const;

    //Concats the new string onto this one
    String &operator+=(const String &str);

    //Assignment
    String &operator=(const String &str);

};

////Input
//std::istream &operator>>(std::istream &in, String str);

//Output
std::ostream &operator<<(std::ostream &out, String str);


#endif //XML_PARSER_STRING_H
