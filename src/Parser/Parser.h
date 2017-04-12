#ifndef XML_PARSER_PARSER_H
#define XML_PARSER_PARSER_H

#include "../Node/Node.h"

class Parser {

    //Recursive helper function for parsing Node Trees to Strings
    String nodeToStringRecursive(Node node, int depth) const;

    //Recursive helper function for parsing Strings to Node Trees
    Node stringToNodeRecursive(String str) const;

public:
    /** Methods **/
    //Checks if a given nodeTree is valid XML
    bool isValid(Node nodeTree) const;

    //Checks if a given string is valid XML
    bool isValid(String str) const;

    //Converts a string to a node tree
    Node stringToNodeTree(String str) const;

    //Converts a nodeTree to a string
    String nodeTreeToString(Node nodeTree) const;
};


#endif //XML_PARSER_PARSER_H
