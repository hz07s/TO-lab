#include <iostream>
#include <string>
#include "InputProcessor.h"
#include "CalculatorCore.h"

int main() {
    std::cout << "CALCULADORA EN C++ " << std::endl;
    std::cout << "Soporte para suma (+) y multiplicación (*)" << std::endl;
    std::cout << "Ejemplos: 12+34, 2*5, 12+4*12, 34*3+1*90" << std::endl;
    std::cout << "Máximo 6 números en expresiones simples." << std::endl;
    
    std::string input;
    std::cout << "\nIngrese la expresión: ";
    std::getline(std::cin, input);
    
    try {
        // Crear procesador de entrada usando puntero
        InputProcessor* inputProc = new InputProcessor(input);
        
        if (!inputProc->parseExpression()) {
            std::cout << "No se pudo procesar la expresión. Programa terminado." << std::endl;
            delete inputProc;
            return 1;
        }
        
        inputProc->displayParseInfo();
        
        // Crear núcleo de calculadora usando puntero
        CalculatorCore* calculator = new CalculatorCore();
        double result;
        
        if (inputProc->isComplex()) {
            // Expresión compleja - usar árbol binario
            result = calculator->processComplexExpression(inputProc->getExpression());
        } else {
            // Expresión simple - usar procesadores individuales
            result = calculator->processOperation(inputProc->getNumbers(), 
                                                inputProc->getOperation());
        }
        
        std::cout << "\n RESULTADO FINAL " << std::endl;
        std::cout << "Expresión: " << input << std::endl;
        std::cout << "Resultado: " << result << std::endl;
        
        // Liberar memoria
        delete inputProc;
        delete calculator;
        
    } catch (const std::exception& e) {
        std::cout << "Error durante la ejecución: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n¡Operación completada exitosamente!" << std::endl;
    return 0;
}
