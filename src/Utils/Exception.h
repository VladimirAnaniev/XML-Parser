#ifndef XML_PARSER_EXCEPTION_H
#define XML_PARSER_EXCEPTION_H

#include <stdexcept>
#include "../Data Structures/String/String.h"

class Exception : public std::exception {
    String message;
public:
    ////Constructor
    Exception(String message) : message(message) {};

    //Extract the message of the exception
    const char *what() const noexcept override {
        return message;
    }
};

#endif //XML_PARSER_EXCEPTION_H
