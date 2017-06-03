#ifndef XML_PARSER_ARRAY_H
#define XML_PARSER_ARRAY_H

template<typename T>
class List {
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
    List(int size = 16);

//    //Converts a pointer array to List
//    List(T *arr);

    //Copy constructor
    List(const List &arr);

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

    //Searches for a given element and returns its index, -1 if not present
    int indexOf(T elem) const;

    /** Ideas
//    //Removes a given element if it is in the array
//    T remove(T elem);

     // void forEach(function f); do some action on every element of the array
     **/

    /** Operators **/
    List &operator=(const List &arr);

    //Accessor for elements
    T &operator[](int index);

    //Convert to T*
    operator T *() const { return this->arr; };

    ////Destructor
    ~List();
};

#include "List.tpp"

#endif //XML_PARSER_ARRAY_H
