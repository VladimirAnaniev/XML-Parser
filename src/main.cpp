#include <iostream>
#include "Console/Console.h"
#include "Base Classes/Array/Array.h"


int main() {
    Console console;
    //console.listen();
    String str = "nqkuv text dali she go opravi?  !!";

    Array<String> parts = str.split(' ');

    std::cout<<parts[0]<<std::endl;
    std::cout<<parts[1]<<std::endl;
    std::cout<<parts[2]<<std::endl;
    std::cout<<parts[3]<<std::endl;
    std::cout<<parts[4]<<std::endl;
    std::cout<<parts.get(5)<<std::endl;
    std::cout<<parts[6]<<std::endl;
    std::cout<<parts.get(7)<<std::endl;

    return 0;
}