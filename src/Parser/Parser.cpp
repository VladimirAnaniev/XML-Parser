#include "Parser.h"

bool Parser::isValid(Node *nodeTree, Array<String> ids) {
    if(ids.indexOf(nodeTree->getId()) >= 0) {
        //Id is not unique
        return false;
    } else {
        ids.push(nodeTree->getId());

        Array<Node*> children = nodeTree->getChildren();

        for(int i=0;i<children.getSize();i++) {
            if(!Parser::isValid(children[i], ids)) {
                return false;
            }
        }
    }

    return true;
}

bool Parser::isValid(String str) {
    return Parser::isValid(Parser::stringToNodeTree(str), Array<String>());
}

String Parser::nodeTreeToString(Node *nodeTree) {
    String result = Parser::nodeToStringRecursive(nodeTree, 0);

    return result;
}

String Parser::nodeToStringRecursive(Node *node, int depth) {
    String result;

    result += String(' ', depth * 4) + "<" + node->getTag() + " ";
    Array<Argument> args = node->getArguments();
    for (int i = 0; i < args.getSize(); i++) {
        Argument argument = args[i];
        result += argument.getKey() + "=\"" + argument.getValue() + "\" ";
    }

    if (node->getChildren().getSize()) {
        result += ">\n";

        Array<Node *> children = node->getChildren();

        for (int i = 0; i < children.getSize(); i++) {
            result += Parser::nodeToStringRecursive(children[i], depth + 1);
        }

        return result + "</" + node->getTag() + ">\n";
    }

    return result + "/>\n";
}

Node *Parser::stringToNodeTree(String str) {
    if (!str.beginsWith("<?xml version=\"1.0\"?>")) {
        return nullptr; //TODO: Throw error
    }

    Node *parent;

    parent = Parser::stringToNodeRecursive(str.after(str.indexOf('>')));

    return parent;
}

Node *Parser::stringToNodeRecursive(String str) {
    Node *node = new Node;

    //Find the index of the end of this node's declaration
    int delimIndex = str.indexOf('>') + 1;

    String thisNode = str.before(delimIndex); //All props of the node are in this part
    String rest = str.after(delimIndex);

    if (thisNode.beginsWith("<")) {
        thisNode = thisNode.after(1); //Remove the starting "<"

        Array<String> thisParts = thisNode.split(' '); //Split by intervals for access to all props

        String tag = thisParts[0];

        if(thisNode.endsWith("/>")) {
            //No children, closed

            node->setTag(tag);

        } else {
            //Opened, find end and call recursively for its children..
            rest = rest.before(rest.indexOf("</"+tag+">"));

            //TODO: split into chunks and call recursively for all children



        }

    } else {
        //TODO: Throw error, Invalid File
    }

    return node;
}