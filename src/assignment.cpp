#include "assignment.hpp"

assignment::assignment(std::string name, int total)
    : name(name), total(total), grade(-1) {}

std::string assignment::get_name() {
    return name;
}

int assignment::get_total() {
    return total;
}

int assignment::get_grade() {
    return grade;
}

void assignment::enter_grade(int score) {
    grade = score;
}