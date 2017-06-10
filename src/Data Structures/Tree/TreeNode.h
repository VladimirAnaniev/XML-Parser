#ifndef XML_PARSER_TREENODE_H
#define XML_PARSER_TREENODE_H

#include "../List/List.h"

class TreeNode {
private:
    TreeNode *parent;
    List<TreeNode *> children;

public:
    /** Constructors **/
    //Default
    TreeNode();

    //Copy Constructor
    TreeNode(const TreeNode& treeNode);

    /** Methods **/
    //Returns the parent Node
    TreeNode *getParent() const;

    //Returns a list of all children
    List<TreeNode *> &getChildren();

    //Change the parent Node
    void setParent(TreeNode *parent);

    //Add a child
    void addChild(TreeNode *child);

    //Remove a child
    TreeNode *removeChild(TreeNode *child);

    /** Operators **/
    //Assignment
    TreeNode &operator=(const TreeNode &treeNode);

    ////Destructor
    virtual ~TreeNode();
};

#endif //XML_PARSER_TREENODE_H
