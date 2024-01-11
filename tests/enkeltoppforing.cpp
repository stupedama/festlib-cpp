#include <catch2/catch_all.hpp>
#include "enkeltoppforing.h"

TEST_CASE("Enkeltoppforing Class", "[enkeltoppforing]")
{
  using festlib::xml::Enkeltoppforing;

  Enkeltoppforing oppforing{"ID_DE995772-8BBC-4164-8A0C-044CFC522794", "2023-06-05T03:11:16", true};

  std::string id{oppforing.id()};
  std::string date{oppforing.date()};
  bool status{oppforing.status()};

  REQUIRE(id.compare(oppforing.id()) == 0);
  REQUIRE(id.compare("ID_DE995772-8BBC-4164-8A0C-044CFC522794") == 0);
  REQUIRE(date.compare("2023-06-05T03:11:16") == 0);
  REQUIRE(status == true);
}

TEST_CASE("Operator ==", "[enkeltoppforing]")
{
  using festlib::xml::Enkeltoppforing;

  Enkeltoppforing oppforing{"ID_DE995772-8BBC-4164-8A0C-044CFC522794", "2023-06-05T03:11:16", true};

  REQUIRE(oppforing == "ID_DE995772-8BBC-4164-8A0C-044CFC522794");
}
