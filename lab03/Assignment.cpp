#include "Assignment.h"
#include <iostream>

Assignment::Assignment() 
    : assignmentId(""), course(""), teacherId(""), dueDate(""), submitted(false), description("") {}

Assignment::Assignment(const std::string& id, const std::string& courseName, 
                       const std::string& tId, const std::string& date, 
                       bool isSubmitted, const std::string& desc)
    : assignmentId(id), course(courseName), teacherId(tId), 
      dueDate(date), submitted(isSubmitted), description(desc) {}

std::string Assignment::getAssignmentId() const {
    return assignmentId;
}

std::string Assignment::getCourse() const {
    return course;
}

std::string Assignment::getTeacherId() const {
    return teacherId;
}

std::string Assignment::getDueDate() const {
    return dueDate;
}

bool Assignment::isSubmitted() const {
    return submitted;
}

std::string Assignment::getDescription() const {
    return description;
}

void Assignment::setSubmissionStatus(bool status) {
    submitted = status;
}

void Assignment::setDescription(const std::string& desc) {
    description = desc;
}

void Assignment::displayInfo() const {
    std::cout << "Trabajo: " << assignmentId << " | Curso: " << course 
              << " | Fecha límite: " << dueDate 
              << " | Estado: " << getStatusString() << std::endl;
    if (!description.empty()) {
        std::cout << "  Descripción: " << description << std::endl;
    }
}

std::string Assignment::getStatusString() const {
    return submitted ? "✓ PRESENTADO" : "✗ PENDIENTE";
}