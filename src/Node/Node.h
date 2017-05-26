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

    // Copy helper
    void copy(const Node& node);

    // Set children
    void setChildren(Array<Node *> children);

    //Destroy this and its children recursively
    void destroy();

public:
    /** Constructors **/
    // Default
    Node();

    // Parse string to Node tree
    Node(String str);

    // Copy
    Node(const Node& node);

    /** Methods **/

    //Addds new child in children array
    void addChild(Node *child);

    //Removes child at index from the children array
    Node *removeChild(int index);

    //Change the parent of this node
    //Removes this node from parent's children
    //If parent has no children left, deletes it
    void changeParent(Node *parent);

    //Add an argument to Arguments array
    void addArgument(Argument arg);

    //Remove argument at index from the Arguments array
    Argument removeArgument(int index);

    //Set this node's tag
    void setTag(String tag);

    //returns this node's tag
    String getTag() const;

    //Get this node's children
    Array<Node *> getChildren() const;

    // returns this node's arguments
    Array<Argument> getArguments() const;

    //Returns a pointer to this node's parent
    const Node *getParent() const;

    //Set this node's id
    void setId(String id);

    //Returns this node's id
    String getId() const;

    //Sets the text in this node's body
    void setContent(String content);

    //Returns the text in this node's body
    String getContent() const;

    /** Operations **/

    //Assignment
    Node& operator=(const Node& node);

    //Convert to String
    operator String();

    ////Destructor
    ~Node();
};


#endif //XML_PARSER_NODE_H
