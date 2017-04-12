#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <fstream>
#include "../Array/Array.h"

class String {
    char *str;
    int length;

    //Make the string double the size
    void resize(int newCells);

    //Adds a symbol for new line
    void newLine();

public:
    /** Constructors **/
    //Default constructor
    String(const char *str = "");

    //Copy constructor
    String(const String &string);

    //Repeat single char n times
    String(char c, int n);

    //Desctuctor
    ~String();

    /** Methods **/
    //concatenates a string after the current value
    void concat(const char *str);

    //Concats a string and adds a new line at the end
    void concatLine(const char* str);

    //Returns the string as a char*
    const char *get() const;

    //Override the current string
    void set(const char *str);

    //Split the string when given char is seen
    Array<String> split(char c = ' ') const;

    //Split the string when any of the given chars is seen
    Array<String> split(Array<char> delims) const;

    //Get a substring
    String substring(int start, int end) const;

    //Removes consecutive spaces
    String clearSpaces() const;

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
std::istream &operator>>(std::istream &in, String &str);

//Output
std::ostream &operator<<(std::ostream &out, String &str);

//Adding char* and String
String operator+(char* c, String str);




#endif //XML_PARSER_STRING_H
