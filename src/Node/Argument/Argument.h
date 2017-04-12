#ifndef XML_PARSER_ARGUMENT_H
#define XML_PARSER_ARGUMENT_H

#include "../../Base Classes/String/String.h"

class Argument {
    String key;
    String value;

public:
    /** Methods **/
    String getKey() const;

    String getValue() const;

    void setKey(String key) const;

    void setValue(String key) const;
};


#endif //XML_PARSER_ARGUMENT_H
