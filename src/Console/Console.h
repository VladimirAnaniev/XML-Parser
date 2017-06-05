#ifndef XML_PARSER_CONSOLE_H
#define XML_PARSER_CONSOLE_H

#include "../FileManager/FileManager.h"

class Console {
    //Private constructor
    Console() {}

    //reads from console, returns executeCommand(parseCommand(input));
    static bool readLine();

public:
    /** Methods **/
    //Listen for commands
    static void listen();

    //Write text on the console, then start a new line
    static void log(String str);
};


#endif //XML_PARSER_CONSOLE_H
