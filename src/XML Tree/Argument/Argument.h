#ifndef XML_PARSER_ARGUMENT_H
#define XML_PARSER_ARGUMENT_H

#include "../../Data Structures/String/String.h"
#include "../../Interfaces/Pair.h"

class Argument : public Pair<String, String> {
    String key;
    String value;

public:
    //// Constructor
    Argument(String key = "", String value = "");

    /** Methods **/
    String getKey() const;

    String getValue() const;

    void setKey(String key);

    void setValue(String value);
};


#endif //XML_PARSER_ARGUMENT_H
