#ifndef SUMPROCESSOR_H
#define SUMPROCESSOR_H

#include <vector>
#include <stdexcept>
#include <iostream>

class SumProcessor {
private:
    std::vector<double> numbers;
    
public:
    SumProcessor();
    void setNumbers(const std::vector<double>& nums);
    double performSum() const;
    size_t getNumberCount() const;
    void displayNumbers() const;
};

#endif
