#include <cstring>
#include "File.h"

void File::setPath(String path) {
    this->path = path;
}

void File::setData(String data) {
    this->data = data;
}

String File::getData() const {
    return this->data;
}

String File::getPath() const {
    return this->path;
}

