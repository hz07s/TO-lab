#include "Student.h"
#include "Assignment.h"
#include <iostream>
#include <iomanip>

Student::Student() : studentId(""), grade(0), firstName(""), lastName("") {}

Student::Student(const std::string& id, int gr, const std::string& fName, const std::string& lName)
    : studentId(id), grade(gr), firstName(fName), lastName(lName) {
    // Validación del grado (1-6 años de primaria)
    if (grade < 1 || grade > 6) {
        std::cout << "Advertencia: Grado fuera del rango válido (1-6)" << std::endl;
    }
}

Student::~Student() {
    // El destructor no elimina los Assignment* porque son administrados por SchoolSystem
    assignments.clear();
}

std::string Student::getStudentId() const {
    return studentId;
}

int Student::getGrade() const {
    return grade;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getFullName() const {
    return firstName + " " + lastName;
}

void Student::addAssignment(Assignment* assignment) {
    if (assignment != nullptr) {
        assignments.push_back(assignment);
    }
}

int Student::getSubmittedAssignmentsCount() const {
    int count = 0;
    for (const Assignment* assignment : assignments) {
        if (assignment != nullptr && assignment->isSubmitted()) {
            count++;
        }
    }
    return count;
}

int Student::getTotalAssignmentsCount() const {
    return assignments.size();
}

double Student::getCompletionPercentage() const {
    if (assignments.empty()) {
        return 0.0;
    }
    return (static_cast<double>(getSubmittedAssignmentsCount()) / assignments.size()) * 100.0;
}

void Student::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL ESTUDIANTE ===" << std::endl;
    std::cout << "Código: " << studentId << std::endl;
    std::cout << "Nombre completo: " << getFullName() << std::endl;
    std::cout << "Grado: " << grade << "° año de primaria" << std::endl;
    std::cout << "Trabajos asignados: " << getTotalAssignmentsCount() << std::endl;
    std::cout << "Trabajos presentados: " << getSubmittedAssignmentsCount() << std::endl;
    std::cout << "Porcentaje de cumplimiento: " << std::fixed << std::setprecision(1) 
              << getCompletionPercentage() << "%" << std::endl;
}

void Student::displayAssignments() const {
    std::cout << "\n--- TRABAJOS ASIGNADOS ---" << std::endl;
    if (assignments.empty()) {
        std::cout << "No tiene trabajos asignados." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < assignments.size(); ++i) {
        std::cout << (i + 1) << ". ";
        if (assignments[i] != nullptr) {
            assignments[i]->displayInfo();
        }
    }
}