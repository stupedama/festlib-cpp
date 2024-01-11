#include <catch2/catch_all.hpp>
#include "festlib.h"

TEST_CASE("Load xml file", "[festlib]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_file("fest251.xml");

  REQUIRE_NOTHROW(fest);
}
