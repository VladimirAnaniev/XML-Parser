#ifndef XML_PARSER_COMMAND_H
#define XML_PARSER_COMMAND_H

#include "../../Data Structures/String/String.h"

class Command {
    String action;
    List<String> arguments;
    List<String> optionals;
public:
    /** Constructors **/
    Command(List<String> input);

    /** Methods **/
    //Returns the action being requested
    String getAction() const;

    //Returns the arguments of the command if such exist
    List<String> getArguments() const;

    /** Operators **/
    bool operator==(String action) const;

};


#endif //XML_PARSER_COMMAND_H
