#include "MultiplicationProcessor.h"

MultiplicationProcessor::MultiplicationProcessor() {}

MultiplicationProcessor::~MultiplicationProcessor() {}

void MultiplicationProcessor::setNumbers(const std::vector<double>& nums) {
    if (nums.size() > 6) {
        throw std::invalid_argument("Máximo 6 números permitidos");
    }
    numbers = nums;
}

double MultiplicationProcessor::performMultiplication() const {
    if (numbers.empty()) {
        throw std::runtime_error("No hay números para multiplicar");
    }
    
    double result = 1.0;
    for (const double& num : numbers) {
        result *= num;
    }
    return result;
}

size_t MultiplicationProcessor::getNumberCount() const {
    return numbers.size();
}

void MultiplicationProcessor::displayNumbers() const {
    std::cout << "Números a multiplicar: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << " * ";
        }
    }
    std::cout << std::endl;
}
