#ifndef SCHOOLSYSTEM_H
#define SCHOOLSYSTEM_H

#include <vector>
#include <memory>
#include "Student.h"
#include "Teacher.h"
#include "Assignment.h"

/**
 * Clase SchoolSystem - Sistema principal que administra toda la información
 * Gestiona estudiantes, profesores y trabajos usando punteros inteligentes
 * Proporciona funcionalidades de registro, búsqueda y consultas estadísticas
 */
class SchoolSystem {
private:
    std::vector<std::unique_ptr<Student>> students;     // Lista de estudiantes
    std::vector<std::unique_ptr<Teacher>> teachers;     // Lista de profesores  
    std::vector<std::unique_ptr<Assignment>> assignments; // Lista de trabajos

public:
    SchoolSystem();
    ~SchoolSystem();
    
    // Métodos de registro
    bool registerStudent(const std::string& id, int grade, 
                        const std::string& firstName, const std::string& lastName);
    bool registerTeacher(const std::string& id, const std::string& firstName, 
                        const std::string& lastName, const std::string& specialization);
    bool registerAssignment(const std::string& assignmentId, const std::string& course,
                           const std::string& teacherId, const std::string& dueDate,
                           bool submitted, const std::string& description = "");
    
    // Métodos de asignación
    bool assignWorkToStudent(const std::string& studentId, const std::string& assignmentId);
    bool assignStudentToTeacher(const std::string& studentId, const std::string& teacherId);
    
    // Métodos de búsqueda
    Student* findStudent(const std::string& studentId);
    Teacher* findTeacher(const std::string& teacherId);
    Assignment* findAssignment(const std::string& assignmentId);
    
    // Métodos de consulta estadística
    void displayStudentReport(const std::string& studentId);
    void displayTeacherReport(const std::string& teacherId);
    void displaySystemSummary();
    
    // Métodos de visualización general
    void displayAllStudents();
    void displayAllTeachers();
    void displayAllAssignments();
    
    // Métodos de utilidad
    bool studentExists(const std::string& studentId);
    bool teacherExists(const std::string& teacherId);
    int getTotalStudents() const;
    int getTotalTeachers() const;
    int getTotalAssignments() const;
};

#endif