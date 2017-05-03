#include "Parser.h"

bool Parser::isValid(Node nodeTree) const {
    //TODO: Check for unique Ids

    return false;
}

bool Parser::isValid(String str) const {
    //TODO

    return false;
}

String Parser::nodeTreeToString(Node nodeTree) const {
    String result = nodeToStringRecursive(nodeTree, 0);

    return result;
}

String Parser::nodeToStringRecursive(Node node, int depth) const {
    String result;

    result += String(' ', depth * 4) + "<" + node.getTag() + " ";
    Array<Argument> args = node.getArguments();
    for (int i = 0; i < args.getSize(); i++) {
        Argument argument = args[i];
        result += argument.getKey() + "=\"" + argument.getValue() + "\" ";
    }

    if (node.getChildren().getSize()) {
        result += ">\n";

        Array<Node *> children = node.getChildren();

        for (int i = 0; i < children.getSize(); i++) {
            result += nodeToStringRecursive(*children[i], depth + 1);
        }

        return result + "</" + node.getTag() + ">\n";
    }

    return result + "/>\n";
}

Node *Parser::stringToNodeTree(String str) const {
    if (!str.beginsWith("<?xml version=\"1.0\"?>")) {
        return nullptr; //TODO: Throw error
    }

    Node *parent;

    parent = stringToNodeRecursive(str.after(str.indexOf('>')));

    return parent;
}

Node *Parser::stringToNodeRecursive(String str) const {
    Node *node = new Node;

    //Set params and recursively set its children

    return node;
}