#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <string>
#include <vector>

class InputProcessor {
private:
    std::string expression;
    std::vector<double> numbers;
    char operation;
    bool isComplexExpression;
    
public:
    InputProcessor(const std::string& expr);
    
    bool validateExpression() const;
    bool parseExpression();
    bool isComplex() const;
    std::string getExpression() const;
    std::vector<double> getNumbers() const;
    char getOperation() const;
    void displayParseInfo() const;
    
private:
    bool hasMultipleOperators() const;
    bool parseSimpleExpression();
};

#endif
