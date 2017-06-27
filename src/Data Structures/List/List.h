#ifndef XML_PARSER_ARRAY_H
#define XML_PARSER_ARRAY_H

#include <iostream>

template<typename T>
class List {
    T *arr;
    int size;
    int capacity;

    //Copy the given array into this one
    void copy(T *arr, int length) {
        for (int i = 0; i < length; i++) {
            this->arr[i] = arr[i];
        }
    }

    //Resize the array to the given size
    void resize(int newSize) {
        T *old = this->arr;
        this->arr = new T[newSize];
        this->copy(old, this->size);
        this->capacity = newSize;
    }

public:
    /** Constructors **/
    //Default
    List(int size = 16) : capacity(size), size(0) {
        this->arr = new T[size];
    }

//    //Converts a pointer array to List
//    List(T *arr);

    //Copy constructor
    List(const List &arr) : capacity(arr.capacity), size(arr.size) {
        this->arr = new T[arr.capacity];
        this->copy(arr.arr, arr.size);
    }

    /** Methods **/
    //Returns number of elements currently in the array
    int getSize() const {
        return this->size;
    }

    //Returns the maximum capacity of the array
    int getCapacity() const {
        return this->capacity;
    }

    //Returns wether the array is empty
    bool isEmpty() const {
        return this->size == 0;
    }

    //Returns the element at the given index, error if index is out of bounds
    T &get(int index) const {
        if (index < 0 || index >= capacity) {
            std::cerr << "Calling List.get() with an invalid index";
        }

        return this->arr[index];
    }

    //Add an element at the end of the array
    void push(T elem) {
        this->insert(this->size, elem);
    }

    //Insert an element at a given position, shifts all elements after it
    void insert(int index, T elem) {
        if (this->size == this->capacity) {
            this->resize(this->capacity * 2); //double the size if array is full
        }

        for (int i = this->size - 1; i >= index; i--) {
            this->arr[i + 1] = this->arr[i]; //shift all elements after [index] to the right
        }

        this->arr[index] = elem;
        this->size++;
    }

    //Inserts the given element at the beginning of the array
    void prepend(T elem) {
        this->insert(0, elem);
    }

    //Removes the last item
    T pop() {
        return this->deleteAt(this->size - 1);
    }

    //Removes the element at a given index and shift all after it to the left
    T deleteAt(int index) {
        if (index < 0 || index >= capacity) {
            std::cerr << "Calling List.deleteAt() with an invalid index";
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

    //Searches for a given element and returns its index, -1 if not present
    int indexOf(T elem) const {
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i] == elem) return i;
        }

        return -1;
    }

    /** Ideas
    //Removes a given element if it is in the array
    T remove(T elem);

     // void forEach(function f); do some action on every element of the array
     **/

    /** Operators **/
    List &operator=(const List &arr) {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->arr = new T[arr.capacity];
        this->copy(arr.arr, arr.size);

        return *this;
    }

    //Accessor for elements
    T &operator[](int index) {
        return this->get(index);
    }

    //Convert to T*
    operator T *() const {
        return this->arr;
    };

    ////Destructor
    ~List() {
        delete[] this->arr;
    }
};

#endif //XML_PARSER_ARRAY_H
