#ifndef XML_PARSER_XML_NODE_H
#define XML_PARSER_XML_NODE_H


#include "../Data Structures/Tree/TreeNode.h"
#include "../Data Structures/String/String.h"
#include "Argument/Argument.h"

struct Data {
    String tag;
    String id;
    List<Argument> arguments;
    String content;
};

class XML_Node : public TreeNode, public Stringifiable {
    Data data;

public:

    /** Methods **/
    //Set this node's tag
    void setTag(String tag);

    //returns this node's tag
    String getTag() const;

    //Set this node's id
    void setId(String id);

    //Returns this node's id
    String getId() const;

    //Sets the text in this node's body
    void setContent(String content);

    //Returns the text in this node's body
    String getContent() const;

    //Add an argument to Arguments array
    void addArgument(Argument arg);

    //Remove argument at index from the Arguments array
    Argument removeArgument(int index);

    // returns this node's arguments
    List<Argument> &getArguments();

    //Find the Node with [id] if such exists
    XML_Node *findById(String id);

    //Parse to String
    String toString() override;
};


#endif //XML_PARSER_XML_NODE_H
