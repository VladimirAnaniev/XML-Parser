#ifndef XML_PARSER_ARRAY_H
#define XML_PARSER_ARRAY_H

template<typename T>
class Array {
    T *arr;
    int size;
    int capacity;

    //Copy the given array into this one
    void copy(T *arr, int length);

    //Resize the array to the given size
    void resize(int newSize);

public:
    /** Constructors **/
    //Default
    Array(int size = 16);

//    //Converts a pointer array to Array
//    Array(T *arr);

    //Copy constructor
    Array(const Array &arr);

    /** Methods **/
    //Returns number of elements currently in the array
    int getSize() const;

    //Returns the maximum capacity of the array
    int getCapacity() const;

    //Returns wether the array is empty
    bool isEmpty() const;

    //Returns the element at the given index, error if index is out of bounds
    T &get(int index) const;

    //Add an element at the end of the array
    void push(T elem);

    //Insert an element at a given position, shifts all elements after it
    void insert(int index, T elem);

    //Inserts the given element at the beggining of the array
    void prepend(T elem);

    //Removes the last item
    T pop();

    //Removes the element at a given index and shift all after it to the left
    T deleteAt(int index);

//    //Removes a given element if it is in the array
//    T remove(T elem);
//
//    //Returns the index of an element if it is in the array
//    int find(T elem) const;

    /** Operators **/
    Array &operator=(const Array &arr);

    //Accessor for elements
    T &operator[](int index);

    //Convert to T*
    operator T *() const { return this->arr; };

    ////Destructor
    ~Array();
};

#include "Array.tpp"

#endif //XML_PARSER_ARRAY_H
