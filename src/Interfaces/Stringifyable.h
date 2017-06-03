#ifndef XML_PARSER_STRINGIFYABLE_H
#define XML_PARSER_STRINGIFYABLE_H

#include "../Data Structures/String/String.h"

class Stringifyable {
public:
    virtual String toString() = 0;

    operator String() { return this->toString(); }

    virtual ~Stringifyable() {}
};

#endif //XML_PARSER_STRINGIFYABLE_H
