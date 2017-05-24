#include "File.h"
#include "../../Parser/Parser.h"

bool File::setPath(String path) {
    this->path.set(path);
    return this->isValid();
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

void File::parse() {
    Parser parser;

    std::ifstream file(this->path);

    file >> this->data;

    if(this->parent) delete this->parent;
    this->parent = parser.stringToNodeTree(this->data);

    file.close();
}

Node *File::getParent() const {
    return this->parent;
}

bool File::isValid() const {
    std::ifstream file(this->path);
    return (file) ? true : false;
}

File::File() : parent(nullptr) {}

File::File(const File &file): path(file.path), parent(nullptr) {
    this->parse();
}

File &File::operator=(const File &file) {
    this->path = file.path;
    this->parse();
    return *this;
}

File::~File() {
    delete this->parent;
}