#include <catch2/catch_test_macros.hpp>
#include <string>
#include "cs.h"
#include "festlib.h"
#include "legemiddel.h"

TEST_CASE("Create Class from xml string", "[Legemiddel]")
{
  using festlib::Festlib;
  using Name = std::string;
  using Reference = std::string;

  const char xml_string[] = "<?xml version='1.0' encoding='utf-8'?><FEST xmlns:xsd='http://www.w3.org/2001/XMLSchema' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns='http://www.kith.no/xmlstds/eresept/m30/2014-12-01'><HentetDato>2023-09-08T03:11:43</HentetDato><KatLegemiddelMerkevare><OppfLegemiddelMerkevare><Id>ID_DE995772-8BBC-4164-8A0C-044CFC522794</Id><Tidspunkt>2023-06-05T03:11:16</Tidspunkt><Status V='A' DN='Aktiv oppføring' /><LegemiddelMerkevare xmlns='http://www.kith.no/xmlstds/eresept/forskrivning/2014-12-01'><Atc V='N02AJ07' S='2.16.578.1.12.4.1.1.7180' DN='Kodein og acetylsalisylsyre' /><NavnFormStyrke>Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg</NavnFormStyrke><Reseptgruppe V='B' DN='Reseptgruppe B' /><LegemiddelformKort V='53' S='2.16.578.1.12.4.1.1.7448' DN='Tablett' /><RefVilkar>ID_491E7F6C-23A9-45C3-A906-95A1332AD5BD</RefVilkar><Preparattype V='11' DN='Krever godkj. Fritak' /><TypeSoknadSlv V='2' DN='Søknad vurderes av apotek' /><Opioidsoknad>true</Opioidsoknad><AdministreringLegemiddel><Administrasjonsvei V='53' S='2.16.578.1.12.4.1.1.7477' DN='Oral bruk' /><EnhetDosering V='13' S='2.16.578.1.12.4.1.1.7480' DN='tablett' /></AdministreringLegemiddel><Id>ID_000A27B8-3930-4264-80F9-CDB14C895662</Id><Varenavn>Kodimagnyl Ikke-stoppende dak</Varenavn><LegemiddelformLang>Tablett, filmdrasjert</LegemiddelformLang><SortertVirkestoffMedStyrke><Sortering>0</Sortering><RefVirkestoffMedStyrke>ID_A0DBC88E-864A-4231-BA8F-DFCA3D00F599</RefVirkestoffMedStyrke></SortertVirkestoffMedStyrke><SortertVirkestoffMedStyrke><Sortering>1</Sortering><RefVirkestoffMedStyrke>ID_32FD98A6-2F11-43E5-B328-18567E32C5C4</RefVirkestoffMedStyrke></SortertVirkestoffMedStyrke><SortertVirkestoffMedStyrke><Sortering>2</Sortering><RefVirkestoffMedStyrke>ID_A22E070F-7B94-46D5-B0DE-2476A2429868</RefVirkestoffMedStyrke></SortertVirkestoffMedStyrke><ProduktInfo><Produsent>Orifarm Healthcare</Produsent></ProduktInfo><Reseptgyldighet><Varighet>P1Y</Varighet></Reseptgyldighet></LegemiddelMerkevare></OppfLegemiddelMerkevare></KatLegemiddelMerkevare></FEST>";

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
  festlib::xml::Legemiddel lm = festlib::xml::get_legemiddel(node);

  festlib::xml::Cv atc = lm.atc();
  REQUIRE(atc == "N02AJ07");

  Name navnformstyrke = lm.navnformstyrke();
  REQUIRE(navnformstyrke.compare("Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg") == 0);

  festlib::xml::Cs reseptgruppe = lm.reseptgruppe();
  REQUIRE(reseptgruppe == "B");

  festlib::xml::Cv legemiddelform = lm.legemiddelformkort();
  REQUIRE(legemiddelform == "53");

  Reference refvilkar = lm.refvilkar();
  REQUIRE(refvilkar.compare("ID_491E7F6C-23A9-45C3-A906-95A1332AD5BD") == 0);

  festlib::xml::Cs preparattype = lm.preparattype();
  REQUIRE(preparattype == "11");

  festlib::xml::Cs typesoknadslv = lm.typesoknadslv();
  REQUIRE(typesoknadslv == "2");

  bool opioidsoknad = lm.opioidsoknad();
  REQUIRE(opioidsoknad == true);

  // there is no svarttrekant in this source.
  // so it should be empty
  festlib::xml::Cv svarttrekant = lm.svarttrekant();
  REQUIRE(svarttrekant.value().length() == 0);

  std::optional<festlib::xml::Refusjon> refusjon = lm.refusjon();
  REQUIRE(refusjon.has_value() == false);
}

