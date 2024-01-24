#include "festlib.h"
#include <catch2/catch_all.hpp>

const char xml_string[] =
    "<?xml version='1.0' encoding='utf-8'?><FEST "
    "xmlns:xsd='http://www.w3.org/2001/XMLSchema' "
    "xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' "
    "xmlns='http://www.kith.no/xmlstds/eresept/m30/"
    "2014-12-01'><HentetDato>2023-09-08T03:11:43</"
    "HentetDato><KatLegemiddelMerkevare><OppfLegemiddelMerkevare><Id>ID_"
    "DE995772-8BBC-4164-8A0C-044CFC522794</"
    "Id><Tidspunkt>2023-06-05T03:11:16</Tidspunkt><Status V='A' DN='Aktiv "
    "oppføring' /><LegemiddelMerkevare "
    "xmlns='http://www.kith.no/xmlstds/eresept/forskrivning/2014-12-01'><Atc "
    "V='N02AJ07' S='2.16.578.1.12.4.1.1.7180' DN='Kodein og "
    "acetylsalisylsyre' /><NavnFormStyrke>Kodimagnyl Ikke-stoppende dak tab "
    "9,6 mg/500 mg/150 mg</NavnFormStyrke><Reseptgruppe V='B' "
    "DN='Reseptgruppe B' /><LegemiddelformKort V='53' "
    "S='2.16.578.1.12.4.1.1.7448' DN='Tablett' "
    "/><RefVilkar>ID_491E7F6C-23A9-45C3-A906-95A1332AD5BD</"
    "RefVilkar><Preparattype V='11' DN='Krever godkj. Fritak' "
    "/><TypeSoknadSlv V='2' DN='Søknad vurderes av apotek' "
    "/><Opioidsoknad>true</"
    "Opioidsoknad><AdministreringLegemiddel><Administrasjonsvei V='53' "
    "S='2.16.578.1.12.4.1.1.7477' DN='Oral bruk' /><EnhetDosering V='13' "
    "S='2.16.578.1.12.4.1.1.7480' DN='tablett' "
    "/></"
    "AdministreringLegemiddel><Id>ID_000A27B8-3930-4264-80F9-CDB14C895662</"
    "Id><Varenavn>Kodimagnyl Ikke-stoppende "
    "dak</Varenavn><LegemiddelformLang>Tablett, "
    "filmdrasjert</"
    "LegemiddelformLang><SortertVirkestoffMedStyrke><Sortering>0</"
    "Sortering><RefVirkestoffMedStyrke>ID_A0DBC88E-864A-4231-BA8F-"
    "DFCA3D00F599</RefVirkestoffMedStyrke></"
    "SortertVirkestoffMedStyrke><SortertVirkestoffMedStyrke><Sortering>1</"
    "Sortering><RefVirkestoffMedStyrke>ID_32FD98A6-2F11-43E5-B328-"
    "18567E32C5C4</RefVirkestoffMedStyrke></"
    "SortertVirkestoffMedStyrke><SortertVirkestoffMedStyrke><Sortering>2</"
    "Sortering><RefVirkestoffMedStyrke>ID_A22E070F-7B94-46D5-B0DE-"
    "2476A2429868</RefVirkestoffMedStyrke></"
    "SortertVirkestoffMedStyrke><ProduktInfo><Produsent>Orifarm "
    "Healthcare</Produsent></ProduktInfo><Reseptgyldighet><Varighet>P1Y</"
    "Varighet></Reseptgyldighet></LegemiddelMerkevare></"
    "OppfLegemiddelMerkevare></KatLegemiddelMerkevare></FEST>";

TEST_CASE("Load xml file", "[Festlib]") {
  using festlib::Festlib;

  Festlib fest{};
  REQUIRE_THROWS_AS(fest.load_file("nofile.xml"),
                    festlib::exceptions::FileNotFound);
}

TEST_CASE("Load xml string", "[Festlib]") {
  using festlib::Festlib;

  Festlib fest{};
  fest.load_string(xml_string);
  REQUIRE_NOTHROW(fest);
}

TEST_CASE("Get created date from node", "[Festlib]") {
  using festlib::Festlib;

  Festlib fest{};

  fest.load_string(xml_string);
  auto date = created_date(fest);

  REQUIRE(date.compare("2023-09-08T03:11:43") == 0);
}
