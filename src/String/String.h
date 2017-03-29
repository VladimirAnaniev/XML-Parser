#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H


class String {
    char *str;
    int length;
    int lastIndex;

    //Make the string double the size
    void resize();

public:
    /* Constructors */
    //Default constructor
    String(const char *str = "");

    //Copy constructor
    String(const String &string);

    //Desctuctor
    ~String();

    /* Methods */
    //concatenates a string after the current value
    void concat(const char *str);

    //returns the string
    const char *get() const;

    /* Operators */
    //Concats two strings together and produces new String
    String operator+(const String &str) const;

    //Concats the new string onto this one
    String &operator+=(const String &str);

    //Assignment
    String &operator=(const String &str);
};


#endif //XML_PARSER_STRING_H
