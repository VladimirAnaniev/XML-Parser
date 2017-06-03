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

    List<TreeNode *> getChildren() const;

    void setParent(TreeNode *parent);

    void addChild(TreeNode *child);

    TreeNode *removeChild(TreeNode *child);

    TreeNode *depthSearch(TreeNode *node);

    TreeNode *breadthSearch(TreeNode *node);

    /** Operators **/
    TreeNode &operator=(const TreeNode &treeNode);


    ////Destructor
    virtual ~TreeNode();
};

#endif //XML_PARSER_TREENODE_H
