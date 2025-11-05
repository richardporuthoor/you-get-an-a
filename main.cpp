#include <iostream>
#include <vector>
#include "string"
#include "src/assignment.hpp"
#include "src/gradebook.hpp"
#include "src/student.hpp"
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

  std::cout << printer.pretty_print(classroom);

}
