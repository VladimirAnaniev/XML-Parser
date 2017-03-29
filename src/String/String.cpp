#include <cstring>
#include "String.h"

String::String(const char *str) : str(nullptr) {
    int len = (int) strlen(str);
    this->set(str);
    this->length = len;
}

String::String(const String &string) : str(nullptr), length(string.length) {
    this->set(string.get());
}

void String::set(const char *str) {
    delete[] this->str;
    this->length = (int) strlen(str);
    this->str = new char[this->length + 1];
    strcpy(this->str, str);
}

const char *String::get() const {
    return this->str;
}

void String::resize(int newCells) {
    this->length += newCells;

    char *newStr = new char[this->length];
    strcpy(newStr, this->str);
    delete[] this->str;
    this->str = newStr;
}

void String::concat(const char *str) {
    resize((int) strlen(str));
    strcat(this->str, str);
}

String &String::operator=(const String &str) {
    if (this->str != nullptr) delete[] this->str;
    this->length = str.length;
    this->set(str.get());

    return *this;
}

String String::operator+(const String &str) const {
    String newstr;
    newstr.concat(this->get());
    newstr.concat(str.get());
    return newstr;
}

String &String::operator+=(const String &str) {
    this->concat(str.get());
    return *this;
}

String::~String() {
    delete[] this->str;
}

std::ostream &operator<<(std::ostream &out, String str) {
    out << str.get();
    return out;
}

void String::concat(String str) {
    this->concat(str.get());
}