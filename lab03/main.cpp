#include <iostream>
#include <string>
#include "SchoolSystem.h"

void displayMenu() {
    std::cout << "\n========== SISTEMA DE GESTIÓN ESCOLAR ==========" << std::endl;
    std::cout << "1. Registrar estudiante" << std::endl;
    std::cout << "2. Registrar profesor" << std::endl;
    std::cout << "3. Registrar trabajo/tarea" << std::endl;
    std::cout << "4. Asignar trabajo a estudiante" << std::endl;
    std::cout << "5. Asignar estudiante a profesor" << std::endl;
    std::cout << "6. Consultar información de estudiante" << std::endl;
    std::cout << "7. Consultar información de profesor" << std::endl;
    std::cout << "8. Ver resumen del sistema" << std::endl;
    std::cout << "9. Mostrar todos los estudiantes" << std::endl;
    std::cout << "10. Mostrar todos los profesores" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    SchoolSystem system;
    int option;
    
    std::cout << "=== SISTEMA DE GESTIÓN ESCOLAR CON CLASES Y PUNTEROS ===" << std::endl;
    std::cout << "Desarrollado en C++ para administrar estudiantes, profesores y tareas" << std::endl;
    
    // Datos de prueba iniciales
    std::cout << "\n--- Cargando datos de prueba ---" << std::endl;
    system.registerStudent("EST001", 1, "Juan Carlos", "Pérez López");
    system.registerStudent("EST002", 2, "María Elena", "García Ruiz");
    system.registerStudent("EST003", 3, "Pedro Antonio", "Mendoza Silva");
    
    system.registerTeacher("PROF001", "Ana Lucía", "Vargas Castro", "Matemáticas");
    system.registerTeacher("PROF002", "Carlos Eduardo", "Ramírez Torres", "Comunicación");
    
    system.registerAssignment("TAREA001", "Matemáticas", "PROF001", "2025-09-20", true, "Ejercicios de suma y resta");
    system.registerAssignment("TAREA002", "Comunicación", "PROF002", "2025-09-22", false, "Lectura comprensiva");
    system.registerAssignment("TAREA003", "Matemáticas", "PROF001", "2025-09-25", true, "Problemas de multiplicación");
    
    // Asignaciones de prueba
    system.assignWorkToStudent("EST001", "TAREA001");
    system.assignWorkToStudent("EST001", "TAREA002");
    system.assignWorkToStudent("EST002", "TAREA001");
    system.assignWorkToStudent("EST003", "TAREA003");
    
    system.assignStudentToTeacher("EST001", "PROF001");
    system.assignStudentToTeacher("EST002", "PROF001");
    system.assignStudentToTeacher("EST002", "PROF002");
    system.assignStudentToTeacher("EST003", "PROF001");
    
    while (true) {
        displayMenu();
        std::cin >> option;
        std::cin.ignore(); // Limpiar buffer
        
        switch (option) {
            case 1: {
                std::string id, firstName, lastName;
                int grade;
                std::cout << "Ingrese código del estudiante: ";
                std::getline(std::cin, id);
                std::cout << "Ingrese grado (1-6): ";
                std::cin >> grade;
                std::cin.ignore();
                std::cout << "Ingrese nombres: ";
                std::getline(std::cin, firstName);
                std::cout << "Ingrese apellidos: ";
                std::getline(std::cin, lastName);
                
                system.registerStudent(id, grade, firstName, lastName);
                break;
            }
            case 2: {
                std::string id, firstName, lastName, specialization;
                std::cout << "Ingrese código del profesor: ";
                std::getline(std::cin, id);
                std::cout << "Ingrese nombres: ";
                std::getline(std::cin, firstName);
                std::cout << "Ingrese apellidos: ";
                std::getline(std::cin, lastName);
                std::cout << "Ingrese especialización: ";
                std::getline(std::cin, specialization);
                
                system.registerTeacher(id, firstName, lastName, specialization);
                break;
            }
            case 3: {
                std::string assignmentId, course, teacherId, dueDate, description;
                bool submitted;
                std::cout << "Ingrese ID del trabajo: ";
                std::getline(std::cin, assignmentId);
                std::cout << "Ingrese curso: ";
                std::getline(std::cin, course);
                std::cout << "Ingrese código del profesor: ";
                std::getline(std::cin, teacherId);
                std::cout << "Ingrese fecha límite (YYYY-MM-DD): ";
                std::getline(std::cin, dueDate);
                std::cout << "¿Está presentado? (1=Sí, 0=No): ";
                std::cin >> submitted;
                std::cin.ignore();
                std::cout << "Descripción (opcional): ";
                std::getline(std::cin, description);
                
                system.registerAssignment(assignmentId, course, teacherId, dueDate, submitted, description);
                break;
            }
            case 4: {
                std::string studentId, assignmentId;
                std::cout << "Ingrese código del estudiante: ";
                std::getline(std::cin, studentId);
                std::cout << "Ingrese ID del trabajo: ";
                std::getline(std::cin, assignmentId);
                
                system.assignWorkToStudent(studentId, assignmentId);
                break;
            }
            case 5: {
                std::string studentId, teacherId;
                std::cout << "Ingrese código del estudiante: ";
                std::getline(std::cin, studentId);
                std::cout << "Ingrese código del profesor: ";
                std::getline(std::cin, teacherId);
                
                system.assignStudentToTeacher(studentId, teacherId);
                break;
            }
            case 6: {
                std::string studentId;
                std::cout << "Ingrese código del estudiante: ";
                std::getline(std::cin, studentId);
                
                system.displayStudentReport(studentId);
                break;
            }
            case 7: {
                std::string teacherId;
                std::cout << "Ingrese código del profesor: ";
                std::getline(std::cin, teacherId);
                
                system.displayTeacherReport(teacherId);
                break;
            }
            case 8: {
                system.displaySystemSummary();
                break;
            }
            case 9: {
                system.displayAllStudents();
                break;
            }
            case 10: {
                system.displayAllTeachers();
                break;
            }
            case 0: {
                std::cout << "¡Gracias por usar el Sistema de Gestión Escolar!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Opción inválida. Por favor, intente nuevamente." << std::endl;
                break;
            }
        }
        
        std::cout << "\nPresione Enter para continuar...";
        std::cin.get();
    }
    
    return 0;
}