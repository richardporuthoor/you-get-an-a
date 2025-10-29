#pragma once
#include "assignment.hpp"
#include <vector>

class student {
private:
    std::vector<assignment> assignments;
    std::string name;
    std::string id;

public:
    student(std::string name, std::string id);
    void add_assignment(std::string name, int total);
    std::string get_name();
    std::vector<assignment> get_assignments();
    void enter_grade(std::string aname, int grade);
};


