#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

/**
 * Clase Student - Representa un estudiante del sistema escolar
 * Almacena información básica del estudiante y sus trabajos asignados
 */
class Student {
private:
    std::string studentId;      // Código de identificación único
    int grade;                  // Grado del estudiante (1-6)
    std::string firstName;      // Nombres del estudiante
    std::string lastName;       // Apellidos del estudiante
    std::vector<class Assignment*> assignments; // Punteros a trabajos asignados

public:
    Student();
    Student(const std::string& id, int gr, const std::string& fName, const std::string& lName);
    ~Student();
    
    // Métodos de acceso (getters)
    std::string getStudentId() const;
    int getGrade() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    
    // Métodos de manipulación
    void addAssignment(class Assignment* assignment);
    int getSubmittedAssignmentsCount() const;
    int getTotalAssignmentsCount() const;
    double getCompletionPercentage() const;
    
    // Métodos de visualización
    void displayInfo() const;
    void displayAssignments() const;
};

#endif