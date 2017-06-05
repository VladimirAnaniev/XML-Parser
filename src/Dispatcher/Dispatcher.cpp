#include "Dispatcher.h"

#include "../Utils/Globals.h"
#include "../Utils/Exception.h"
#include "../FileManager/FileManager.h"
#include "../Console/Console.h"

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
    } else if (command == QUIT) {
        return false;
    } else {
        Console::writeLine(INVALID_COMMAND);
    }

    return true;
}

XML_Node *findNodeById(String id) {
    try {
        return FileManager::getFile().getParent()->findById(id);
    } catch (Exception ex) {
        Console::writeLine(ex.what());
    }
    return nullptr;
}

void Dispatcher::select(String id, String key) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    List<Argument> &nodeArgs = node->getArguments();

    for (int i = 0; i < nodeArgs.getSize(); i++) {
        if (nodeArgs[i].getKey() == key) {
            Console::writeLine(nodeArgs[i]);
            return;
        }
    }

    Console::writeLine(NO_SUCH_ARGUMENT);
}

void Dispatcher::set(String id, String key, String value) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    List<Argument> &nodeArgs = node->getArguments();

    for (int i = 0; i < nodeArgs.getSize(); i++) {
        if (nodeArgs[i].getKey() == key) {
            nodeArgs[i].setValue(value);
            Console::writeLine(nodeArgs[i]);
            return;
        }
    }

    nodeArgs.push(Argument(key, value));
    Console::writeLine(nodeArgs[nodeArgs.getSize() -1]);
}

void Dispatcher::child(String id, int index) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    if(node->getChildren().getSize() <= index) {
        Console::writeLine(NO_SUCH_CHILD);
    } else {
        Console::writeLine(((XML_Node *)node->getChildren()[index])->toString());
    }
}

void Dispatcher::children(String id) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    for(int i=0;i<node->getChildren().getSize();i++) {
        Console::writeLine(((XML_Node *)node->getChildren()[i])->toString());
    }

    if(node->getChildren().getSize() < 1) {
        Console::writeLine(NO_CHILDREN);
    }
}

void Dispatcher::text(String id) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    Console::writeLine(node->getContent());
}

void Dispatcher::del(String id, String key) {
    XML_Node *node = findNodeById(id);
    if(!node) return;

    List<Argument> &args = node->getArguments();

    for(int i=0;i<args.getSize();i++) {
        if(args[i].getKey() == key) {
            Console::writeLine(DELETED + args.deleteAt(i));
            return;
        }
    }

    Console::writeLine(NO_SUCH_ARGUMENT);
}