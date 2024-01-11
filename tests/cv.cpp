#include <catch2/catch_all.hpp>
#include "cv.h"

TEST_CASE("Create Class", "[Cv]")
{
  using festlib::xml::Cv;

  Cv atc{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  std::string v{atc.value()};
  std::string l{atc.long_value()};

  REQUIRE(v.compare("C07AA05") == 0);
  REQUIRE(l.compare("Propranolol") == 0);
}

TEST_CASE("Create empty", "[Cv]")
{
  using festlib::xml::Cv;

  Cv cv{};

  std::string v{cv.value()};
  std::string dn{cv.long_value()};

  REQUIRE(v.length() == 0);
  REQUIRE(dn.length() == 0);
}

TEST_CASE("Copy assignment operator", "[Cv]")
{
  using festlib::xml::Cv;

  Cv atc_a{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  Cv atc_b{"N02AJ07", "2.16.578.1.12.4.1.1.7180", "Kodein og acetylsalisylsyre"};

  std::string a_v{atc_a.value()};
  std::string a_dn{atc_a.long_value()};

  REQUIRE(a_v.compare("C07AA05") == 0);
  REQUIRE(a_dn.compare("Propranolol") == 0);

  std::string b_v{atc_b.value()};
  std::string b_dn{atc_b.long_value()};

  REQUIRE(b_v.compare("N02AJ07") == 0);
  REQUIRE(b_dn.compare("Kodein og acetylsalisylsyre") == 0);

  // copy
  atc_a = atc_b;
  std::string new_a_v{atc_a.value()};
  std::string new_a_dn{atc_a.long_value()};

  REQUIRE(new_a_v.compare("N02AJ07") == 0);
  REQUIRE(new_a_dn.compare("Kodein og acetylsalisylsyre") == 0);
}

TEST_CASE("Operator ==", "[Cv]")
{
  using festlib::xml::Cv;

  Cv atc{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  Cv atc_2{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  REQUIRE(atc == atc_2);
}
