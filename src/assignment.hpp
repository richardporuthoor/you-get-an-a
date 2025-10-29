#pragma once
#include "string"

class assignment {
private:
    std::string name;
    int total;
    int grade;

public:
    assignment(std::string name, int total);
    std::string get_name();
    int get_total();
    int get_grade();
    void enter_grade(int score);
};
