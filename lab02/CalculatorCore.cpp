#include "CalculatorCore.h"
#include <iostream>

CalculatorCore::CalculatorCore() {
    sumProc = new SumProcessor();
    multiProc = new MultiplicationProcessor();
    expressionTree = new ExpressionTree();
}

CalculatorCore::~CalculatorCore() {
    delete sumProc;
    delete multiProc;
    delete expressionTree;
}

double CalculatorCore::processComplexExpression(const std::string& expression) {
    std::cout << "\n PROCESANDO EXPRESIÓN COMPLEJA " << std::endl;
    std::cout << "Expresión: " << expression << std::endl;
    
    if (!expressionTree->buildFromExpression(expression)) {
        throw std::runtime_error("No se pudo construir el árbol de expresión");
    }
    
    expressionTree->displayTree();
    
    double result = expressionTree->evaluate();
    std::cout << "Resultado de evaluación del árbol: " << result << std::endl;
    
    return result;
}

double CalculatorCore::processOperation(const std::vector<double>& numbers, char operation) {
    switch (operation) {
        case '+':
            return processSumOperation(numbers);
        case '*':
            return processMultiplicationOperation(numbers);
        default:
            throw std::invalid_argument("Operación no soportada. Solo se admiten suma (+) y multiplicación (*)");
    }
}

double CalculatorCore::processSumOperation(const std::vector<double>& numbers) {
    try {
        sumProc->setNumbers(numbers);
        sumProc->displayNumbers();
        return sumProc->performSum();
    } catch (const std::exception& e) {
        throw std::runtime_error("Error en operación de suma: " + std::string(e.what()));
    }
}

double CalculatorCore::processMultiplicationOperation(const std::vector<double>& numbers) {
    try {
        multiProc->setNumbers(numbers);
        multiProc->displayNumbers();
        return multiProc->performMultiplication();
    } catch (const std::exception& e) {
        throw std::runtime_error("Error en operación de multiplicación: " + std::string(e.what()));
    }
}
