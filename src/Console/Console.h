#ifndef XML_PARSER_CONSOLE_H
#define XML_PARSER_CONSOLE_H

#include "../FileManager/FileManager.h"

class Console {
    //reads from console, returns executeCommand(parseCommand(input));
    bool readLine() const;

    //Informs the user they entered an invalid command
    void invalidCommand() const;

public:
    ////Empty default constructor
    Console() {};

    /** Methods **/
    //Listen for commands
    void listen() const;

    //Write text on the console
    void write(String str) const;

    //Write text on the console, then start a new line
    void writeLine(String str) const;
};


#endif //XML_PARSER_CONSOLE_H
