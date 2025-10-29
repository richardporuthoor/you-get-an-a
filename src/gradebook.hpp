#pragma once
#include "string"
#include <vector>
#include "student.hpp"

class gradebook {
private:
    std::vector<student> classroom;

public:
    gradebook();
    void add_student(const std::string name, const std::string id);
    void add_assignment(const std::string name, const int total);
    void enter_grade(std::string sname, std::string aname, int grade);
    std::vector<student> get_classroom();
};

