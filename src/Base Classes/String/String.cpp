#include <cstring>
#include <iostream>
#include "String.h"

String::String(const char *str) : str(nullptr) {
    int len = (int) strlen(str);
    this->set(str);
    this->length = len;
}

String::String(const String &string) : str(nullptr), length(string.length) {
    this->set(string);
}

void String::set(const char *str) {
    if (this->str != nullptr) delete[] this->str;
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

std::ifstream &operator>>(std::ifstream &in, String str) {
//    char line[10000];
//    in.getline(line, 10000);
//    str.set(line);
    //TODO: HOW DO I READ FROM THE FILE CORRECTLY?
    return in;
}

const char String::operator[](int index) const {
    if (index >= 0 && index < this->length) {
        return this->str[index];
    }
    std::cerr << "You cannot access this index!!" << std::endl;
    return '\0';
}

bool String::operator==(const String &str) const {
    return strcmp(this->str, str.str) == 0;
}
