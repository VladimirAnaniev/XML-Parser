#include "Argument.h"

Argument::Argument(String key, String value) : Pair(key, value) {}

String Argument::toString() {
    return this->getKey()+"=\""+this->getValue()+"\" ";
}
