#include <iostream>
#include "Console/Console.h"

int main() {
    srand((unsigned int) time(0));

    Console::listen();

    return 0;
}