#ifndef XML_PARSER_TREENODE_H
#define XML_PARSER_TREENODE_H

#include "../Array/List.h"

class TreeNode {
private:
    TreeNode *parent;
    List<TreeNode *> children;

public:
    /** Constructors **/
    TreeNode();

    TreeNode(const TreeNode& treeNode);

    /** Methods **/
    TreeNode *getParent() const;

    List<TreeNode *> &getChildren();

    void setParent(TreeNode *parent);

    void addChild(TreeNode *child);

    TreeNode *removeChild(TreeNode *child);

    /** Operators **/
    TreeNode &operator=(const TreeNode &treeNode);


    ////Destructor
    virtual ~TreeNode();
};

#endif //XML_PARSER_TREENODE_H
