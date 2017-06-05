#ifndef XML_PARSER_ARGUMENT_H
#define XML_PARSER_ARGUMENT_H

#include "../../Data Structures/String/String.h"
#include "../../Data Structures/Pair/Pair.h"
#include "../../Interfaces/Stringifiable.h"

class Argument : public Pair<String, String>, public Stringifiable {
public:
    //// Constructor
    Argument(String key = "", String value = "");

    /** Methods **/
    String toString() override;
};


#endif //XML_PARSER_ARGUMENT_H
