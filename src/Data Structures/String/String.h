#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <fstream>
#include "../List/List.h"

class String {
    char *str;
    int length;
    int capacity;

    //Make the string double the size
    void resize();

    //Calculates the capacity of the string for a given length
    //Capacities are powers of 2
    static int calculateCapacity(int length);

public:
    /** Constructors **/
    //Default constructor
    String(const char *str = "");

    //Copy constructor
    String(const String &string);

    //Repeat single char n times
    String(char c, int n = 1);

    //Desctuctor
    ~String();

    /** Methods **/
    //concatenates a string after the current value
    void concat(const char *str);

    //Returns the string as a char*
    const char *get() const;

    //Override the current string
    void set(const char *str);

    //Split the string when given char is seen
    List<String> split(char c = ' ') const;

    //Split the string when any of the given chars is seen
    List<String> split(List<char> delims) const;

    //Get a substring
    String substring(int start, int end) const;

    //Get the substring after a given index;
    String after(int index) const;

    //Get the substring before a given index
    String before(int index) const;

    //Removes consecutive spaces
    String clearSpaces() const;

    //Checks if the string begins with a given string
    bool beginsWith(String str) const;

    //Checks if the string begins with a given string
    bool endsWith(String str) const;

    //Current string's length
    int getLength() const;

    //Get the first occurrence of a given character | -1 if not present
    int indexOf(char c) const;

    //Get the first occurrence of a given String | -1 if not present
    int indexOf(String str) const;

    //Concat a string at the beginning of another string
    void prepend(String str);

    //Return an array of all occurrences of a given character
    List<int> occurrencesOf(char c) const;

    //Generates a random string with given length
    static String generateRandom(int len);

    //Returns the index of the last occurrence of c
    int lastIndexOf(char c) const;

    //Remove spaces and new lines at start and end
    String trim() const;

    String toLower() const;

    /** Operators **/
    //Concats two strings together and produces new String
    String operator+(const String &str) const;

    //Concats the new string onto this one
    String &operator+=(const String &str);

    //Assignment
    String &operator=(const String &str);

    //Compare strings
    bool operator==(const String &str) const;

    //Parse to const char*
    operator const char *() const { return this->str; }

    //Convert a String to int
    explicit operator int() { return atoi(this->str); }

    //Get char at index
    const char operator[](int index) const;

};

//Input
std::istream &operator>>(std::istream &in, String &str);

//Output
std::ostream &operator<<(std::ostream &out, String &str);

//Adding char* and String
String operator+(char *c, String str);

#endif //XML_PARSER_STRING_H
