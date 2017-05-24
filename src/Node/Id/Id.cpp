#include "Id.h"

Id::Id(String id) : Argument("id", id) {}

String Id::get() const {
    return this->getValue();
}

void Id::set(String id) {
    this->setValue(id);
}