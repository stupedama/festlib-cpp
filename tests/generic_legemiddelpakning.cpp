#include "festlib.h"
#include "legemiddelpakning.h"
#include <catch2/catch_test_macros.hpp>

const char xml_string[] =
    "<?xml version='1.0' encoding='utf-8'?><FEST "
    "xmlns:xsd='http://www.w3.org/2001/XMLSchema' "
    "xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' "
    "xmlns='http://www.kith.no/xmlstds/eresept/m30/"
    "2014-12-01'><HentetDato>2023-09-08T03:11:43</"
    "HentetDato><KatLegemiddelpakning><OppfLegemiddelpakning><Id>ID_9453E041-"
    "D1D0-42BA-812F-59A3C54A1C20</Id><Tidspunkt>2022-12-20T03:10:47</"
    "Tidspunkt><Status V='A' DN='Aktiv oppføring' /><Legemiddelpakning "
    "xmlns='http://www.kith.no/xmlstds/eresept/forskrivning/2014-12-01'><Atc "
    "V='N05CF02' S='2.16.578.1.12.4.1.1.7180' DN='Zolpidem' "
    "/><NavnFormStyrke>Zolpidem Dune tab 10 mg</NavnFormStyrke><Reseptgruppe "
    "V='B' DN='Reseptgruppe B' /><LegemiddelformKort V='53' "
    "S='2.16.578.1.12.4.1.1.7448' DN='Tablett' /><Preparattype V='7' "
    "DN='Legemiddel' /><TypeSoknadSlv V='1' DN='Skal ikke søkes' "
    "/><Refusjon><RefRefusjonsgruppe>ID_18258D51-519E-47AC-9430-D284BA1A1514<"
    "/RefRefusjonsgruppe><GyldigFraDato>2023-01-01</GyldigFraDato></"
    "Refusjon><PakningByttegruppe><RefByttegruppe>ID_BF16B775-2109-41A1-8369-"
    "2230FDE6B0EE</RefByttegruppe><GyldigFraDato>2023-01-01</GyldigFraDato></"
    "PakningByttegruppe><Id>ID_0008426A-FCA1-4CA1-9202-7D7D5B2922C2</"
    "Id><Varenr>526181</Varenr><Ean>5745000695003</Ean><Oppbevaring V='R' "
    "DN='Rom (15-25 grader)' "
    "/><Pakningsinfo><RefLegemiddelMerkevare>ID_D9ECF4A9-FE22-401D-AA86-"
    "31ACA65EFAC2</RefLegemiddelMerkevare><Pakningsstr>7</"
    "Pakningsstr><EnhetPakning V='stk' S='2.16.578.1.12.4.1.1.7452' "
    "DN='stykk' /><Pakningstype V='169' S='2.16.578.1.12.4.1.1.7449' "
    "DN='Blisterpakning' /><Mengde>7</Mengde><DDD V='0.01' U='g' "
    "/><Statistikkfaktor>0.07</Statistikkfaktor></"
    "Pakningsinfo><PrisVare><Type V='3' S='2.16.578.1.12.4.1.1.7453' "
    "DN='AIP' /><Pris V='7.69' U='NOK' "
    "/><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type "
    "V='2' S='2.16.578.1.12.4.1.1.7453' DN='Refusjonspris' /><Pris V='69.8' "
    "U='NOK' "
    "/><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type "
    "V='4' S='2.16.578.1.12.4.1.1.7453' DN='AUP' /><Pris V='69.8' U='NOK' "
    "/><GyldigFraDato>2023-01-01</GyldigFraDato></"
    "PrisVare><Markedsforingsinfo><Markedsforingsdato>2023-01-01</"
    "Markedsforingsdato></Markedsforingsinfo></Legemiddelpakning></"
    "OppfLegemiddelpakning></KatLegemiddelpakning></FEST>";

TEST_CASE("Search generic by varenr", "[Generic legemiddelpakning]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning");

  auto legemiddelpakning = festlib::xml::get_legemiddelpakning(node);

  node = node.child("Legemiddelpakning");

  auto catalog = festlib::catalog_legemiddelpakning(fest);
  auto pakning = festlib::find_legemiddelpakning(catalog, "526181");
  REQUIRE(catalog.size() == 1);

  auto generic = festlib::generic_legemiddelpakning(catalog, pakning);
  REQUIRE(generic.size() == 1);
}

TEST_CASE("Search generic by varenr that does not exist",
          "[Generic legemiddelpakning]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning");

  auto legemiddelpakning = festlib::xml::get_legemiddelpakning(node);

  node = node.child("Legemiddelpakning");

  auto catalog = festlib::catalog_legemiddelpakning(fest);
  auto pakning = festlib::find_legemiddelpakning(catalog, "55444");

  auto generic = festlib::generic_legemiddelpakning(catalog, pakning);
  REQUIRE(generic.size() == 0);
}

TEST_CASE("Search generic by pakningbyttegruppe reference",
          "[Generic legemiddelpakning]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning");

  auto legemiddelpakning = festlib::xml::get_legemiddelpakning(node);

  node = node.child("Legemiddelpakning");

  auto catalog = festlib::catalog_legemiddelpakning(fest);

  auto generic = festlib::generic_legemiddelpakning(
      catalog, "ID_BF16B775-2109-41A1-8369-2230FDE6B0EE");
  REQUIRE(generic.size() == 1);
}

TEST_CASE("Search generic by non existing pakningbyttegruppe reference",
          "[Generic legemiddelpakning]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning");

  auto legemiddelpakning = festlib::xml::get_legemiddelpakning(node);

  node = node.child("Legemiddelpakning");

  auto catalog = festlib::catalog_legemiddelpakning(fest);

  auto generic = festlib::generic_legemiddelpakning(
      catalog, "ID_BF16B775-2109-41A2-8369-2230FDE6B0EE");
  REQUIRE(generic.size() == 0);
}
