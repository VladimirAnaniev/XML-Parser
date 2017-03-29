#ifndef XML_PARSER_CONSOLE_H
#define XML_PARSER_CONSOLE_H

#include "../FileManager/FileManager.h"

class Console {
    FileManager fm;

    //reads from console, returns executeCommand(parseCommand(input));
    short readLine();

    void invalidCommand();

public:
    /* Methods */
    //Listen for commands
    void listen();
};


#endif //XML_PARSER_CONSOLE_H
