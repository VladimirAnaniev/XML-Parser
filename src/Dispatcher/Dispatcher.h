#ifndef XML_PARSER_DISPATCHER_H
#define XML_PARSER_DISPATCHER_H

#include "Command/Command.h"

class Dispatcher {
    //Private constructor
    Dispatcher() {}

    /** Methods **/ //TODO: Transition them closer to the actual XML Tree
    static void select(String id, String key);

    static void set(String id, String key, String value);

    static void child(String id, int index);

    static void children(String id);

    static void text(String id);

    static void del(String id, String key);

public:
    /** Methods **/
    //Dispatch a command
    static bool dispatch(Command c);

};


#endif //XML_PARSER_DISPATCHER_H
