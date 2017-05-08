#include "File.h"
#include "../../Parser/Parser.h"

void File::setPath(String path) {
    //TODO: check it if is valid
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

void File::parse() {
    Parser parser;

    std::ifstream file("testfile.txt");

    file >> this->data;

    this->parent = parser.stringToNodeTree(this->data);

    file.close();
}

Node *File::getParent() const {
    return this->parent;
}