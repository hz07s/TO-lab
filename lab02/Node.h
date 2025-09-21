#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>

class Node {
public:
    std::string value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    
    Node(const std::string& val);
    bool isOperator() const;
    bool isNumber() const;
    int getPrecedence() const;
};

#endif
