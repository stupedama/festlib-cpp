#include "cs.h"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Create Class", "[Cs]") {
  using festlib::xml::Cs;

  Cs reseptgruppe{"B", "Reseptgruppe B"};
  std::string v{reseptgruppe.value()};
  std::string l{reseptgruppe.long_value()};

  REQUIRE(v.compare("B") == 0);
  REQUIRE(l.compare("Reseptgruppe B") == 0);
}

TEST_CASE("Create empty", "[Cs]") {
  using festlib::xml::Cs;

  Cs cs{};

  std::string v{cs.value()};
  std::string dn{cs.long_value()};

  REQUIRE(v.length() == 0);
  REQUIRE(dn.length() == 0);
}

TEST_CASE("Operator ==", "[Cs]") {
  using festlib::xml::Cs;

  Cs reseptgruppe{"B", "Reseptgruppe B"};
  REQUIRE(reseptgruppe == "B");
}
