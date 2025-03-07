#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include <string>  // Required for std::string
#include <vector>  // Required for std::vector

TEST_CASE("Basic Arithmetic Test") {
    REQUIRE(1 + 1 == 2);
    REQUIRE(2 * 2 == 4);
}

TEST_CASE("String Comparison Test") {
    std::string str = "Hello, Catch2!";
    REQUIRE(str == "Hello, Catch2!");
}

TEST_CASE("Vector Size Test") {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    REQUIRE(numbers.size() == 5);
}
