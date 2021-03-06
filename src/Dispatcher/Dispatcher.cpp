#include "Dispatcher.h"

#include "../Utils/Globals.h"
#include "../Utils/Exception.h"
#include "../FileManager/FileManager.h"
#include "../Console/Console.h"
#include "../XPath/XPath.h"

using namespace Globals;

bool Dispatcher::dispatch(Command command) {
    List<String> args = command.getArguments();

    if (command == OPEN) {
        FileManager::open(args[0]);
    } else if (command == CLOSE) {
        FileManager::close();
    } else if (command == SAVE) {
        FileManager::save();
    } else if (command == SAVE_AS) {
        FileManager::saveAs(args[0]);
    } else if (command == PRINT) {
        FileManager::print();
    } else if (command == SELECT) {
        Dispatcher::select(args[0], args[1]);
    } else if (command == SET) {
        Dispatcher::set(args[0], args[1], args[2]);
    } else if (command == CHILD) {
        Dispatcher::child(args[0], (int) args[1]);
    } else if (command == CHILDREN) {
        Dispatcher::children(args[0]);
    } else if (command == TEXT) {
        Dispatcher::text(args[0]);
    } else if (command == DELETE) {
        Dispatcher::del(args[0], args[1]);
    } else if (command == REMOVE) {
        Dispatcher::remove(args[0]);
    } else if (command == SET_ID) {
        Dispatcher::setId(args[0], args[1]);
    } else if (command == NEW_CHILD) {
        Dispatcher::newChild(args[0], args[1], args[2]);
    } /*else if (command == XPATH) {
        Dispatcher::xpath(args[0], args[1]);
    }*/ else if (command == QUIT) {
        return false;
    } else {
        Console::log(INVALID_COMMAND);
    }

    return true;
}

XML_Node *findNodeById(String id) {
    try {
        return FileManager::getFile().getParent()->findById(id);
    } catch (Exception ex) {
        Console::log(ex.what());
    }
    return nullptr;
}

void Dispatcher::select(String id, String key) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    List<Argument> &nodeArgs = node->getArguments();

    for (int i = 0; i < nodeArgs.getSize(); i++) {
        if (nodeArgs[i].getKey() == key) {
            Console::log(nodeArgs[i]);
            return;
        }
    }

    Console::log(NO_SUCH_ARGUMENT);
}

void Dispatcher::set(String id, String key, String value) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }
    if(key == String("id")) {
        Console::log(USE_SETID);
        return;
    }

    List<Argument> &nodeArgs = node->getArguments();

    for (int i = 0; i < nodeArgs.getSize(); i++) {
        if (nodeArgs[i].getKey() == key) {
            nodeArgs[i].setValue(value);
            Console::log(nodeArgs[i]);
            return;
        }
    }

    nodeArgs.push(Argument(key, value));
    Console::log(nodeArgs[nodeArgs.getSize() - 1]);
}

void Dispatcher::child(String id, int index) {
    XML_Node *node = findNodeById(id);

    if (!node || node->getChildren().getSize() <= index) {
        Console::log(NO_SUCH_ELEMENT);
    } else {
        Console::log(((XML_Node *) node->getChildren()[index])->toString());
    }
}

void Dispatcher::children(String id) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    for (int i = 0; i < node->getChildren().getSize(); i++) {
        Console::log(((XML_Node *) node->getChildren()[i])->toString());
    }

    if (node->getChildren().getSize() < 1) {
        Console::log(NO_CHILDREN);
    }
}

void Dispatcher::text(String id) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    Console::log(node->getContent());
}

void Dispatcher::del(String id, String key) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    List<Argument> &args = node->getArguments();

    for (int i = 0; i < args.getSize(); i++) {
        if (args[i].getKey() == key) {
            Console::log(DELETED + args.deleteAt(i));
            return;
        }
    }

    Console::log(NO_SUCH_ARGUMENT);
}

void Dispatcher::remove(String id) {
    XML_Node *node = findNodeById(id);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    delete node;

    Console::log(REMOVED + id);
}

void Dispatcher::setId(String oldId, String newId) {
    if(newId.getLength() <= 0) {
        Console::log(SPECIFY_ID);
        return;
    }

    XML_Node *node = findNodeById(oldId);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    node->setId(newId);
    Console::log("id=\""+newId+"\"");
}

void Dispatcher::newChild(String parentId, String tag, String id) {
    //TODO: Check if id is unique

    XML_Node *node = findNodeById(parentId);
    if (!node) {
        Console::log(NO_SUCH_ELEMENT);
        return;
    }

    XML_Node *newNode = new XML_Node();
    newNode->setId(id);
    newNode->setTag(tag);
    node->addChild(newNode);
    Console::log(newNode->toString());
}

//void Dispatcher::xpath(String id, String query) { TODO
//    XML_Node *node = findNodeById(id);
//    if (!node) return;
//
//    List<String> results = XPath::executeQuery(query, node);
//
//    for(int i=0;i<results.getSize();i++) {
//        Console::log(results[i]);
//    }
//
//    if (results.getSize() == 0) {
//        Console::log(NO_RRESULTS_XPATH);
//    }
//}