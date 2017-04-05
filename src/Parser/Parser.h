#ifndef XML_PARSER_PARSER_H
#define XML_PARSER_PARSER_H

#include "../Node/Node.h"

class Parser {
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
