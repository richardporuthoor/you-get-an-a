#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/student.hpp"
#include "../src/assignment.hpp"

// TEST_CASE( "tests if assignments get added to student" ) {
//     student new_guy = student("kasper", "kaminski", "ABC123");
//     new_guy.add_assignment("quiz 1", 100);
//     new_guy.add_assignment("quiz 2", 100);
//     new_guy.add_assignment("quiz 3", 100);
    
//     REQUIRE(new_guy.assignments.size() == 3);
// }