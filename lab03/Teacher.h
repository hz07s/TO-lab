#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

/**
 * Clase Teacher - Representa un profesor del sistema escolar
 * Almacena información del profesor y gestiona sus cursos y estudiantes
 */
class Teacher {
private:
    std::string teacherId;      // Código de identificación del profesor
    std::string firstName;      // Nombres del profesor
    std::string lastName;       // Apellidos del profesor
    std::string specialization; // Especialización o materia principal
    std::vector<class Student*> students; // Punteros a estudiantes a cargo

public:
    Teacher();
    Teacher(const std::string& id, const std::string& fName, const std::string& lName, 
            const std::string& spec);
    ~Teacher();
    
    // Métodos de acceso
    std::string getTeacherId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    std::string getSpecialization() const;
    
    // Métodos de gestión de estudiantes
    void addStudent(class Student* student);
    bool hasStudent(const std::string& studentId) const;
    int getStudentCount() const;
    std::vector<int> getGradeDistribution() const;
    
    // Métodos de visualización
    void displayInfo() const;
    void displayStudents() const;
};

#endif