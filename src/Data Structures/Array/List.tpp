#include <iostream>
#include "List.h"


template<typename T>
List<T>::List(int size): capacity(size), size(0) {
    this->arr = new T[size];
}

template<typename T>
List<T>::~List() {
    delete[] this->arr;
}

template<typename T>
List<T>::List(const List &arr) : capacity(arr.capacity), size(arr.size) {
    this->arr = new T[arr.capacity];
    this->copy(arr.arr, arr.size);
}

template<typename T>
void List<T>::copy(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        this->arr[i] = arr[i];
    }
}

template<typename T>
void List<T>::resize(int newSize) {
    T *old = this->arr;
    this->arr = new T[newSize];
    this->copy(old, this->size);
    this->capacity = newSize;
}

template<typename T>
List<T> &List<T>::operator=(const List &arr) {
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->arr = new T[arr.capacity];
    this->copy(arr.arr, arr.size);

    return *this;
}

template<typename T>
T &List<T>::operator[](int index) {
    return this->get(index);
}

template<typename T>
int List<T>::getSize() const {
    return this->size;
}

template<typename T>
int List<T>::getCapacity() const {
    return this->capacity;
}

template<typename T>
void List<T>::insert(int index, T elem) {
    if (this->size == this->capacity) {
        this->resize(this->capacity * 2); //double the size if array is full
    }

    for (int i = this->size - 1; i >= index; i--) {
        this->arr[i + 1] = this->arr[i]; //shift all elements after [index] to the right
    }

    this->arr[index] = elem;
    this->size++;
}

template<typename T>
void List<T>::push(T elem) {
    this->insert(this->size, elem);
}

template<typename T>
void List<T>::prepend(T elem) {
    this->insert(0, elem);
}

template<typename T>
T &List<T>::get(int index) const {
    if (index < 0 || index >= capacity) {
        throw std::invalid_argument("Calling List.get() with an invalid index");
    }

    return this->arr[index];
}

template<typename T>
bool List<T>::isEmpty() const {
    return this->size == 0;
}

template<typename T>
T List<T>::deleteAt(int index) {
    if (index < 0 || index >= capacity) {
        throw std::invalid_argument("Calling List.deleteAt() with an invalid index");
    }

    T toReturn = this->arr[index];
    this->size--;

    for (int i = index; i < this->size; i++) {
        this->arr[i] = this->arr[i + 1]; //Shift all elements after [index] to the left
    }

    if (this->size < this->capacity / 4) {
        this->resize(this->capacity / 4);
    }

    return toReturn;
}

template<typename T>
T List<T>::pop() {
    return this->deleteAt(this->size - 1);
}

template<typename T>
int List<T>::indexOf(T elem) const {
    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] == elem) return i;
    }

    return -1;
}

