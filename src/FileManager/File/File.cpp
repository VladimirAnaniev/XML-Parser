#include "File.h"

void File::setPath(String path) {
    this->path.set(path);
}

void File::setData(String data) {
    this->data.set(data);
}

String File::getData() const {
    return this->data;
}

String File::getPath() const {
    return this->path;
}

bool File::parse(String path) {
    this->setPath(path);

    return true;

    //TODO: Open file, read input and parse to node tree.
}