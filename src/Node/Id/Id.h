#ifndef XML_PARSER_ID_H
#define XML_PARSER_ID_H


#include "../Argument/Argument.h"

class Id : private Argument {

public:
    ////Constructor
    Id(String id = "");

    /** Methods **/
    String get() const;

    void set(String id);
};


#endif //XML_PARSER_ID_H
