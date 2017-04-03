#include <iostream>
#include "Array.h"

template<typename T>
Array<T>::Array(int size): length(size) {
    this->arr = new T[size];
}

template<typename T>
Array<T>::~Array() {
    delete[] this->arr;
}

template<typename T>
Array<T>::Array(const Array &arr) : length(arr.length) {
    this->arr = new T[arr.length];
    this->copy(arr.arr, arr.length);
}

template<typename T>
void Array<T>::copy(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        this->arr[i] = arr[i];
    }
}

template<typename T>
void Array<T>::resize(int newSize) {
    T *old = this->arr;
    this->arr = new T[newSize];
    this->copy(old, this->length);
    this->length = newSize;
}

template<typename T>
void Array<T>::expand(int n) {
    this->resize(this->length + n);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &arr) {
    this->length = arr.length;
    this->arr = new T[this->length];
    this->copy(arr.arr, arr.length);

    return *this;
}

template<typename T>
T &Array<T>::operator[](int index) {
    if (index < 0) {
        std::cerr << "Can't access index < 0" << std::endl;
        return this->arr[0]; //is this logical?
    } else if (index >= this->length) {
        this->resize(index + 1);
    }

    return this->arr[index];
}