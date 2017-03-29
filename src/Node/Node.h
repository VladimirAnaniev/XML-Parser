#ifndef XML_PARSER_NODE_H
#define XML_PARSER_NODE_H

#include "Argument/Argument.h"
#include "../String/String.h"

class Node {
    String tag;
    Node** children;
    Node* parent;
    Argument* args;

};


#endif //XML_PARSER_NODE_H
