#include "pq.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Create empty pq", "[Pq]") {
  using festlib::xml::Pq;

  Pq pq{};
  REQUIRE(pq.u.size() == 0);
}

TEST_CASE("Create class Pq", "[Pq]") {
  using festlib::xml::Pq;

  Pq pq{"V", "U"};

  REQUIRE(pq.v.compare("V") == 0);
  REQUIRE(pq.u.compare("U") == 0);
}
