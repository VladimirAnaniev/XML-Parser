#include "Console.h"
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

    String str = input;

    Array<String> parts = str.split();

//    switch(parts[0]) {
//       //TODO: Can it work that way?
//    }

    if (strcmp(parts[0], "open") == 0) {
        this->fm.open(parts[1]);
        return OK;
    } else if (strcmp(parts[0], "close") == 0) {
        this->fm.close();
        return OK;
    } else if (strcmp(parts[0], "save") == 0) {
        if (parts.getSize() == 1) {
            this->fm.save();
        } else if (strcmp(parts[1], "as") == 0) {
            if (parts.getSize() != 3) return BAD;

            this->fm.saveAs(parts[2]);
            return OK;

        }
        else {
            return BAD;
        }
    }

    if (strcmp(input, "boza") == 0) return END;

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


