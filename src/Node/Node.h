#ifndef XML_PARSER_NODE_H
#define XML_PARSER_NODE_H

#include "Argument/Argument.h"
#include "../Base Classes/String/String.h"
#include "../Base Classes/Array/Array.h"

class Node {
    String tag;
    Array<Node*> children;
    Node* parent;
    Argument* args;

};


#endif //XML_PARSER_NODE_H
