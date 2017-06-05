#ifndef XML_PARSER_COMMAND_H
#define XML_PARSER_COMMAND_H

#include "../../Data Structures/String/String.h"

class Command {
    String action;
    List<String> arguments;
public:
    /** Constructors **/
    Command(List<String> input);

    /** Methods **/
    //Returns the action being requested
    String getAction() const;

    //Returns the arguments of the command if such exist
    List<String> getArguments() const;

    /** Operators **/
    //Compare to an action String
    bool operator==(String action) const;

};


#endif //XML_PARSER_COMMAND_H
