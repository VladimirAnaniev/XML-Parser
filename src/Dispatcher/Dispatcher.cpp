#include <cstring>
#include "Dispatcher.h"

#include "../Globals.h"

using namespace Globals;

bool Dispatcher::dispatch(Command command) {

    if (command == OPEN) {
        return fileManager.open(command.getArguments()[0]);
    } else if (command == CLOSE) {
        return fileManager.close();
    } else if (command == SAVE) {
        return fileManager.save();
    } else if (command == SAVE_AS) {
        return fileManager.saveAs(command.getArguments()[0]);
    } else if (command == PRINT) {
        return fileManager.print();
    } else {
        return false;
    }
}