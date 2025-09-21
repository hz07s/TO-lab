#include "Node.h"

Node::Node(const std::string& val) : value(val), left(nullptr), right(nullptr) {}

bool Node::isOperator() const {
    return value == "+" || value == "*";
}

bool Node::isNumber() const {
    return !isOperator();
}

int Node::getPrecedence() const {
    if (value == "*") return 2;
    if (value == "+") return 1;
    return 0;
}
