#include "File.h"
#include "../../Parser/Parser.h"
#include "../../Utils/Exception.h"
#include "../../Utils/Globals.h"

using namespace Globals;

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

void File::parse() {
    std::ifstream file(this->path);

    file >> this->data;

    if (this->root) delete this->root;
    this->root = Parser::stringToNodeTree(this->data);

    file.close();
}

XML_Node *File::getParent() const {
    return this->root;
}

File::File(String path) : root(nullptr) {
    this->setPath(path);
    this->parse();
}

File::File(const File &file) : path(file.path), root(nullptr) {
    this->parse();
}

File &File::operator=(const File &file) {
    this->path = file.path;
    this->parse();
    return *this;
}

File::~File() {
    delete this->root;
}