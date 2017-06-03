#include "XML_Node.h"


String XML_Node::getTag() const {
    return this->data.tag;
}

void XML_Node::addArgument(Argument arg) {
    this->data.arguments.push(arg);
}

List<Argument> XML_Node::getArguments() const {
    return this->data.arguments;
}

Argument XML_Node::removeArgument(int index) {
    return this->data.arguments.deleteAt(index);
}

void XML_Node::setTag(String tag) {
    this->data.tag.set(tag);
}

void XML_Node::setId(String id) {
    this->data.id.set(id);
}

String XML_Node::getId() const {
    return this->data.id;
}

void XML_Node::setContent(String content) {
    this->data.content = content;
}

String XML_Node::getContent() const {
    return this->data.content;
}

