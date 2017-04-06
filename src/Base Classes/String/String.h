#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <fstream>
#include "../Array/Array.h"

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

    Array<String> split(char c = ' ') const;

    String substring(int start, int end) const;

    /** Operators **/
    //Concats two strings together and produces new String
    String operator+(const String &str) const;

    //Concats the new string onto this one
    String &operator+=(const String &str);

    //Assignment
    String &operator=(const String &str);

    //Compare strings
    bool operator==(const String &str) const;

    //Parse to char*
    operator const char *() const { return this->str; }

    //Get char at index
    const char operator[](int index) const;

};

//Input
std::istream &operator>>(std::istream &in, String str);

//Output
std::ostream &operator<<(std::ostream &out, String str);


#endif //XML_PARSER_STRING_H
