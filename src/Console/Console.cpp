#include "Console.h"
#include <iostream>
#include <cstring>

const short OK = 1;
const short BAD = 0;
const short END = -1;

void Console::listen() {
    short response = readLine();
    if (response == END) return;
    else if (response == BAD) invalidCommand();
    listen();
}

short Console::readLine() {
    char input[128];
    std::cin.getline(input, 128);

    //TODO: LOGIC

    if (strcmp(input, "boza") == 0) return END;

    return BAD;
}

void Console::invalidCommand() {
    std::cout << "Invalid command!" << std::endl;
}


