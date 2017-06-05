#include <cstring>
#include "Parser.h"
#include "../Utils/Exception.h"
#include "../Utils/Globals.h"

using namespace Globals;

void Parser::validate(XML_Node *nodeTree, List<String> &ids) {
    if(nodeTree->getId() == String("")) {
        nodeTree->setId(Parser::generateUniqueId());
    }

    if (ids.indexOf(nodeTree->getId()) >= 0) {
        int i = 1;
        String oldId = nodeTree->getId();
        do {
            nodeTree->setId(oldId + "_" + intToString(i));
            i++;
        } while(ids.indexOf(nodeTree->getId()) >= 0);
    }

    ids.push(nodeTree->getId());

    List<TreeNode *> children = nodeTree->getChildren();

    for (int i = 0; i < children.getSize(); i++) {
        Parser::validate((XML_Node *) children[i], ids);
    }
}

String Parser::nodeTreeToString(XML_Node *nodeTree) {
    String result = Parser::nodeToStringRecursive(nodeTree, 0);

    return result;
}

String Parser::nodeToStringRecursive(XML_Node *node, int depth) {
    String result;
    String offset(' ', depth * 4); // Children are 4 spaces to the right compared to their parents

    //All elements have a tag and an id
    result += offset + "<" + node->getTag() + " id=\"" + node->getId() + "\"";

    List<Argument> args = node->getArguments();
    for (int i = 0; i < args.getSize(); i++) {
        //Add all arguments in format [key]="[value]"
        Argument argument = args[i];
        String arg = String(" ") + argument.getKey() + "=\"" + argument.getValue() + "\"";
        result += arg;
    }

    if (node->getChildren().getSize() || node->getContent().getLength()) {
        result += ">\n";

        List<TreeNode *> children = node->getChildren();
        for (int i = 0; i < children.getSize(); i++) {
            // Call recursively for each node's children
            result += Parser::nodeToStringRecursive((XML_Node *) children[i], depth + 1);
        }

        if (node->getContent().getLength()) {
            //Content should be printed with bigger offset, like children are
            result += offset + String(' ', 4) + node->getContent() + "\n";
        }

        return result + offset + "</" + node->getTag() + ">\n";
    }

    return result + "/>\n";
}

XML_Node *Parser::stringToNodeTree(String str) {
    XML_Node *parent = Parser::stringToNodeRecursive(str);

    //After parsing validate the created node tree
    //=> create unique ids where necessary
    List<String> ids;
    Parser::validate(parent, ids);

    return parent;
}

XML_Node *Parser::stringToNodeRecursive(String &str) {
    XML_Node *node = new XML_Node;
    bool isOpened = false;

    str = str.substring(str.indexOf('<'), str.lastIndexOf('>') + 1);

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

        List<String> thisParts = thisNode.split(' '); //Split by intervals for access to all props
        String tag = thisParts.deleteAt(0); //Tag is always first

        /**Set node's parameters **/
        node->setTag(tag);

        for (int i = 0; i < thisParts.getSize(); i++) {
            //For each pair of arguments, split by '=' and add to args array
            List<String> pair = thisParts[i].split('=');
            if (pair[1].beginsWith("\"") && pair[1].endsWith("\""))
                pair[1] = pair[1].substring(1, pair[1].getLength() - 1);

            if (strcmp(pair[0], "id") == 0) {
                node->setId(pair[1]);
            } else {
                node->addArgument(Argument(pair[0], pair[1]));
            }
        }

        /** Set Content or Children **/
        if (isOpened) {
            //Opened, find end and call recursively for its children..
            String closingTag = String("</") + tag + ">";
            String inside = rest.before(rest.indexOf(closingTag));

            //Set str to the string that remains so that the recursion can continue
            str = rest.after(rest.indexOf(String(closingTag)) + closingTag.getLength());

            if(inside.indexOf('<') >= 0) {
                //Has children -> parse them recursively
                while (inside.indexOf('<') >= 0) { //While there are opening tags, add as children
                    //Pass the inside as a parameter for the 'child' node
                    //After parsing it will change that to the remainder after it's closing tag
                    // that's why str was set to the remainder of the input string earlier
                    node->addChild(Parser::stringToNodeRecursive(inside));
                }
            } else {
                //No children -> Add the content
                node->setContent(inside.trim());
            }
        } else {
            // Same as earlier, in order for the elements after the current one to be parsed
            str = rest;
        }

    } else {
        throw Exception(INVALID_XML);
    }

    return node;
}

String Parser::generateUniqueId() {
    return String::generateRandom(3) + "*";
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