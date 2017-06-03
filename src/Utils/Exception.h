#ifndef XML_PARSER_EXCEPTION_H
#define XML_PARSER_EXCEPTION_H

#include <stdexcept>
#include "../Data Structures/String/String.h"

class Exception : public std::exception {
    String message;
public:
    Exception(String message) : message(message) {};

    const char *what() const noexcept override {
        return message;
    }
};

#endif //XML_PARSER_EXCEPTION_H
