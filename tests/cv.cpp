#include "cv.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Create Class", "[Cv]") {
  using festlib::xml::Cv;

  Cv atc{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  std::string v{atc.value()};
  std::string l{atc.long_value()};

  REQUIRE(v.compare("C07AA05") == 0);
  REQUIRE(l.compare("Propranolol") == 0);
}

TEST_CASE("Operator ==", "[Cv]") {
  using festlib::xml::Cv;

  Cv atc{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  Cv atc_2{"C07AA05", "2.16.578.1.12.4.1.1.7180", "Propranolol"};
  REQUIRE(atc == atc_2);
}
