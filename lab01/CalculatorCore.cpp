#include "CalculatorCore.h"
#include <iostream>

CalculatorCore::CalculatorCore() {}

double CalculatorCore::processOperation(const std::vector<double>& numbers, char operation) {
    switch (operation) {
        case '+':
            return processSumOperation(numbers);
        default:
            throw std::invalid_argument("Operación no soportada. Solo se admite suma (+)");
    }
}

double CalculatorCore::processSumOperation(const std::vector<double>& numbers) {
    try {
        sumProc.setNumbers(numbers);
        sumProc.displayNumbers();
        return sumProc.performSum();
    } catch (const std::exception& e) {
        throw std::runtime_error("Error en operación de suma: " + std::string(e.what()));
    }
}
