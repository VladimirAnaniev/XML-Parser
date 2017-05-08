#include "Console.h"
#include <cstring>
#include "../Globals.h"

using namespace Globals;

void Console::listen() const {
    bool loop = true;
    while(true) {
        loop = readLine();
        if(!loop) this->invalidCommand(); //TODO: REFACTOR THIS
    }
}

bool Console::readLine() const {
    char input[128];
    std::cin.getline(input, 128);

    String str = input;

    Array<String> parts = str.split();

    Command c(parts);

    return dispatcher.dispatch(c);
}

void Console::invalidCommand() const {
    this->writeLine("Invalid command!");
}

void Console::write(String str) const {
    std::cout << str;
}

void Console::writeLine(String str) const {
    std::cout << str << std::endl;
}


