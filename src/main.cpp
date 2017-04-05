#include <iostream>
#include "Console/Console.h"
#include "Base Classes/Array/Array.h"


int main() {
    Console console;
    //console.listen();
    String str = "nqkuv text dali she go opravi?  !!";

    Array<String> parts = str.split(' ');

    for(int i=0;i<parts.getSize();i++) {
        std::cout<<parts[i]<<" ";
    }

    return 0;
}