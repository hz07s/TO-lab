#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "Node.h"
#include "SumProcessor.h"
#include "MultiplicationProcessor.h"
#include <vector>
#include <string>
#include <stack>
#include <memory>

class ExpressionTree {
private:
    std::shared_ptr<Node> root;
    SumProcessor* sumProcessor;
    MultiplicationProcessor* multiProcessor;
    
    std::vector<std::string> tokenize(const std::string& expression);
    std::vector<std::string> infixToPostfix(const std::vector<std::string>& infix);
    std::shared_ptr<Node> buildTree(const std::vector<std::string>& postfix);
    double evaluateTree(std::shared_ptr<Node> node);
    
public:
    ExpressionTree();
    ~ExpressionTree();
    
    bool buildFromExpression(const std::string& expression);
    double evaluate();
    void displayTree(std::shared_ptr<Node> node, int depth = 0);
    void displayTree();
};

#endif
