#include "Console.h"
#include "../Dispatcher/Command/Command.h"
#include "../Dispatcher/Dispatcher.h"
#include <cstring>

void Console::listen() {
    bool loop = true;
    while(true) {
        loop = Console::readLine();
        if(!loop) Console::invalidCommand(); //TODO: REFACTOR THIS
    }
}

bool Console::readLine() {
    char input[128];
    std::cin.getline(input, 128);

    String str = input;

    Array<String> parts = str.split();

    Command c(parts);

    return Dispatcher::dispatch(c);
}

void Console::invalidCommand() {
    Console::writeLine("Invalid command!");
}

void Console::write(String str) {
    std::cout << str;
}

void Console::writeLine(String str) {
    std::cout << str << std::endl;
}


