#include "ExpressionTree.h"
#include <sstream>
#include <algorithm>
#include <iostream>

ExpressionTree::ExpressionTree() {
    root = nullptr;
    sumProcessor = new SumProcessor();
    multiProcessor = new MultiplicationProcessor();
}

ExpressionTree::~ExpressionTree() {
    delete sumProcessor;
    delete multiProcessor;
}

std::vector<std::string> ExpressionTree::tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string current = "";
    
    for (char c : expression) {
        if (c == '+' || c == '*') {
            if (!current.empty()) {
                tokens.push_back(current);
                current = "";
            }
            tokens.push_back(std::string(1, c));
        } else if (c != ' ') {
            current += c;
        }
    }
    
    if (!current.empty()) {
        tokens.push_back(current);
    }
    
    return tokens;
}

std::vector<std::string> ExpressionTree::infixToPostfix(const std::vector<std::string>& infix) {
    std::vector<std::string> postfix;
    std::stack<std::string> operators;
    
    for (const std::string& token : infix) {
        if (token != "+" && token != "*") {
            // Es un número
            postfix.push_back(token);
        } else {
            // Es un operador
            Node tempNode(token);
            while (!operators.empty()) {
                Node topNode(operators.top());
                if (topNode.getPrecedence() >= tempNode.getPrecedence()) {
                    postfix.push_back(operators.top());
                    operators.pop();
                } else {
                    break;
                }
            }
            operators.push(token);
        }
    }
    
    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }
    
    return postfix;
}

std::shared_ptr<Node> ExpressionTree::buildTree(const std::vector<std::string>& postfix) {
    std::stack<std::shared_ptr<Node>> nodeStack;
    
    for (const std::string& token : postfix) {
        auto node = std::make_shared<Node>(token);
        
        if (node->isOperator()) {
            if (nodeStack.size() < 2) {
                throw std::runtime_error("Expresión inválida");
            }
            
            node->right = nodeStack.top();
            nodeStack.pop();
            node->left = nodeStack.top();
            nodeStack.pop();
        }
        
        nodeStack.push(node);
    }
    
    if (nodeStack.size() != 1) {
        throw std::runtime_error("Expresión inválida");
    }
    
    return nodeStack.top();
}

double ExpressionTree::evaluateTree(std::shared_ptr<Node> node) {
    if (!node) return 0.0;
    
    if (node->isNumber()) {
        return std::stod(node->value);
    }
    
    double leftVal = evaluateTree(node->left);
    double rightVal = evaluateTree(node->right);
    
    if (node->value == "+") {
        std::vector<double> nums = {leftVal, rightVal};
        sumProcessor->setNumbers(nums);
        return sumProcessor->performSum();
    } else if (node->value == "*") {
        std::vector<double> nums = {leftVal, rightVal};
        multiProcessor->setNumbers(nums);
        return multiProcessor->performMultiplication();
    }
    
    throw std::runtime_error("Operador no soportado: " + node->value);
}

bool ExpressionTree::buildFromExpression(const std::string& expression) {
    try {
        auto tokens = tokenize(expression);
        auto postfix = infixToPostfix(tokens);
        root = buildTree(postfix);
        return true;
    } catch (const std::exception& e) {
        std::cout << "Error construyendo árbol: " << e.what() << std::endl;
        return false;
    }
}

double ExpressionTree::evaluate() {
    if (!root) {
        throw std::runtime_error("Árbol no construido");
    }
    return evaluateTree(root);
}

void ExpressionTree::displayTree(std::shared_ptr<Node> node, int depth) {
    if (!node) return;
    
    displayTree(node->right, depth + 1);
    
    for (int i = 0; i < depth; ++i) {
        std::cout << "    ";
    }
    std::cout << node->value << std::endl;
    
    displayTree(node->left, depth + 1);
}

void ExpressionTree::displayTree() {
    std::cout << "\n ÁRBOL BINARIO DE EXPRESIÓN " << std::endl;
    if (root) {
        displayTree(root);
    } else {
        std::cout << "Árbol vacío" << std::endl;
    }
}
