#include "Console.h"
#include "../Dispatcher/Command/Command.h"
#include "../Dispatcher/Dispatcher.h"
#include <cstring>

void Console::listen() {
    bool loop = true;
    while (loop) {
        loop = Console::readLine();
    }
}

bool Console::readLine() {
    char input[128];
    std::cin.getline(input, 128);

    String str = input;

    List<String> parts = str.split();

    Command c(parts);

    return Dispatcher::dispatch(c);
}

void Console::log(String str) {
    std::cout << str << std::endl;
}


