#include <catch2/catch_test_macros.hpp>
#include "festlib.h"
#include "pakningbyttegruppe.h"

TEST_CASE("Get the value of a pakningbyttegruppe", "[PakningByttegruppe]")
{
  using festlib::Festlib;
  using festlib::xml::PakningByttegruppe;

  const char xml_string[] = "<?xml version='1.0' encoding='utf-8'?><FEST xmlns:xsd='http://www.w3.org/2001/XMLSchema' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns='http://www.kith.no/xmlstds/eresept/m30/2014-12-01'><HentetDato>2023-09-08T03:11:43</HentetDato><KatLegemiddelpakning><OppfLegemiddelpakning><Id>ID_9453E041-D1D0-42BA-812F-59A3C54A1C20</Id><Tidspunkt>2022-12-20T03:10:47</Tidspunkt><Status V='A' DN='Aktiv oppføring' /><Legemiddelpakning xmlns='http://www.kith.no/xmlstds/eresept/forskrivning/2014-12-01'><Atc V='N05CF02' S='2.16.578.1.12.4.1.1.7180' DN='Zolpidem' /><NavnFormStyrke>Zolpidem Dune tab 10 mg</NavnFormStyrke><Reseptgruppe V='B' DN='Reseptgruppe B' /><LegemiddelformKort V='53' S='2.16.578.1.12.4.1.1.7448' DN='Tablett' /><Preparattype V='7' DN='Legemiddel' /><TypeSoknadSlv V='1' DN='Skal ikke søkes' /><Refusjon><RefRefusjonsgruppe>ID_18258D51-519E-47AC-9430-D284BA1A1514</RefRefusjonsgruppe><GyldigFraDato>2023-01-01</GyldigFraDato></Refusjon><PakningByttegruppe><RefByttegruppe>ID_BF16B775-2109-41A1-8369-2230FDE6B0EE</RefByttegruppe><GyldigFraDato>2023-01-01</GyldigFraDato></PakningByttegruppe><Id>ID_0008426A-FCA1-4CA1-9202-7D7D5B2922C2</Id><Varenr>526181</Varenr><Ean>5745000695003</Ean><Oppbevaring V='R' DN='Rom (15-25 grader)' /><Pakningsinfo><RefLegemiddelMerkevare>ID_D9ECF4A9-FE22-401D-AA86-31ACA65EFAC2</RefLegemiddelMerkevare><Pakningsstr>7</Pakningsstr><EnhetPakning V='stk' S='2.16.578.1.12.4.1.1.7452' DN='stykk' /><Pakningstype V='169' S='2.16.578.1.12.4.1.1.7449' DN='Blisterpakning' /><Mengde>7</Mengde><DDD V='0.01' U='g' /><Statistikkfaktor>0.07</Statistikkfaktor></Pakningsinfo><PrisVare><Type V='3' S='2.16.578.1.12.4.1.1.7453' DN='AIP' /><Pris V='7.69' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type V='2' S='2.16.578.1.12.4.1.1.7453' DN='Refusjonspris' /><Pris V='69.8' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><PrisVare><Type V='4' S='2.16.578.1.12.4.1.1.7453' DN='AUP' /><Pris V='69.8' U='NOK' /><GyldigFraDato>2023-01-01</GyldigFraDato></PrisVare><Markedsforingsinfo><Markedsforingsdato>2023-01-01</Markedsforingsdato></Markedsforingsinfo></Legemiddelpakning></OppfLegemiddelpakning></FEST>";

  Festlib fest{};
  auto res = fest.load_string(xml_string);

  REQUIRE(res == true);

  pugi::xml_node node = fest.get_node();
  node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");

  auto pakningbyttegruppe = festlib::xml::get_pakningbyttegruppe(node);
  REQUIRE(pakningbyttegruppe.refbyttegruppe().compare("ID_BF16B775-2109-41A1-8369-2230FDE6B0EE") == 0);
  REQUIRE(pakningbyttegruppe.gyldigfradato().compare("2023-01-01") == 0);
  REQUIRE(pakningbyttegruppe.gyldigtildato().has_value() == false);
}
