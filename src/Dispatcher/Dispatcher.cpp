#include <cstring>
#include "Dispatcher.h"

#include "../Globals.h"

using namespace Globals;

bool Dispatcher::dispatch(Command c) const {
    String action = c.getAction();

    if (strcmp(action, OPEN) == 0) {
        return fileManager.open(c.getArguments()[0]);
    } else if (strcmp(action, CLOSE) == 0) {
        return fileManager.close();
    } else if (strcmp(action, SAVE) == 0) {
        return fileManager.save();
    } else if (strcmp(action, SAVE_AS) == 0) {
        return fileManager.saveAs(c.getArguments()[0]);
    } else if (strcmp(action, PRINT) == 0) {
        //Check for optionals

        return fileManager.print();
    } else {
        return false;
    }
}