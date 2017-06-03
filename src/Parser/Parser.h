#ifndef XML_PARSER_PARSER_H
#define XML_PARSER_PARSER_H

#include "../Node/Node.h"

class Parser {

    //Recursive helper function for parsing Node Trees to Strings
    static String nodeToStringRecursive(Node *node, int depth);

    //Recursive helper function for parsing Strings to Node Trees
    static Node *stringToNodeRecursive(String &str);

    //Converts an integer to a sting
    static String intToString(int n);

public:
    /** Methods **/
    //Checks if a given nodeTree is valid XML and places unique Ids
    static void validate(Node *nodeTree, List<String> &ids);

    //Converts a string to a node tree
    static Node *stringToNodeTree(String str);

    //Converts a nodeTree to a string
    static String nodeTreeToString(Node *nodeTree);

    //Generates unique id
    static String generateUniqueId();


};


#endif //XML_PARSER_PARSER_H
