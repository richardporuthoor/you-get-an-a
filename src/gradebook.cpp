#include "gradebook.hpp"
#include "student.hpp"
#include "assignment.hpp"
#include "string"
#include <vector>
#include <sstream>
#include <iomanip>

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

std::string gradebook::report() {
    std::ostringstream out;

    for (auto& s : classroom) {
        out << "---- " << s.get_name() << " ----\n";

        std::vector<assignment> work = s.get_assignments();

        double earned = 0;
        double possible = 0;

        for (auto& a : work) {
            int g = a.get_grade();
            out << a.get_name() << ": ";
            if (g == -1) out << "Not scored /" << a.get_total() << "\n";
            else {
                out << g << "/" << a.get_total() << "\n";
                earned += g;
                possible += a.get_total();
            }
        }

        out << "Average: ";
        if (possible == 0) out << "none\n\n";
        else out << std::fixed << std::setprecision(3) << earned / possible << "\n\n";
    }

    return out.str();
}

std::string gradebook::assignment_report(const std::string& aname) {
    std::ostringstream out;

    double earned = 0;
    double count = 0;
    double total = 0;

    for (auto& s : classroom) {
        out << "---- " << s.get_name() << " ----\n";

        std::vector<assignment> work = s.get_assignments();

        bool found = false;
        for (auto& a : work) {
            if (a.get_name() == aname) {
                found = true;
                int g = a.get_grade();
                total = a.get_total();

                out << a.get_name() << ": ";
                if (g == -1) out << "Not scored /" << a.get_total() << "\n\n";
                else {
                    out << g << "/" << a.get_total() << "\n\n";
                    earned += g;
                    count += 1;
                }
                break;
            }
        }

        if (!found) out << "Not scored /?\n\n";
    }

    out << "Average score: ";
    if (count == 0) out << "none";
    else out << std::fixed << std::setprecision(1) << (earned / count);
    out << " / " << total;

    return out.str();
}