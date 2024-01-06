#include <catch2/catch_all.hpp>
#include "festlib.h"

TEST_CASE("Load xml file", "[festlib]") {
  using festlib::Festlib;

  Festlib fest(std::string_view{"hello.txt"});

  REQUIRE(true == true);
}
