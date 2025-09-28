#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include <algorithm>

Teacher::Teacher() : teacherId(""), firstName(""), lastName(""), specialization("") {}

Teacher::Teacher(const std::string& id, const std::string& fName, const std::string& lName, 
                 const std::string& spec)
    : teacherId(id), firstName(fName), lastName(lName), specialization(spec) {}

Teacher::~Teacher() {
    // No eliminamos los Student* porque son administrados por SchoolSystem
    students.clear();
}

std::string Teacher::getTeacherId() const {
    return teacherId;
}

std::string Teacher::getFirstName() const {
    return firstName;
}

std::string Teacher::getLastName() const {
    return lastName;
}

std::string Teacher::getFullName() const {
    return firstName + " " + lastName;
}

std::string Teacher::getSpecialization() const {
    return specialization;
}

void Teacher::addStudent(Student* student) {
    if (student != nullptr) {
        // Verificar que el estudiante no esté ya asignado
        if (!hasStudent(student->getStudentId())) {
            students.push_back(student);
        }
    }
}

bool Teacher::hasStudent(const std::string& studentId) const {
    for (const Student* student : students) {
        if (student != nullptr && student->getStudentId() == studentId) {
            return true;
        }
    }
    return false;
}

int Teacher::getStudentCount() const {
    return students.size();
}

std::vector<int> Teacher::getGradeDistribution() const {
    std::vector<int> distribution(7, 0); // Índices 1-6 para grados 1-6
    
    for (const Student* student : students) {
        if (student != nullptr) {
            int grade = student->getGrade();
            if (grade >= 1 && grade <= 6) {
                distribution[grade]++;
            }
        }
    }
    
    return distribution;
}

void Teacher::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL PROFESOR ===" << std::endl;
    std::cout << "Código: " << teacherId << std::endl;
    std::cout << "Nombre completo: " << getFullName() << std::endl;
    std::cout << "Especialización: " << specialization << std::endl;
    std::cout << "Estudiantes a cargo: " << getStudentCount() << std::endl;
    
    // Mostrar distribución por grados
    std::vector<int> distribution = getGradeDistribution();
    std::cout << "Distribución por grados:" << std::endl;
    for (int i = 1; i <= 6; ++i) {
        if (distribution[i] > 0) {
            std::cout << "  " << i << "° año: " << distribution[i] << " estudiantes" << std::endl;
        }
    }
}

void Teacher::displayStudents() const {
    std::cout << "\n--- ESTUDIANTES A CARGO ---" << std::endl;
    if (students.empty()) {
        std::cout << "No tiene estudiantes asignados." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i] != nullptr) {
            std::cout << (i + 1) << ". " << students[i]->getFullName() 
                      << " (Código: " << students[i]->getStudentId() 
                      << ", Grado: " << students[i]->getGrade() << "°)" << std::endl;
        }
    }
}