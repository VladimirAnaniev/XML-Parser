#include "Argument.h"

String Argument::getKey() const {
    return this->key;
}

String Argument::getValue() const {
    return this->value;
}

void Argument::setKey(String key) {
    this->key = key;
}

void Argument::setValue(String value) {
    this->value = value;
}

Argument::Argument(String key, String value) : key(key), value(value) {}

String Argument::toString() {
    return this->getKey()+"=\""+this->getValue()+"\" ";
}
