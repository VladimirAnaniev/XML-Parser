#ifndef XML_PARSER_DISPATCHER_H
#define XML_PARSER_DISPATCHER_H


#include "Command/Command.h"

class Dispatcher {

    static bool select(String id, String key);

    static bool set(String id, String key, String value);

public:
    /** Methods **/
    //Dispatch a command
    static bool dispatch(Command c);

};


#endif //XML_PARSER_DISPATCHER_H
