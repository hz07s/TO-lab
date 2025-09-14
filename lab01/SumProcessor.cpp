#include "SumProcessor.h"

SumProcessor::SumProcessor() {}

void SumProcessor::setNumbers(const std::vector<double>& nums) {
    if (nums.size() > 6) {
        throw std::invalid_argument("Máximo 6 números permitidos");
    }
    numbers = nums;
}

double SumProcessor::performSum() const {
    if (numbers.empty()) {
        throw std::runtime_error("No hay números para sumar");
    }
    
    double result = 0.0;
    for (const double& num : numbers) {
        result += num;
    }
    return result;
}

size_t SumProcessor::getNumberCount() const {
    return numbers.size();
}

void SumProcessor::displayNumbers() const {
    std::cout << "Números a sumar: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}
