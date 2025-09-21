#include "InputProcessor.h"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

InputProcessor::InputProcessor(const std::string& expr) 
    : expression(expr), operation('+'), isComplexExpression(false) {}

bool InputProcessor::validateExpression() const {
    if (expression.empty()) {
        std::cout << "Error: Expresión vacía" << std::endl;
        return false;
    }
    
    if (expression.find('+') == std::string::npos && expression.find('*') == std::string::npos) {
        std::cout << "Error: La expresión debe contener operador de suma (+) o multiplicación (*)" << std::endl;
        return false;
    }
    
    return true;
}

bool InputProcessor::hasMultipleOperators() const {
    int operatorCount = 0;
    for (char c : expression) {
        if (c == '+' || c == '*') {
            operatorCount++;
        }
    }
    return operatorCount > 1 || (expression.find('+') != std::string::npos && expression.find('*') != std::string::npos);
}

bool InputProcessor::parseSimpleExpression() {
    try {
        numbers.clear();
        char op = '+';
        
        // Determinar operación
        if (expression.find('*') != std::string::npos) {
            op = '*';
        }
        operation = op;
        
        std::stringstream ss(expression);
        std::string token;
        
        while (std::getline(ss, token, op)) {
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            
            if (!token.empty()) {
                double num = std::stod(token);
                numbers.push_back(num);
            }
        }
        
        if (numbers.empty()) {
            std::cout << "Error: No se encontraron números válidos" << std::endl;
            return false;
        }
        
        if (numbers.size() > 6) {
            std::cout << "Error: Máximo 6 números permitidos. Se encontraron: " 
                      << numbers.size() << std::endl;
            return false;
        }
        
        return true;
    } catch (const std::exception& e) {
        std::cout << "Error parseando expresión: " << e.what() << std::endl;
        return false;
    }
}

bool InputProcessor::parseExpression() {
    if (!validateExpression()) {
        return false;
    }
    
    isComplexExpression = hasMultipleOperators();
    
    if (isComplexExpression) {
        std::cout << "Detectada expresión compleja - usando árbol binario" << std::endl;
        return true;
    } else {
        return parseSimpleExpression();
    }
}

bool InputProcessor::isComplex() const {
    return isComplexExpression;
}

std::string InputProcessor::getExpression() const {
    return expression;
}

std::vector<double> InputProcessor::getNumbers() const {
    return numbers;
}

char InputProcessor::getOperation() const {
    return operation;
}

void InputProcessor::displayParseInfo() const {
    std::cout << "\n INFORMACIÓN DE PARSEO " << std::endl;
    std::cout << "Expresión original: " << expression << std::endl;
    
    if (isComplexExpression) {
        std::cout << "Tipo: Expresión compleja (múltiples operadores)" << std::endl;
    } else {
        std::cout << "Números encontrados: " << numbers.size() << std::endl;
        std::cout << "Operación: " << operation << std::endl;
    }
}
