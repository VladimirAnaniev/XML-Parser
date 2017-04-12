#ifndef XML_PARSER_NODE_H
#define XML_PARSER_NODE_H

#include "Argument/Argument.h"
#include "../Base Classes/String/String.h"
#include "../Base Classes/Array/Array.h"

class Node {
    String tag;
    Array<Node *> children;
    Node *parent;
    Array<Argument> args;

public:
    /** Constructors **/
    Node();

    Node(const Node& node);

    /** Methods **/

    void addChild(Node child);

    Node removeChild(int index);

    void changeParent(Node *parent);

    void addArgument(Argument arg);

    Argument removeArgument(int index);

    void setTag(String tag);

    String getTag() const;

    Array<Node> &getChildren() const;

    Array<Argument> &getArguments() const;

    const Node *getParent() const;

    /** Operations **/

    Node& operator=(const Node& node);

    ////Destructor
    ~Node();
};


#endif //XML_PARSER_NODE_H
