#include "Node.h"

Node::Node() {
    this->parent = nullptr;
}

Node::~Node() {
    delete[] this->parent;
}

Node::Node(const Node &node) {
    //TODO
}

Array<Node *> Node::getChildren() const {
    return this->children;
}

String Node::getTag() const {
    return this->tag;
}

void Node::addArgument(Argument arg) {
    //TODO
}

void Node::changeParent(Node *parent) {

    //TODO: delete this->parent; If nothing points to it
    this->parent = parent;
}

void Node::addChild(Node child) {
    //TODO
}

Array<Argument> Node::getArguments() const {
    return this->args;
}

const Node* Node::getParent() const {
    return this->parent;
}

Node& Node::operator=(const Node &node) {
    //TODO

    return *this;
}

Argument Node::removeArgument(int index) {
    //TODO
}

Node Node::removeChild(int index) {
    //TODO
}

void Node::setTag(String tag) {
    this->tag = tag;
}



