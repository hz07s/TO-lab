#include <iostream>
#include <string>
#include "InputProcessor.h"
#include "CalculatorCore.h"

int main() {
    std::cout << "CALCULADORA DE SUMA EN C++" << std::endl;
    std::cout << "Ingrese una expresión de suma (ejemplo: 12+34, 1+2+3+4+5+6)" << std::endl;
    std::cout << "Máximo 6 números permitidos." << std::endl;
    
    std::string input;
    std::cout << "\nIngrese la expresión: ";
    std::getline(std::cin, input);
    
    try {
        InputProcessor inputProc(input);
        
        if (!inputProc.parseExpression()) {
            std::cout << "No se pudo procesar la expresión. Programa terminado." << std::endl;
            return 1;
        }
        
        inputProc.displayParseInfo();
        
        CalculatorCore calculator;
        double result = calculator.processOperation(inputProc.getNumbers(), 
                                                  inputProc.getOperation());
        
        std::cout << "\nRESULTADO:" << std::endl;
        std::cout << "Expresión: " << input << std::endl;
        std::cout << "Resultado: " << result << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
