#include "pakningskomponent.h"
#include <catch2/catch_test_macros.hpp>
// #include "festlib.h"

TEST_CASE("Create empty pakningskomponent", "[Pakningskomponent]") {
  festlib::xml::Pakningskomponent komponent{};
  REQUIRE(true == false);
}
