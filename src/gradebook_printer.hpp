#include <iostream>
#include "string"
#include <vector>
#include "gradebook.hpp"
#include "student.hpp"
#include "assignment.hpp"

class gradebook_printer {
public:
    gradebook_printer();
    std::string pretty_print(gradebook& classroom);
};

gradebook_printer::gradebook_printer() {}

std::string gradebook_printer::pretty_print(gradebook& classroom) {
    std::vector<student> room = classroom.get_classroom();
    std::string output;

    for (int i = 0; i < room.size(); i++) {
        student current_student = room[i];
        output += "---- ";
        output += current_student.get_name();
        output += " ----\n";

        std::vector<assignment> work = current_student.get_assignments();

        for (int i = 0; i < work.size(); i++) {
            output += work[i].get_name() + ": ";

            if (work[i].get_grade() == -1) {
               output += "Not scored /";
            } else {
                output += std::to_string(work[i].get_grade()) + "/";
            }
            
            output += std::to_string(work[i].get_total()) + "\n";
        }

        output += "\n\n";
    }
    return output;
}