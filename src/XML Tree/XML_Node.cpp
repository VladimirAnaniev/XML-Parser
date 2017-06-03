#include "XML_Node.h"
#include "../Parser/Parser.h"


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

XML_Node* XML_Node::findById(String id) {
    if(this->getId() == id) return this;

    List<TreeNode *> children = this->getChildren();

    for(int i=0;i<children.getSize(); i++) {
        XML_Node *result = ((XML_Node *) children[i])->findById(id);
        if(result != nullptr) return result;
    }

    return nullptr;
}

String XML_Node::toString() {
    return Parser::nodeTreeToString(this);
}

