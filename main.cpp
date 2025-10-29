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

  printer.pretty_print(classroom);

}
