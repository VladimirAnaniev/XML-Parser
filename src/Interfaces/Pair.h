#ifndef XML_PARSER_PAIR_H
#define XML_PARSER_PAIR_H

template<typename T1, typename T2>
class Pair {
    T1 key;
    T2 value;
public:
    Pair(T1 key, T2 value) : key(key), value(value) {}

    virtual void setKey(T1 key) { this->key = key; }
    virtual void setValue(T2 val) { this->value = val; }
    virtual T1 getKey() const  { return this->key; }
    virtual T2 getValue() const { return this->value; }

    virtual ~Pair() {}
};

#endif //XML_PARSER_PAIR_H
