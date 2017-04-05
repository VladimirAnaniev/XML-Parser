#ifndef XML_PARSER_NODE_H
#define XML_PARSER_NODE_H

#include "Argument/Argument.h"
#include "../Base Classes/String/String.h"
#include "../Base Classes/Array/Array.h"

class Node {
    String tag;
    Array<Node> children;
    Node *parent;
    Array<Argument> args;

public:
    /** Constructors **/
    //TODO

    /** Methods **/

    void addChild(Node child);

    Node removeChild(int index);

    void changeParent(Node *parent);

    void addArgument(Argument arg);

    Argument removeArgument(int index);

    void setTag(String tag);

    String getTag() const;

    Array<Node> &getChildren() const;

    Array<Node> &getArguments() const;

    const Node *getParent() const;

    ////Destructor
    //TODO
};


#endif //XML_PARSER_NODE_H
