#include "TreeNode.h"

TreeNode *TreeNode::getParent() const {
    return this->parent;
}

List<TreeNode *> &TreeNode::getChildren() {
    return this->children;
}

void TreeNode::setParent(TreeNode *parent) {
    if (this->parent) {
        this->parent->removeChild(this);
    }

    this->parent = parent;
}

void TreeNode::addChild(TreeNode *child) {
    this->children.push(child);
    child->setParent(this);
}

TreeNode *TreeNode::removeChild(TreeNode *child) {
    return this->children.deleteAt(this->children.indexOf(child));
}

TreeNode::~TreeNode() {
    for (int i = 0; i < this->children.getSize(); i++) {
        delete this->children[i];
    }

    // remove this from its parents' children
    if (this->parent) {
        this->parent->removeChild(this);
    }
}

TreeNode::TreeNode() : parent(nullptr) {}

TreeNode::TreeNode(const TreeNode &treeNode) : parent(nullptr) {
    *this = treeNode;
}

TreeNode &TreeNode::operator=(const TreeNode &treeNode) {
    this->parent = treeNode.parent;
    this->children = treeNode.children;
    return *this;
}
