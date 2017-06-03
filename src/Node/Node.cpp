#include "Node.h"
#include "../Parser/Parser.h"

Node::Node() {
    this->parent = nullptr;
}

Node::~Node() {
    this->destroy();
}

Node::Node(const Node &node) {
    this->parent = nullptr;
    this->copy(node);
}

List<Node *> Node::getChildren() const {
    return this->children;
}

String Node::getTag() const {
    return this->data.tag;
}

void Node::addArgument(Argument arg) {
    this->data.args.push(arg);
}

void Node::changeParent(Node *parent) {
    if (this->parent) {
        Node *p = this->parent;
        p->children.deleteAt(p->children.indexOf(this));
        if (p->children.isEmpty()) delete p;
    }

    this->parent = parent;
}

void Node::addChild(Node *child) {
    this->children.push(child);
    child->changeParent(this);
}

List<Argument> Node::getArguments() const {
    return this->data.args;
}

const Node *Node::getParent() const {
    return this->parent;
}

Node &Node::operator=(const Node &node) {
    this->copy(node);

    return *this;
}

Argument Node::removeArgument(int index) {
    return this->data.args.deleteAt(index);
}

Node *Node::removeChild(int index) {
    return this->children.deleteAt(index);
}

void Node::setTag(String tag) {
    this->data.tag.set(tag);
}

void Node::setId(String id) {
    this->data.id.set(id);
}

String Node::getId() const {
    return this->data.id;
}

void Node::copy(const Node &node) {
    this->data = node.data;
    this->changeParent(node.parent);
    this->setChildren(node.children);
}

void Node::setChildren(List<Node *> children) {
    this->children = children;

    for (int i = 0; i < children.getSize(); i++) {
        children[i]->changeParent(this);
    }
}

Node::Node(String str) {
    this->parent = nullptr;
    this->copy(*Parser::stringToNodeTree(str));
}

void Node::setContent(String content) {
    this->data.content = content;
}

String Node::getContent() const {
    return this->data.content;
}

Node::operator String() {
    return Parser::nodeTreeToString(this);
}

void Node::destroy() {
    for(int i=0;i<this->children.getSize();i++) {
        this->children[i]->destroy();
    }

    // remove this from its parents' children
    this->parent->removeChild(this->parent->children.indexOf(this));

    //delete this->parent; If we delete the parent we may lose the whole tree?
    //Someone should be holding the top of the tree so no need to worry?
}


