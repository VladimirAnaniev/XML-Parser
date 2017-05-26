#include <cstring>
#include <iostream>
#include "String.h"

String::String(const char *str) : str(nullptr) {
    this->set(str);
}

String::String(const String &string) : str(nullptr) {
    this->set(string);
}

void String::set(const char *str) {
    delete[] this->str;
    this->length = (int) strlen(str);
    this->capacity = calculateCapacity(length);
    this->str = new char[capacity];
    strcpy(this->str, str);
}

const char *String::get() const {
    return this->str;
}

void String::resize() {
    this->capacity *= 2;

    char *newStr = new char[this->capacity];
    strcpy(newStr, this->str);
    delete[] this->str;
    this->str = newStr;
}

void String::concat(const char *str) {
    int len = (int) strlen(str);
    while (capacity <= this->length + len + 1) {
        resize();
    }
    strcat(this->str, str);
    this->length += len;
}

String &String::operator=(const String &str) {
    this->set(str.get());

    return *this;
}

String String::operator+(const String &str) const {
    char *newStr = new char[this->getLength() + str.getLength() + 1];

    strcpy(newStr, this->str);
    strcat(newStr, str.str);

    return String(newStr);
}

String &String::operator+=(const String &str) {
    this->concat(str.get());
    return *this;
}

String::~String() {
    delete[] this->str;
}

std::ostream &operator<<(std::ostream &out, String &str) {
    out << str.get();
    return out;
}

std::istream &operator>>(std::istream &in, String &str) {
    str = "";
    char read[256];

    while (in.getline(read, 256)) {
        if (read[0] != '\0') str.concat(String(read) + "\n");
    }

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
    String str = this->clearSpaces();

    for (int i = 0; i < str.length; i++) {
        if (str[i] == c) {
            String newstr = str.substring(lastIndex, i);
            if (newstr.length) arr.push(newstr);
            lastIndex = i + 1;
        }
    }
    arr.push(substring(lastIndex, str.length + 1));

    return arr;
}

String String::substring(int start, int end) const {
    char *newStr = new char[end - start + 1];
    strncpy(newStr, this->str + start, (size_t) end - start);
    newStr[end - start] = '\0';
    return String(newStr);
}

Array<String> String::split(Array<char> delims) const {
    Array<String> arr;
    int lastIndex = 0;
    String str = this->clearSpaces();

    for (int i = 0; i < str.length; i++) {
        if (delims.indexOf(str[i]) != -1) {
            String newstr = str.substring(lastIndex, i);
            if (newstr.length) arr.push(newstr);
            lastIndex = i + 1;
        }
    }
    arr.push(substring(lastIndex, str.length + 1));

    return arr;
}

String String::clearSpaces() const {
    String result;
    int lastIndex = 0;
    bool lastWasSpace = false;

    for (int i = 0; i < this->length; i++) {
        if (this->str[i] == ' ') {
            if (!lastWasSpace) {
                result += this->substring(lastIndex, i);
                lastWasSpace = true;
            }

            lastIndex = i;
        } else {
            lastWasSpace = false;
        }
    }
    result += this->substring(lastIndex, this->length + 1);

    return result;
}

String operator+(char *c, String str) {
    String s(c);
    s.concat(str);
    return s;
}

String::String(char c, int n) : str(nullptr) {
    char *arr = new char[n + 1];
    for (int i = 0; i < n; i++) {
        arr[i] = c;
    }
    arr[n] = '\0';

    this->set(arr);
}

bool String::beginsWith(String str) const {
    for (int i = 0; i < str.length; i++) {
        if (this->str[i] != str[i]) return false;
    }

    return true;
}

int String::getLength() const {
    return this->length;
}

String String::before(int index) const {
    return this->substring(0, index);
}

String String::after(int index) const {
    return this->substring(index, this->length);
}

int String::indexOf(char c) const {
    for (int i = 0; i < this->length; i++) {
        if (this->str[i] == c) return i;
    }

    return -1;
}

int String::indexOf(String str) const {
    Array<int> indexes = this->occurrencesOf(str[0]);

    for (int o = 0; o < indexes.getSize(); o++) {
        bool flag = true;
        for (int i = 1; i < str.length; i++) {
            if (this->str[indexes[o] + i] != str[i]) {
                flag = false;
                break;
            }
        }
        if (flag) return indexes[o];
    }


    return -1;
}

bool String::endsWith(String str) const {
    for (int i = 0; i < str.length; i++) {
        if (this->str[this->getLength() - 1 - i] != str[str.getLength() - 1 - i]) {
            return false;
        }
    }

    return true;
}

void String::prepend(String str) {
    this->set(str + this->get());
}

Array<int> String::occurrencesOf(char c) const {
    Array<int> result;

    for (int i = 0; i < this->length; i++) {
        if (this->operator[](i) == c) result.push(i);
    }

    return result;
}

String String::generateRandom(int len) {
    char *arr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        int alphabet = 26, digits = 10;
        int random = rand() % (2 * alphabet + digits);
        if (random < alphabet) {
            arr[i] = (char) ('a' + random);
        } else if (random < 2 * alphabet) {
            arr[i] = (char) ('A' + (random - alphabet));
        } else {
            arr[i] = (char) ('0' + (random - 2 * alphabet));
        }
    }

    String str(arr);
    delete[] arr;
    return str;
}

int String::indexOfBackwards(char c) const {
    for (int i = this->length - 1; i >= 0; i--) {
        if (this->str[i] == c) return i;
    }

    return -1;
}

int String::calculateCapacity(int length) {
    int capacity = 16;
    while (capacity <= length) {
        capacity *= 2;
    }
    return capacity;
}