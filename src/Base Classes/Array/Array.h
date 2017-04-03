#ifndef XML_PARSER_ARRAY_H
#define XML_PARSER_ARRAY_H

template<typename T>
class Array {
    T *arr;
    int length;

    void copy(T *arr, int length);

public:
    /** Constructors **/
    //Default
    Array(int size = 0);

//    //Converts a pointer array to Array
//    Array(T *arr);

    //Copy constructor
    Array(const Array &arr);

    /** Methods **/
    // Expand the size of the array by n cells
    void expand(int n);

    //Resize the array to the given size
    void resize(int newSize);

    /** Operators **/
    Array &operator=(const Array &arr);

    T &operator[](int index);

    operator T *() const { return this->arr; };

    ////Destructor
    ~Array();
};

#include "Array.tpp"

#endif //XML_PARSER_ARRAY_H
