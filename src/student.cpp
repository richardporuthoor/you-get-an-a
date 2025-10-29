#include <vector>
#include "student.hpp"
#include "string"

student::student(std::string name, std::string id)
    : name(name), id(id) {}

void student::add_assignment(std::string name, int total) {
    assignments.emplace_back(assignment(name, total));
}

std::string student::get_name() {
    return name;
}

void student::enter_grade(std::string aname, int grade) {
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i].get_name() == aname) {
            assignments[i].enter_grade(grade);
        }
    }
}

std::vector<assignment> student::get_assignments() {
    return assignments;
}
