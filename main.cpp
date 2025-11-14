#include <iostream>
#include "src/gradebook.hpp"
#include "src/gradebook_printer.hpp"

int main() {
    gradebook classroom;
    gradebook_printer printer;

    classroom.add_student("kasper kaminski", "ABC123");
    classroom.add_student("richard poruthoor", "xyz987");
    classroom.add_student("matthew kutyna", "OOOOOOO");

    classroom.add_assignment("Quiz 1", 100);
    classroom.add_assignment("Homework 1", 20);

    classroom.enter_grade("kasper kaminski", "Homework 1", 18);
    classroom.enter_grade("matthew kutyna", "Quiz 1", 70);
    classroom.enter_grade("richard poruthoor", "Quiz 1", 95);
    classroom.enter_grade("richard poruthoor", "Homework 1", 20);

    std::cout << classroom.report() << "\n";
    std::cout << classroom.assignment_report("Quiz 1") << "\n";
    std::cout << classroom.assignment_report("Homework 1") << "\n";
    std::cout << printer.pretty_print(classroom);
}