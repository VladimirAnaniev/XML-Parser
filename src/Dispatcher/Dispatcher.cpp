#include <cstring>
#include "Dispatcher.h"

#include "../Globals.h"

using namespace Globals;

bool Dispatcher::dispatch(Command command) {
    List<String> args = command.getArguments();

    if (command == OPEN) {
        return fileManager.open(args[0]);
    } else if (command == CLOSE) {
        return fileManager.close();
    } else if (command == SAVE) {
        return fileManager.save();
    } else if (command == SAVE_AS) {
        return fileManager.saveAs(args[0]);
    } else if (command == PRINT) {
        return fileManager.print();
    } else if (command == SELECT) {
        return Dispatcher::select(args[0], args[1]);
    }else if (command == SET) {
        return Dispatcher::set(args[0], args[1], args[2]);
    } else {
        return false;
    }
}

bool Dispatcher::select(String id, String key) {
    try {
        XML_Node *node = fileManager.getFile().getParent()->findById(id);

        List<Argument> nodeArgs = node->getArguments();

        for(int i=0;i<nodeArgs.getSize();i++) {
            if(nodeArgs[i].getKey() == key) {
                Console::writeLine(nodeArgs[i]);
                return true;
            }
        }
    } catch (std::logic_error ex) {
        Console::writeLine(ex.what());
    }

    Console::writeLine("No such argument exists");
    return false;
}

bool Dispatcher::set(String id, String key, String value) {
    XML_Node *node = fileManager.getFile().getParent()->findById(id);

    List<Argument> nodeArgs = node->getArguments();

    for(int i=0;i<nodeArgs.getSize();i++) {
        if(nodeArgs[i].getKey() == key) {
            nodeArgs[i].setValue(value);
            Console::writeLine(nodeArgs[i]);
            return true;
        }
    }

    node->addArgument(Argument(key, value));
    Console::writeLine(nodeArgs[nodeArgs.getSize()-1]);
    return true;
}