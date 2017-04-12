#ifndef XML_PARSER_CONSOLE_H
#define XML_PARSER_CONSOLE_H

#include "../FileManager/FileManager.h"

class Console {
    FileManager fm;

    //reads from console, returns executeCommand(parseCommand(input));
    short readLine();

    //Informs the user they entered an invalid command
    void invalidCommand();

public:
    /** Methods **/
    //Listen for commands
    void listen();

    //Write text on the console
    void write(String str);

    //Write text on the console, then start a new line
    void writeLine(String str);
};


#endif //XML_PARSER_CONSOLE_H
