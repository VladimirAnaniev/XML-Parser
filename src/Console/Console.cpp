#include "Console.h"
#include <cstring>
#include "../Globals.cpp"

using namespace Globals;

void Console::listen() {
    short response = readLine();
    if (response == END) return;
    else if (response == BAD) invalidCommand();
    listen();
}

short Console::readLine() {
    char input[128];
    std::cin.getline(input, 128);

    String str = input;

    Array<String> parts = str.split();

//    switch(parts[0]) {
//       //TODO: Can it work that way?
//    }
    //TODO: SEND EVENTS TO DISPATCHER

    if (strcmp(parts[0], OPEN) == 0) {
        this->fm.open(parts[1]);
        return OK;
    } else if (strcmp(parts[0], CLOSE) == 0) {
        this->fm.close();
        return OK;
    } else if (strcmp(parts[0], SAVE) == 0) {
        if (parts.getSize() == 1) {
            this->fm.save();
        } else if (strcmp(parts[1], AS) == 0) {
            if (parts.getSize() != 3) return BAD;

            this->fm.saveAs(parts[2]);
            return OK;

        }
        else {
            return BAD;
        }
    } else if (strcmp(parts[0], PRINT) == 0) {
       // this->
    }

    if (strcmp(input, "boza") == 0) return END;

    //TODO: SEND EVENTS TO DISPATCHER

    return BAD;
}

void Console::invalidCommand() {
    this->writeLine("Invalid command!");
}

void Console::write(String str) {
    std::cout << str;
}

void Console::writeLine(String str) {
    std::cout << str << std::endl;
}


