#ifndef XML_PARSER_PAIR_H
#define XML_PARSER_PAIR_H

template<typename T1, typename T2>
class Pair {
public:
    virtual void setKey(T1 key) = 0;
    virtual void setValue(T2 val) = 0;
    virtual T1 getKey() const = 0;
    virtual T2 getValue() const = 0;

    virtual ~Pair() {}
};

#endif //XML_PARSER_PAIR_H
