#ifndef XML_PARSER_PARSER_H
#define XML_PARSER_PARSER_H

#include "../XML Tree/XML_Node.h"

class Parser {
    //Private Constructor
    Parser() {}

    //Recursive helper function for parsing XML Tree Trees to Strings
    static String nodeToStringRecursive(XML_Node *node, int depth);

    //Recursive helper function for parsing Strings to XML Tree Trees
    static XML_Node *stringToNodeRecursive(String &str);

    //Converts an integer to a sting
    static String intToString(int n);

public:
    /** Methods **/
    //Checks if a given nodeTree is valid XML and places unique Ids
    static void validate(XML_Node *nodeTree, List<String> &ids);

    //Converts a string to a node tree
    static XML_Node *stringToNodeTree(String str);

    //Converts a nodeTree to a string
    static String nodeTreeToString(XML_Node *nodeTree);

    //Generates unique id
    static String generateUniqueId();


};


#endif //XML_PARSER_PARSER_H
