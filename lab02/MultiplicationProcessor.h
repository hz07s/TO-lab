#ifndef MULTIPLICATIONPROCESSOR_H
#define MULTIPLICATIONPROCESSOR_H

#include <vector>
#include <stdexcept>
#include <iostream>

class MultiplicationProcessor {
private:
    std::vector<double> numbers;
    
public:
    MultiplicationProcessor();
    ~MultiplicationProcessor();
    
    void setNumbers(const std::vector<double>& nums);
    double performMultiplication() const;
    size_t getNumberCount() const;
    void displayNumbers() const;
};

#endif
