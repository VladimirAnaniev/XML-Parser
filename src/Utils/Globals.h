#ifndef XML_PARSER_GLOBALS
#define XML_PARSER_GLOBALS

#include "../Data Structures/String/String.h"

namespace Globals {
    // Actions
    static const String OPEN = "open";
    static const String CLOSE = "close";
    static const String SAVE = "save";
    static const String SAVE_AS = "saveas";
    static const String PRINT = "print";
    static const String SELECT = "select";
    static const String SET = "set";
    static const String CHILDREN = "children";
    static const String CHILD = "child";
    static const String TEXT = "text";
    static const String DELETE = "delete";
    static const String REMOVE = "remove";
    static const String NEW_CHILD = "newchild";
    static const String XPATH = "xpath";
    static const String QUIT = "quit";

    //Feedback
    static const String INVALID_COMMAND = "Invalid command.";
    static const String NO_FILE = "No file is currently open. Please open a file and try again.";
    static const String ALREADY_OPEN = "You can have only one open file at a time. Please close the current one to open another.";
    static const String INVALID_PATH = "No such file found. Please check if the given path is valid and try again.";
    static const String OPENED_FILE = "Opened file: ";
    static const String CLOSED_FILE = "Closed file: ";
    static const String CANNOT_CLOSE = "You cannot close a file when you haven't opened one.";
    static const String SAVED_FILE = "Saved file: ";
    static const String CANNOT_SAVE = "You cannot close a file when you haven't opened one.";
    static const String CANNOT_PRINT = "You cannot print when you haven't opened a file.";
    static const String NO_SUCH_ARGUMENT = "No such argument exists.";
    static const String NO_SUCH_CHILD = "No such child exists.";
    static const String NO_CHILDREN = "This element has no children.";
    static const String DELETED = "Deleted: ";
    static const String REMOVED = "Removed element with id: ";
    static const String INVALID_XML = "Invalid XML file.";
    static const String NO_RRESULTS_XPATH = "Your XPath query returned no results.";
    static const String INVALID_INDEXES_EXCEPTION = "Invalid parameter indexes for function ";
}

#endif //XML_PARSER_GLOBALS