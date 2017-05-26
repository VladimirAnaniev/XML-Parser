#include <cstring>
#include "Parser.h"

void Parser::validate(Node *nodeTree, Array<String> &ids) {
    if (ids.indexOf(nodeTree->getId()) >= 0 || nodeTree->getId() == String("")) {
        do {
            nodeTree->setId(Parser::generateUniqueId());
        } while (ids.indexOf(nodeTree->getId()) >= 0);
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

    result += String(' ', depth * 4) + "<" + node->getTag() + " id=\"" + node->getId() + "\"";
    Array<Argument> args = node->getArguments();
    for (int i = 0; i < args.getSize(); i++) {
        Argument argument = args[i];
        String arg = String(" ") + argument.getKey() + "=\"" + argument.getValue() + "\"";
        result += arg;
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

    Array<String> ids;
    Parser::validate(parent, ids);

    return parent;
}

Node *Parser::stringToNodeRecursive(String str) {
    Node *node = new Node;
    bool isOpened = false;

    str = str.substring(str.indexOf('<'), str.indexOfBackwards('>') + 1);

    //Find the index of the end of this node's declaration
    int delimIndex = str.indexOf('>') + 1;

    String thisNode = str.before(delimIndex); //All props of the node are in this part
    String rest = str.after(delimIndex);

    if (thisNode.beginsWith("<")) {
        thisNode = thisNode.after(1); //Remove the starting "<"

        if (thisNode.endsWith("/>")) {
            // No children or content
            thisNode = thisNode.before(thisNode.indexOf("/>"));
        } else {
            //Has children or content, mark it as open
            thisNode = thisNode.before(thisNode.getLength() - 1);
            isOpened = true;
        }

        Array<String> thisParts = thisNode.split(' '); //Split by intervals for access to all props
        String tag = thisParts.deleteAt(0); //Tag is always first

        /**Set node's parameters **/
        node->setTag(tag);

        for (int i = 0; i < thisParts.getSize(); i++) {
            //For each pair of arguments, split by '=' and add to args array
            Array<String> pair = thisParts[i].split('=');
            if (pair[1].beginsWith("\"") && pair[1].endsWith("\""))
                pair[1] = pair[1].substring(1, pair[1].getLength() - 1);

            if (strcmp(pair[0], "id") == 0) {
                node->setId(pair[1]);
            } else {
                node->addArgument(Argument(pair[0], pair[1]));
            }
        }

        if (isOpened) {
            //Opened, find end and call recursively for its children..
            rest = rest.before(rest.indexOf(String("</") + tag + ">"));

            //TODO: split into chunks and add all children
            node->addChild(Parser::stringToNodeRecursive(rest));

            //node->setContent(rest);
        }

    } else {
        //TODO: Throw error, Invalid File
    }

    return node;
}

String Parser::generateUniqueId() {
    return String::generateRandom(5) + "*";
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