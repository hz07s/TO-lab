#include "InputProcessor.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

InputProcessor::InputProcessor(const std::string& expr) : expression(expr), operation('+') {}

bool InputProcessor::validateExpression() const {
    if (expression.empty()) {
        std::cout << "Error: Expresión vacía" << std::endl;
        return false;
    }
    
    if (expression.find('+') == std::string::npos) {
        std::cout << "Error: La expresión debe contener operador de suma (+)" << std::endl;
        return false;
    }
    
    return true;
}

bool InputProcessor::parseExpression() {
    if (!validateExpression()) {
        return false;
    }
    
    try {
        numbers.clear();
        std::stringstream ss(expression);
        std::string token;
        
        while (std::getline(ss, token, '+')) {
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
        
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: Formato de número inválido en la expresión" << std::endl;
        return false;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: Número fuera de rango" << std::endl;
        return false;
    }
}

std::vector<double> InputProcessor::getNumbers() const {
    return numbers;
}

char InputProcessor::getOperation() const {
    return operation;
}

void InputProcessor::displayParseInfo() const {
    std::cout << "\nINFORMACIÓN DE PARSEO" << std::endl;
    std::cout << "Expresión original: " << expression << std::endl;
    std::cout << "Números encontrados: " << numbers.size() << std::endl;
    std::cout << "Operación: " << operation << std::endl;
}
