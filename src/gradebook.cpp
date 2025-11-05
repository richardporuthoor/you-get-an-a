#include "gradebook.hpp"
#include "student.hpp"
#include "assignment.hpp"
#include "string"
#include <vector>

gradebook::gradebook()
    : classroom(){}

void gradebook::add_student(const std::string name, const std::string id) {
    classroom.emplace_back(student(name, id));
}

void gradebook::add_assignment(const std::string name, const int total) {
    for (int i = 0; i < classroom.size(); i++) {
        classroom[i].add_assignment(name, total);
    }
}

std::vector<student> gradebook::get_classroom() {
    return classroom;
}

void gradebook::enter_grade(std::string stuname, std::string aname, int grade) {
    for (int i = 0; i < classroom.size(); i++) {
        student& current_student = classroom[i];

        if (current_student.get_name() == stuname) {
            current_student.enter_grade(aname, grade);
        }
    }
}