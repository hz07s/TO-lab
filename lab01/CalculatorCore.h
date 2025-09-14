#ifndef CALCULATORCORE_H
#define CALCULATORCORE_H

#include <vector>
#include <stdexcept>
#include "SumProcessor.h"

/**
 * Clase CalculatorCore - Núcleo de la calculadora
 */
class CalculatorCore {
private:
    SumProcessor sumProc;
    
public:
    CalculatorCore();
    double processOperation(const std::vector<double>& numbers, char operation);
    
private:
    double processSumOperation(const std::vector<double>& numbers);
};

#endif
