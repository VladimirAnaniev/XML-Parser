#ifndef XML_PARSER_XML_NODE_H
#define XML_PARSER_XML_NODE_H


#include "../Data Structures/Tree/TreeNode.h"
#include "../Data Structures/String/String.h"
#include "Argument/Argument.h"

struct Data {
    String tag;
    String id; //TODO: Id polymorphic class
    List<Argument> arguments;
    String content;

    bool operator==(const Data& data) {
        return false; //TODO
    }
};

class XML_Node : public TreeNode, public Stringifyable {
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
    List<Argument> getArguments() const;

    XML_Node *findById(String id);

    String toString() override;
};


#endif //XML_PARSER_XML_NODE_H
