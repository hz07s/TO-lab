#include "SchoolSystem.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

SchoolSystem::SchoolSystem() {}

SchoolSystem::~SchoolSystem() {
    // Los unique_ptr se encargan automáticamente de la limpieza
}

bool SchoolSystem::registerStudent(const std::string& id, int grade, 
                                   const std::string& firstName, const std::string& lastName) {
    // Verificar que no exista un estudiante con el mismo ID
    if (studentExists(id)) {
        std::cout << "Error: Ya existe un estudiante con código " << id << std::endl;
        return false;
    }
    
    // Crear nuevo estudiante usando unique_ptr
    auto newStudent = std::make_unique<Student>(id, grade, firstName, lastName);
    students.push_back(std::move(newStudent));
    
    std::cout << "Estudiante registrado exitosamente: " << firstName << " " << lastName << std::endl;
    return true;
}

bool SchoolSystem::registerTeacher(const std::string& id, const std::string& firstName, 
                                   const std::string& lastName, const std::string& specialization) {
    if (teacherExists(id)) {
        std::cout << "Error: Ya existe un profesor con código " << id << std::endl;
        return false;
    }
    
    auto newTeacher = std::make_unique<Teacher>(id, firstName, lastName, specialization);
    teachers.push_back(std::move(newTeacher));
    
    std::cout << "Profesor registrado exitosamente: " << firstName << " " << lastName << std::endl;
    return true;
}

bool SchoolSystem::registerAssignment(const std::string& assignmentId, const std::string& course,
                                      const std::string& teacherId, const std::string& dueDate,
                                      bool submitted, const std::string& description) {
    // Verificar que el profesor existe
    if (!teacherExists(teacherId)) {
        std::cout << "Error: No existe profesor con código " << teacherId << std::endl;
        return false;
    }
    
    auto newAssignment = std::make_unique<Assignment>(assignmentId, course, teacherId, 
                                                     dueDate, submitted, description);
    assignments.push_back(std::move(newAssignment));
    
    std::cout << "Trabajo registrado exitosamente: " << course << " - " << assignmentId << std::endl;
    return true;
}

bool SchoolSystem::assignWorkToStudent(const std::string& studentId, const std::string& assignmentId) {
    Student* student = findStudent(studentId);
    Assignment* assignment = findAssignment(assignmentId);
    
    if (student == nullptr) {
        std::cout << "Error: Estudiante no encontrado " << studentId << std::endl;
        return false;
    }
    
    if (assignment == nullptr) {
        std::cout << "Error: Trabajo no encontrado " << assignmentId << std::endl;
        return false;
    }
    
    student->addAssignment(assignment);
    std::cout << "Trabajo asignado exitosamente a " << student->getFullName() << std::endl;
    return true;
}

bool SchoolSystem::assignStudentToTeacher(const std::string& studentId, const std::string& teacherId) {
    Student* student = findStudent(studentId);
    Teacher* teacher = findTeacher(teacherId);
    
    if (student == nullptr) {
        std::cout << "Error: Estudiante no encontrado " << studentId << std::endl;
        return false;
    }
    
    if (teacher == nullptr) {
        std::cout << "Error: Profesor no encontrado " << teacherId << std::endl;
        return false;
    }
    
    teacher->addStudent(student);
    std::cout << "Estudiante asignado exitosamente al profesor " << teacher->getFullName() << std::endl;
    return true;
}

Student* SchoolSystem::findStudent(const std::string& studentId) {
    for (auto& student : students) {
        if (student->getStudentId() == studentId) {
            return student.get();
        }
    }
    return nullptr;
}

Teacher* SchoolSystem::findTeacher(const std::string& teacherId) {
    for (auto& teacher : teachers) {
        if (teacher->getTeacherId() == teacherId) {
            return teacher.get();
        }
    }
    return nullptr;
}

Assignment* SchoolSystem::findAssignment(const std::string& assignmentId) {
    for (auto& assignment : assignments) {
        if (assignment->getAssignmentId() == assignmentId) {
            return assignment.get();
        }
    }
    return nullptr;
}

void SchoolSystem::displayStudentReport(const std::string& studentId) {
    Student* student = findStudent(studentId);
    if (student == nullptr) {
        std::cout << "Estudiante no encontrado: " << studentId << std::endl;
        return;
    }
    
    student->displayInfo();
    student->displayAssignments();
}

void SchoolSystem::displayTeacherReport(const std::string& teacherId) {
    Teacher* teacher = findTeacher(teacherId);
    if (teacher == nullptr) {
        std::cout << "Profesor no encontrado: " << teacherId << std::endl;
        return;
    }
    
    teacher->displayInfo();
    teacher->displayStudents();
}

void SchoolSystem::displaySystemSummary() {
    std::cout << "\n======= RESUMEN DEL SISTEMA ESCOLAR =======" << std::endl;
    std::cout << "Total de estudiantes registrados: " << getTotalStudents() << std::endl;
    std::cout << "Total de profesores registrados: " << getTotalTeachers() << std::endl;
    std::cout << "Total de trabajos registrados: " << getTotalAssignments() << std::endl;
    
    // Estadísticas por grado
    int gradeCount[7] = {0}; // Índices 1-6 para grados
    for (const auto& student : students) {
        int grade = student->getGrade();
        if (grade >= 1 && grade <= 6) {
            gradeCount[grade]++;
        }
    }
    
    std::cout << "\nDistribución de estudiantes por grado:" << std::endl;
    for (int i = 1; i <= 6; ++i) {
        if (gradeCount[i] > 0) {
            std::cout << "  " << i << "° año: " << gradeCount[i] << " estudiantes" << std::endl;
        }
    }
}

bool SchoolSystem::studentExists(const std::string& studentId) {
    return findStudent(studentId) != nullptr;
}

bool SchoolSystem::teacherExists(const std::string& teacherId) {
    return findTeacher(teacherId) != nullptr;
}

int SchoolSystem::getTotalStudents() const {
    return students.size();
}

int SchoolSystem::getTotalTeachers() const {
    return teachers.size();
}

int SchoolSystem::getTotalAssignments() const {
    return assignments.size();
}

void SchoolSystem::displayAllStudents() {
    std::cout << "\n=== LISTA DE ESTUDIANTES ===" << std::endl;
    if (students.empty()) {
        std::cout << "No hay estudiantes registrados." << std::endl;
        return;
    }
    
    for (const auto& student : students) {
        std::cout << "• " << student->getFullName() 
                  << " (Código: " << student->getStudentId() 
                  << ", Grado: " << student->getGrade() << "°)" << std::endl;
    }
}

void SchoolSystem::displayAllTeachers() {
    std::cout << "\n=== LISTA DE PROFESORES ===" << std::endl;
    if (teachers.empty()) {
        std::cout << "No hay profesores registrados." << std::endl;
        return;
    }
    
    for (const auto& teacher : teachers) {
        std::cout << "• " << teacher->getFullName() 
                  << " (Código: " << teacher->getTeacherId() 
                  << ", Especialización: " << teacher->getSpecialization() << ")" << std::endl;
    }
}

void SchoolSystem::displayAllAssignments() {
    std::cout << "\n=== LISTA DE TRABAJOS ===" << std::endl;
    if (assignments.empty()) {
        std::cout << "No hay trabajos registrados." << std::endl;
        return;
    }
    
    for (const auto& assignment : assignments) {
        std::cout << "• ";
        assignment->displayInfo();
    }
}