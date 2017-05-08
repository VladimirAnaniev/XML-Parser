#ifndef XML_PARSER_DISPATCHER_H
#define XML_PARSER_DISPATCHER_H


#include "Command/Command.h"

class Dispatcher {
public:
    ////Empty default constructor
    Dispatcher() {};

    /** Methods **/
    //Dispatch a command
    bool dispatch(Command c) const;

};


#endif //XML_PARSER_DISPATCHER_H
