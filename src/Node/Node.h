#ifndef XML_PARSER_NODE_H
#define XML_PARSER_NODE_H

#include "Argument/Argument.h"
#include "../Base Classes/String/String.h"
#include "../Base Classes/Array/Array.h"

struct NodeData {
    String tag;
    String id;
    Array<Argument> args;
    String content;
};

class Node {
    NodeData data;
    Array<Node *> children;
    Node *parent;

    void copy(const Node& node);

    void setChildren(Array<Node *> children);

public:
    /** Constructors **/
    Node();

    Node(String str);

    Node(const Node& node);

    /** Methods **/

    void addChild(Node *child);

    Node *removeChild(int index);

    void changeParent(Node *parent);

    void addArgument(Argument arg);

    Argument removeArgument(int index);

    void setTag(String tag);

    String getTag() const;

    Array<Node *> getChildren() const;

    Array<Argument> getArguments() const;

    const Node *getParent() const;

    void setId(String id);

    String getId() const;

    void setContent(String content);

    String getContent() const;

    /** Operations **/

    Node& operator=(const Node& node);

    operator String();

    ////Destructor
    ~Node();
};


#endif //XML_PARSER_NODE_H
