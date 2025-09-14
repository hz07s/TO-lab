#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <string>
#include <vector>

class InputProcessor {
private:
    std::string expression;
    std::vector<double> numbers;
    char operation;
    
public:
    InputProcessor(const std::string& expr);
    bool validateExpression() const;
    bool parseExpression();
    std::vector<double> getNumbers() const;
    char getOperation() const;
    void displayParseInfo() const;
};

#endif