TEST_CASE("Testing refusjon in legemiddel", "[Legemiddel]")
{
  using festlib::Festlib;

  const char xml_string[] = "<?xml version='1.0' encoding='utf-8'?><FEST xmlns:xsd='http://www.w3.org/2001/XMLSchema' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns='http://www.kith.no/xmlstds/eresept/m30/2014-12-01'><HentetDato>2023-09-08T03:11:43</HentetDato><KatLegemiddelpakning><OppfLegemiddelpakning><Id>ID_9453E041-D1D0-42BA-812F-59A3C54A1C20</Id><Tidspunkt>2022-12-20T03:10:47</Tidspunkt><Status V='A' DN='Aktiv oppføring' /><Legemiddelpakning xmlns='http://www.kith.no/xmlstds/eresept/forskrivning/2014-12-01'><Atc V='N05CF02' S='2.16.578.1.12.4.1.1.7180' DN='Zolpidem' /><NavnFormStyrke>Zolpidem Dune tab 10 mg</NavnFormStyrke><Reseptgruppe V='B' DN='Reseptgruppe B' /><LegemiddelformKort V='53' S='2.16.578.1.12.4.1.1.7448' DN='Tablett' /><Preparattype V='7' DN='Legemiddel' /><TypeSoknadSlv V='1' DN='Skal ikke søkes' /><Refusjon><RefRefusjonsgruppe>ID_18258D51-519E-47AC-9430-D284BA1A1514</RefRefusjonsgruppe><GyldigFraDato>2023-01-01</GyldigFraDato></Refusjon><PakningByttegruppe><RefByttegruppe>ID_BF16B775-2109-41A1-8369-2230FDE6B0EE</RefByttegruppe><GyldigFraDato>2023-01-01</GyldigFraDato></PakningByttegruppe><Id>ID_0008426A-FCA1-4CA1-9202-7D7D5B2922C2</Id><Varenr>526181</Varenr><Ean>5745000695003</Ean><Oppbevaring V='R' DN='Rom (15-25 grader)' /><Pakningsinfo><RefLegemiddelMerkevare>ID_D9ECF4A9-FE22-401D-AA86-31ACA65EFAC2</RefLegemiddelMerkevare><Pakningsstr>7</Pakningsstr><EnhetPakning V='stk' S='2.16.578.1.12.4.1.1.7452' DN='stykk' /><Pakningstype V='169' S='2.16.578.1.12.4.1.1.7449' DN='Blisterpakning' /><Mengde>7</Mengde><DDD V='0.01' U='g' /><Statistikkfaktor>0.07</Statistikkfaktor></Pakningsinfo><PrisVare><Type V='3' S='2.16.578.1.12.4.1.1.7453' DN='AIP' /><Pris V='7.69' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type V='2' S='2.16.578.1.12.4.1.1.7453' DN='Refusjonspris' /><Pris V='69.8' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type V='4' S='2.16.578.1.12.4.1.1.7453' DN='AUP' /><Pris V='69.8' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><Markedsforingsinfo><Markedsforingsdato>2023-01-01</Markedsforingsdato></Markedsforingsinfo></Legemiddelpakning></OppfLegemiddelpakning></FEST>";

  Festlib fest{};
  fest.load_string(xml_string);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
  festlib::xml::Legemiddel lm = festlib::xml::get_legemiddel(node);

  REQUIRE(lm.refusjon().has_value() == true);

  auto refusjon = lm.refusjon().value();
  REQUIRE(refusjon.gyldigfradato().compare("2023-01-01") == 0);
}
