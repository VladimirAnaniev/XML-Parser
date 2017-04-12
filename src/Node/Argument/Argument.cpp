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

void Argument::setValue(String key) {
    this->value = value;
}