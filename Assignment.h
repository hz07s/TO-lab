#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

/**
 * Clase Assignment - Representa un trabajo o tarea asignada
 * Contiene información del curso, profesor, fecha y estado de presentación
 */
class Assignment {
private:
    std::string assignmentId;    // Identificador único del trabajo
    std::string course;          // Nombre del curso
    std::string teacherId;       // ID del profesor a cargo
    std::string dueDate;         // Fecha de presentación
    bool submitted;              // Estado de presentación (true/false)
    std::string description;     // Descripción del trabajo

public:
    Assignment();
    Assignment(const std::string& id, const std::string& courseName, 
               const std::string& tId, const std::string& date, 
               bool isSubmitted, const std::string& desc = "");
    
    // Métodos de acceso
    std::string getAssignmentId() const;
    std::string getCourse() const;
    std::string getTeacherId() const;
    std::string getDueDate() const;
    bool isSubmitted() const;
    std::string getDescription() const;
    
    // Métodos de modificación
    void setSubmissionStatus(bool status);
    void setDescription(const std::string& desc);
    
    // Métodos de visualización
    void displayInfo() const;
    std::string getStatusString() const;
};

#endif