#ifndef XML_PARSER_COMMAND_H
#define XML_PARSER_COMMAND_H

#include "../../Base Classes/String/String.h"

class Command {
    String action;
    Array<String> arguments;
    Array<String> optionals;
public:
    /** Constructors **/
    Command(Array<String> input);

    /** Methods **/
    //Returns the action being requested
    String getAction() const;

    //Returns the arguments of the command if such exist
    Array<String> getArguments() const;

};


#endif //XML_PARSER_COMMAND_H
