#include <catch2/catch_test_macros.hpp>
#include <string>
#include "cs.h"

TEST_CASE("Create Class", "[Cs]")
{
  using festlib::xml::Cs;

  Cs reseptgruppe{"B", "Reseptgruppe B"};
  std::string v{reseptgruppe.value()};
  std::string l{reseptgruppe.long_value()};

  REQUIRE(v.compare("B") == 0);
  REQUIRE(l.compare("Reseptgruppe B") == 0);
}

TEST_CASE("Create empty", "[Cs]")
{
  using festlib::xml::Cs;

  Cs cs{};

  std::string v{cs.value()};
  std::string dn{cs.long_value()};

  REQUIRE(v.length() == 0);
  REQUIRE(dn.length() == 0);
}

TEST_CASE("Copy assignment operator", "[Cs]")
{
  using festlib::xml::Cs;

  Cs gruppe_a{"A", "Reseptgruppe A"};
  Cs gruppe_b{"B", "Reseptgruppe B"};

  std::string a_v{gruppe_a.value()};
  std::string a_dn{gruppe_a.long_value()};

  REQUIRE(a_v.compare("A") == 0);
  REQUIRE(a_dn.compare("Reseptgruppe A") == 0);

  std::string b_v{gruppe_b.value()};
  std::string b_dn{gruppe_b.long_value()};

  REQUIRE(b_v.compare("B") == 0);
  REQUIRE(b_dn.compare("Reseptgruppe B") == 0);

  // copy
  gruppe_a = gruppe_b;
  std::string new_a_v{gruppe_a.value()};
  std::string new_a_dn{gruppe_a.long_value()};

  REQUIRE(new_a_v.compare("B") == 0);
  REQUIRE(new_a_dn.compare("Reseptgruppe B") == 0);
}

TEST_CASE("Operator ==", "[Cs]")
{
  using festlib::xml::Cs;

  Cs reseptgruppe{"B", "Reseptgruppe B"};
  REQUIRE(reseptgruppe == "B");
}
