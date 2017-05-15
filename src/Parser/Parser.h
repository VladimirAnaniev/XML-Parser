#ifndef XML_PARSER_PARSER_H
#define XML_PARSER_PARSER_H

#include "../Node/Node.h"

class Parser {

    //Recursive helper function for parsing Node Trees to Strings
    static String nodeToStringRecursive(Node *node, int depth);

    //Recursive helper function for parsing Strings to Node Trees
    static Node *stringToNodeRecursive(String str);

public:
    /** Methods **/
    //Checks if a given nodeTree is valid XML
    static bool isValid(Node *nodeTree, Array<String> ids);

    //Checks if a given string is valid XML
    static bool isValid(String str);

    //Converts a string to a node tree
    static Node *stringToNodeTree(String str);

    //Converts a nodeTree to a string
    static String nodeTreeToString(Node *nodeTree);
};


#endif //XML_PARSER_PARSER_H
