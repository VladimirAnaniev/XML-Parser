#ifndef XML_PARSER_STRINGIFYABLE_H
#define XML_PARSER_STRINGIFYABLE_H

#include "../Data Structures/String/String.h"

class Stringifiable {
public:
    //Converts the object to String
    virtual String toString() = 0;

    //Operator for casting to String
    virtual operator String() { return this->toString(); }

    ////Virtual destructor
    virtual ~Stringifiable() {}
};

#endif //XML_PARSER_STRINGIFYABLE_H
