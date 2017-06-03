#ifndef XML_PARSER_STRINGIFYABLE_H
#define XML_PARSER_STRINGIFYABLE_H

#include "../Data Structures/String/String.h"

class Stringifiable {
public:
    virtual String toString() = 0;

    virtual operator String() { return this->toString(); }

    virtual ~Stringifiable() {}
};

#endif //XML_PARSER_STRINGIFYABLE_H
