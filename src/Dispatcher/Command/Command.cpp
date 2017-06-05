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

    this->arguments = input;
}

bool Command::operator==(String action) const {
    return strcmp(this->action, action) == 0;
}