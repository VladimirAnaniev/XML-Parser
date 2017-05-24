#include <cstring>
#include "Parser.h"

void Parser::validate(Node *nodeTree, Array<String> &ids) {
    if (ids.indexOf(nodeTree->getId()) >= 0) {
        nodeTree->setId(Parser::generateUniqueId(nodeTree));
    }

    ids.push(nodeTree->getId());

    Array<Node *> children = nodeTree->getChildren();

    for (int i = 0; i < children.getSize(); i++) {
        Parser::validate(children[i], ids);
    }
}

String Parser::nodeTreeToString(Node *nodeTree) {
    String result = Parser::nodeToStringRecursive(nodeTree, 0);

    return result;
}

String Parser::nodeToStringRecursive(Node *node, int depth) {
    String result;

    result += String(' ', depth * 4) + "<" + node->getTag() + " ";
    Array<Argument> args = node->getArguments();
    for (int i = 0; i < args.getSize(); i++) { //TODO: ID
        Argument argument = args[i];
        result += argument.getKey() + "=\"" + argument.getValue() + "\" ";
    }

    if (node->getChildren().getSize() || node->getContent()) {
        result += ">\n";

        Array<Node *> children = node->getChildren();

        for (int i = 0; i < children.getSize(); i++) {
            result += Parser::nodeToStringRecursive(children[i], depth + 1);
        }

        result += node->getContent() + "\n";

        return result + "</" + node->getTag() + ">\n";
    }

    return result + "/>\n";
}

Node *Parser::stringToNodeTree(String str) {
    Node *parent = Parser::stringToNodeRecursive(str);

    return parent;
}

Node *Parser::stringToNodeRecursive(String str) {
    Node *node = new Node;

    //Find the index of the end of this node's declaration
    int delimIndex = str.indexOf('>');

    String thisNode = str.before(delimIndex); //All props of the node are in this part
    String rest = str.after(delimIndex);

    if (thisNode.beginsWith("<")) {
        thisNode = thisNode.after(1); //Remove the starting "<"

        Array<String> thisParts = thisNode.split(' '); //Split by intervals for access to all props

        String tag = thisParts.deleteAt(0);

        if (!thisNode.endsWith("/")) {
            //Opened, find end and call recursively for its children..
            //rest = rest.before(rest.indexOf("</" + tag + ">")); //TODO

            //TODO: split into chunks and call recursively for all children

            node->setContent(rest);
        }

        //Set node's parameters
        node->setTag(tag);

        for (int i = 0; i < thisParts.getSize(); i++) {
            Array<String> pair = thisParts[i].split('=');

            if(strcmp(pair[0], "id") == 0) {
                node->setId(pair[1]);
            } else {
                node->addArgument(Argument(pair[0], pair[1]));
            }
        }

    } else {
        //TODO: Throw error, Invalid File
    }

    return node;
}

String Parser::generateUniqueId(Node *node) {
    return node->getParent()->getId() + "_" +
           Parser::intToString(node->getParent()->getChildren().indexOf(node)) + "*";
    // The * indicates it is generated
}

String Parser::intToString(int n) {
    String str;

    while (n) {
        str.prepend((char) (n % 10) + '0');
        n /= 10;
    }

    return str;
}