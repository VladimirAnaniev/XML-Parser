#include <cstring>
#include "Command.h"

#include "../../Utils/Globals.h"

using namespace Globals;

String Command::getAction() const {
    return this->action;
}

List<String> Command::getArguments() const {
    return this->arguments;
}

Command::Command(List<String> input) {
    this->action = input.deleteAt(0);
    if (this->action == SAVE && input[0] == AS) {

        this->action += " ";
        this->action += input.deleteAt(0);
    }

    this->arguments = input;

    for (int i = 0; i < arguments.getSize(); i++) {
        if (arguments[i].beginsWith("-")) {
            this->optionals.push(this->arguments.deleteAt(i));
        }
    }
}

bool Command::operator==(String action) const {
    return strcmp(this->action, action) == 0;
}