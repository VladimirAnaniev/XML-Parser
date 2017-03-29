#include <cstring>
#include "File.h"

void File::setData(const char *data) {
    delete[] this->data;
    this->data = new char[strlen(data)+1];
    strcpy(this->data, data);
}

void File::setPath(const char *path) {
    delete[] this->path;
    this->path = new char[strlen(path)+1];
    strcpy(this->path, path);
}

const char* File::getData() const {
    return this->data;
}

const char* File::getPath() const {
    return this->path;
}

File::File(const char *path, const char *data): path(nullptr), data(nullptr) {
    this->setPath(path);
    this->setData(data);
}

File::~File() {
    delete[] this->path;
    delete[] this->data;
}