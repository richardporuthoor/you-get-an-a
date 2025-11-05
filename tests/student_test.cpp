#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <iostream>
#include <vector>
#include "string"
#include "../src/assignment.hpp"
#include "../src/gradebook.hpp"
#include "../src/student.hpp"
#include "../src/gradebook_printer.hpp"

TEST_CASE( "tests if assignments get added to student" ) {
    gradebook classroom;
    gradebook_printer printer;

    classroom.add_student("kasper kaminski", "ABC123");
    classroom.add_assignment("Quiz 1", 100);

    std::string output = printer.pretty_print(classroom);

    REQUIRE (output == "---- kasper kaminski ----\nQuiz 1: Not scored /100\n\n\n");
}

TEST_CASE( "tests multiple students and assignments" ) {
    gradebook classroom;
    gradebook_printer printer;

    classroom.add_student("kasper kaminski", "ABC123");
    classroom.add_student("richard poruthoor", "xyz987");
    classroom.add_assignment("Quiz 1", 100);
    classroom.add_assignment("Quiz 2", 100);

    std::string output = printer.pretty_print(classroom);

    REQUIRE (output == "---- kasper kaminski ----\nQuiz 1: Not scored /100\nQuiz 2: Not scored /100\n\n\n---- richard poruthoor ----\nQuiz 1: Not scored /100\nQuiz 2: Not scored /100\n\n\n");
}

TEST_CASE( "tests entering grades" ) {
    gradebook classroom;
    gradebook_printer printer;

    classroom.add_student("kasper kaminski", "ABC123");
    classroom.add_student("richard poruthoor", "xyz987");
    classroom.add_assignment("Quiz 1", 100);
    classroom.add_assignment("Quiz 2", 100);

    classroom.enter_grade("kasper kaminski", "Quiz 1", 90);
    classroom.enter_grade("richard poruthoor", "Quiz 2", 80);

    std::string output = printer.pretty_print(classroom);

    REQUIRE (output == "---- kasper kaminski ----\nQuiz 1: 90/100\nQuiz 2: Not scored /100\n\n\n---- richard poruthoor ----\nQuiz 1: Not scored /100\nQuiz 2: 80/100\n\n\n");
}