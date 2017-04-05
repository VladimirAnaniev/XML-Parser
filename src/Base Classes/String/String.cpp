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
    if (index < 0 || index >= this->length) {
        throw std::invalid_argument("Trying to call string[index] with an invalid index.");
    }

    return this->str[index];
}

bool String::operator==(const String &str) const {
    return strcmp(this->str, str.str) == 0;
}

Array<String> String::split(char c) const {
    Array<String> arr;
    int lastIndex = 0;

    for (int i = 0; i < this->length; i++) {
        if(this->str[i] == c) {
            String newstr = this->substring(lastIndex, i);
            if(newstr.length) arr.push(newstr);
            lastIndex = i + 1;
        }
    }
    arr.push(substring(lastIndex, this->length+1));

    return arr;
}

String String::substring(int start, int end) const {
    char* newStr = new char[end-start+1];
    strncpy(newStr, this->str+start, (size_t) end-start);
    newStr[end-start] = '\0';
    return newStr;
}
