#include "Node.h"

Node::Node() {
    this->parent = nullptr;
}

Node::~Node() {
    delete[] this->parent;
}