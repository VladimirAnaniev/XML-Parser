#ifndef XML_PARSER_GLOBALS
#define XML_PARSER_GLOBALS

#include "Data Structures/String/String.h"
#include "Console/Console.h"
#include "Dispatcher/Dispatcher.h"
#include "Parser/Parser.h"

namespace Globals {
    // Return codes
    static const short OK = 1;
    static const short BAD = 0;
    static const short END = -1;

    // Actions
    static const String OPEN = "open";
    static const String CLOSE = "close";
    static const String SAVE = "save";
    static const String AS = "as";
    static const String SAVE_AS = "save as";
    static const String PRINT = "print";

    static FileManager fileManager;

    //TODO: Add system console feedback
}

#endif //XML_PARSER_GLOBALS