#ifndef XML_PARSER_XPATH_H
#define XML_PARSER_XPATH_H

#include "../Data Structures/String/String.h"
#include "../XML Tree/XML_Node.h"

class XPath {
public:
    static List<String> executeQuery(String query, XML_Node *node);
};


#endif //XML_PARSER_XPATH_H
