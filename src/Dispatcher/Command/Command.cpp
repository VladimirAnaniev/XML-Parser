#include "Command.h"

#include "../../Globals.h"

using namespace Globals;

String Command::getAction() const {
    return this->action;
}

Array<String> Command::getArguments() const {
    return this->arguments;
}

Command::Command(Array<String> input) {
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