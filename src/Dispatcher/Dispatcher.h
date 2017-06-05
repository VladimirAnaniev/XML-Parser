#ifndef XML_PARSER_DISPATCHER_H
#define XML_PARSER_DISPATCHER_H

#include "Command/Command.h"

class Dispatcher {
    //Private constructor
    Dispatcher() {}

    /** Methods **/ //TODO: Transition them closer to the actual XML Tree
    //Prints the [key] argument of node with [id]
    static void select(String id, String key);

    //Sets the [key] argument of node with [id] to [value]
    static void set(String id, String key, String value);

    //Prints the [index]-th child of node with [id]
    static void child(String id, int index);

    //Prints all children of node with [id]
    static void children(String id);

    //Prints the text of node with [id]
    static void text(String id);

    //Deletes [key] argument of node wiht [id]
    static void del(String id, String key);

public:
    /** Methods **/
    //Dispatch a command
    static bool dispatch(Command c);

};


#endif //XML_PARSER_DISPATCHER_H
