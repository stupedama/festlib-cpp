#include "pq.h"
#include <catch2/catch_test_macros.hpp>
// #include "festlib.h"

TEST_CASE("Create empty pq", "[Pq]") {
  festlib::xml::Pq pq{};
  REQUIRE(pq.u.size() == 0);
}
