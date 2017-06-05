#ifndef XML_PARSER_CONSOLE_H
#define XML_PARSER_CONSOLE_H

#include "../FileManager/FileManager.h"

class Console {
    
    Console() {}

    //reads from console, returns executeCommand(parseCommand(input));
    static bool readLine();

    //Informs the user they entered an invalid command
    static void invalidCommand();

public:
    /** Methods **/
    //Listen for commands
    static void listen();

    //Write text on the console
    static void write(String str);

    //Write text on the console, then start a new line
    static void writeLine(String str);
};


#endif //XML_PARSER_CONSOLE_H
