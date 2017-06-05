#ifndef XML_PARSER_PAIR_H
#define XML_PARSER_PAIR_H

template<typename T1, typename T2>
class Pair {
    T1 key;
    T2 value;
public:
    ////Constructor
    Pair(T1 key, T2 value) : key(key), value(value) {}

    //Changes the value of [key]
    virtual void setKey(T1 key) { this->key = key; }

    //Changes the value of [value]
    virtual void setValue(T2 val) { this->value = val; }

    //Returns the key
    virtual T1 getKey() const { return this->key; }

    //Returns the value
    virtual T2 getValue() const { return this->value; }

    ////Virtual destructor
    virtual ~Pair() {}
};

#endif //XML_PARSER_PAIR_H
