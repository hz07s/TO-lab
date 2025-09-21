#ifndef CALCULATORCORE_H
#define CALCULATORCORE_H

#include <vector>
#include <stdexcept>
#include <string>
#include "SumProcessor.h"
#include "MultiplicationProcessor.h"
#include "ExpressionTree.h"

class CalculatorCore {
private:
    SumProcessor* sumProc;
    MultiplicationProcessor* multiProc;
    ExpressionTree* expressionTree;
    
public:
    CalculatorCore();
    ~CalculatorCore();
    
    double processComplexExpression(const std::string& expression);
    double processOperation(const std::vector<double>& numbers, char operation);
    
private:
    double processSumOperation(const std::vector<double>& numbers);
    double processMultiplicationOperation(const std::vector<double>& numbers);
};

#endif
