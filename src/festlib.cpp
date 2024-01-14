#include "festlib.h"

namespace festlib {

  Festlib::Festlib()
    : m_doc{}, m_parse_result{}, m_result{false}
  {
  }

  bool Festlib::load_file(std::string_view filename)
  {
    m_parse_result = m_doc.load_file(filename.data(), pugi::encoding_utf8);

    if(m_parse_result == 0)
      m_result = true;

    return m_result;
  }

  bool Festlib::load_string(std::string_view xml_string)
  {
    m_parse_result = m_doc.load_string(xml_string.data(), pugi::encoding_utf8);

    if(m_parse_result == 0)
      m_result = true;

    return m_result;
  }

  // return the root of the Fest XML
  pugi::xml_node Festlib::get_node() const
  {
    return m_doc.child("FEST");
  }

  // no--member functions

  namespace {

    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute)
    {
      pugi::xml_node child = node;

      if(attribute.length() > 0)
      {
        child = node.child(attribute.data());
      }

      std::string_view v{child.attribute("V").value()};
      std::string_view s{child.attribute("S").value()};
      std::string_view dn{child.attribute("DN").value()};

      return xml::Cv{v, s, dn};
    }

    xml::Cs get_cs(const pugi::xml_node& node, std::string_view attribute)
    {
      pugi::xml_node child = node;

      if(attribute.length() > 0)
      {
        child = node.child(attribute.data());
      }

      std::string_view v{child.attribute("V").value()};
      std::string_view dn{child.attribute("DN").value()};

      return xml::Cs{v, dn};
    }

    Value get_value(const pugi::xml_node& node, std::string_view attribute)
    {
      if(attribute.length() > 0)
      {
        return node.child_value(attribute.data());
      } else {
        return node.child_value();
      }
  }

    xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node& node)
    {
      std::string_view id{get_value(node, "Id")};
      std::string_view date{get_value(node, "Tidspunkt")}; // Tidspunkt = Entry date
      std::string_view status{node.child("Status").first_attribute().value()};

      bool oppforing_status{false};

      if(status.compare("A") == 0)
        oppforing_status = true;

      return xml::Enkeltoppforing{id, date, oppforing_status};
    }

    xml::Legemiddel get_legemiddel(const pugi::xml_node& node)
    {
      using festlib::xml::Cv;
      using festlib::xml::Cs;

      const Cv atc{get_cv(node, "Atc")};
      const std::string navnformstyrke{get_value(node, "NavnFormStyrke")};
      const Cs reseptgruppe{get_cs(node, "Reseptgruppe")};
      const Cv legemiddelformkort{get_cv(node, "LegemiddelformKort")};
      const std::string refvilkar{get_value(node, "RefVilkar")};
      const Cs preparattype{get_cs(node, "Preparattype")};
      const Cs typesoknadslv{get_cs(node, "TypeSoknadSlv")};

      // get OpioidSoknad. It is stored as a string value: true or false
      const std::string opioid_string{get_value(node, "Opioidsoknad")};
      bool opioid{false};

      if(opioid_string.compare("true") == 0)
        opioid = true;

      const Cv svarttrekant{get_cv(node, "SvartTrekant")};

      const xml::Refusjon refusjon{get_refusjon(node)};
      const xml::PakningByttegruppe byttegruppe{get_pakningbyttegruppe(node)};

      return xml::Legemiddel{atc, navnformstyrke, reseptgruppe, legemiddelformkort,
        refvilkar, preparattype, typesoknadslv, opioid, svarttrekant, refusjon, byttegruppe};
    }

    xml::Refusjon get_refusjon(const pugi::xml_node& node)
    {
      const pugi::xml_node refusjon_node{node.child("Refusjon")};

      const Container<xml::IDREF> refrefusjonsgruppe{get_container<xml::IDREF>(refusjon_node, "RefRefusjonsgruppe", [](const pugi::xml_node& n)
      {
        xml::IDREF ref{get_value(n)};
        return ref;
      })};

      const Date gyldigfradato{get_value(refusjon_node, "GyldigFraDato")};
      const Date forskrivestildato{get_value(refusjon_node, "ForskrivesTilDato")};
      const Date utleverestildato{get_value(refusjon_node, "UtleveresTilDato")};

      return xml::Refusjon{refrefusjonsgruppe, gyldigfradato, forskrivestildato, utleverestildato};
    }

    xml::Preparatomtaleavsnitt get_preparatomtaleavsnitt(const pugi::xml_node& node)
    {
      const pugi::xml_node avsnitt_node{node.child("Preparatomtaleavsnitt")};

      const xml::Cs avsnittoverskrift = get_cs(avsnitt_node, "Avsnittoverskrift");
      const xml::Lenke lenke = get_lenke(avsnitt_node);

      return xml::Preparatomtaleavsnitt{avsnittoverskrift, lenke};
    }

    xml::Lenke get_lenke(const pugi::xml_node& node)
    {
      const pugi::xml_node lenke_node{node.child("Lenke").child("Www")};
      return lenke_node.attribute("V").value();
    }

    xml::AdministreringLegemiddel get_administreringlegemiddel(const pugi::xml_node& node)
    {
      using festlib::xml::Cv;
      using festlib::xml::Cs;

      const pugi::xml_node admin_node{node.child("AdministreringLegemiddel")};

      // TODO: use the pugi:: to return .bool()
      bool blandingsveske{false};
      const std::string blandingsveske_string{get_value(admin_node, "Blandingsveske")};

      if(blandingsveske_string.compare("true") == 0)
        blandingsveske = true;

      const Container<xml::IDREF> refbladingsveske{get_container<xml::IDREF>(admin_node, "RefBlandingsVeske", [](const pugi::xml_node& n)
      {
        xml::IDREF ref{get_value(n)};
        return ref;
      })};

      const Container<Cv> administrasjonsvei{get_container<Cv>(admin_node, "Administrasjonsvei", [](const pugi::xml_node& n)
      {
        Cv vei{get_cv(n)};
        return vei;
      })};

      const Cs kanknuses{get_cs(node, "KanKnuses")};
      const Cs kanapnes{get_cs(node, "KanApnes")};
      const Cs bolus{get_cs(node, "Bolus")};
      const Cs injeksjonshastighetbolus{get_cs(node, "InjeksjonshastighetBolus")};
      const Cs deling{get_cs(node, "Deling")};

      const Container<Cv> enhetdosering{get_container<Cv>(admin_node, "EnhetDosering", [](const pugi::xml_node& n)
          {
            Cv enhet{get_cv(n)};
            return enhet;
          })};

      const Container<Cv> kortdose{get_container<Cv>(admin_node, "Kortdose", [](const pugi::xml_node& n)
          {
            Cv dose{get_cv(n)};
            return dose;
          })};

      const Container<Cv> forhandsregelinntak{get_container<Cv>(admin_node, "ForhandsregelInntak", [](const pugi::xml_node& n)
          {
            Cv regel{get_cv(n)};
            return regel;
          })};

      return xml::AdministreringLegemiddel{
        blandingsveske,
        refbladingsveske,
        administrasjonsvei,
        kanknuses,
        kanapnes,
        bolus,
        injeksjonshastighetbolus,
        deling,
        enhetdosering,
        kortdose,
        forhandsregelinntak};
    }

    xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node& node)
    {
      const pugi::xml_node pakning_node{node.child("PakningByttegruppe")};

      xml::IDREF refbyttegruppe{get_value(pakning_node, "RefByttegruppe")};
      Date gyldigfradato{get_value(pakning_node, "GyldigFraDato")};
      Date gyldigtildato{get_value(pakning_node, "GyldigTilDato")};

      return xml::PakningByttegruppe{refbyttegruppe, gyldigfradato, gyldigtildato};
    }

    xml::ProduktInfo get_produktinfo(const pugi::xml_node& node)
    {
      const pugi::xml_node produktinfo_node{node.child("ProduktInfo")};

      // TODO: use the pugi:: to return .bool()
      bool varseltrekant{false};
      const std::string varseltrekant_string{get_value(produktinfo_node, "Varseltrekant")};

      if(varseltrekant_string.compare("true") == 0)
        varseltrekant = true;

      const std::string referanseprodukt{get_value(produktinfo_node, "Referanseprodukt")};
      const xml::Cv vaksinestandard{get_cv(produktinfo_node, "Vaksinestandard")};
      const std::string produsent{get_value(produktinfo_node, "Produsent")};

      return xml::ProduktInfo{varseltrekant, referanseprodukt, vaksinestandard, produsent};
    }

    xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node& node)
    {
      const pugi::xml_node gyldighet_node{node.child("Reseptgyldighet")};

      const xml::Cs kjonn{get_cs(gyldighet_node, "Kjonn")};
      const std::string varighet{get_value(gyldighet_node, "Varighet")};

      return xml::Reseptgyldighet{kjonn, varighet};
    }

    xml::SortertVirkestoff get_sorteringvirkestoffmedstyrke(const pugi::xml_node& node)
    {
      xml::SortertVirkestoff sortertmedstyrke{};

      // get the sortering and reference
      const Container<std::pair<int, xml::IDREF>> sortering = get_container<std::pair<int,xml::IDREF>>(node, "SortertVirkestoffMedStyrke",
          [](const pugi::xml_node& n)
          {
            const std::string sort{get_value(n, "Sortering")};
            int sort_num = std::stoi(sort);

            const xml::IDREF ref{get_value(n, "RefVirkestoffMedStyrke")};
            return std::pair<int, xml::IDREF>{sort_num, ref};
          });

      for(const auto& pair : sortering)
      {
        // the pair.first should be unique, starting from 0
        // .push_back() checks if container already contains a 'sorting'
        sortertmedstyrke.push_back(pair.first, pair.second);
      }

      return sortertmedstyrke;
    }

    xml::SortertVirkestoff get_sorteringvirkestoffutenstyrke(const pugi::xml_node& node)
    {
      xml::SortertVirkestoff sortertmedstyrke{};

      // get the sortering and reference
      const Container<std::pair<int, xml::IDREF>> sortering = get_container<std::pair<int,xml::IDREF>>(node, "SortertVirkestoffUtenStyrke",
          [](const pugi::xml_node& n)
          {
            const std::string sort{get_value(n, "Sortering")};
            int sort_num = std::stoi(sort);

            const xml::IDREF ref{get_value(n, "RefVirkestoff")};
            return std::pair<int, xml::IDREF>{sort_num, ref};
          });

      for(const auto& pair : sortering)
      {
        // the pair.first should be unique, starting from 0
        // .push_back() checks if container already contains a 'sorting'
        sortertmedstyrke.push_back(pair.first, pair.second);
      }

      return sortertmedstyrke;
    }

  } // namespace

  // Get the creation date (<FEST><HentetDato> timestamp </HentetDato></FEST>)
  // from the FEST xml file.
  Date created_date(const Festlib& fest)
  {
    pugi::xml_node node{fest.get_node()};
    return get_value(node, "HentetDato");
  }


// give access to inline functions for testing purposes
#ifdef ENABLE_TESTING

  xml::Cv test_get_cv(const pugi::xml_node& node, std::string_view attribute)
  {
    return get_cv(node, attribute);
  }

  xml::Cs test_get_cs(const pugi::xml_node& node, std::string_view attribute)
  {
    return get_cs(node, attribute);
  }

  xml::Legemiddel test_get_legemiddel(const pugi::xml_node& node)
  {
    return get_legemiddel(node);
  }

  xml::Refusjon test_get_refusjon(const pugi::xml_node& node)
  {
    return get_refusjon(node);
  }

  xml::Preparatomtaleavsnitt test_get_preparatomtaleavsnitt(const pugi::xml_node& node)
  {
    return get_preparatomtaleavsnitt(node);
  }

  xml::Lenke test_get_lenke(const pugi::xml_node& node)
  {
    return get_lenke(node);
  }

  xml::AdministreringLegemiddel test_get_administreringlegemiddel(const pugi::xml_node& node)
  {
    return get_administreringlegemiddel(node);
  }

  xml::PakningByttegruppe test_get_pakningbyttegruppe(const pugi::xml_node& node)
  {
    return get_pakningbyttegruppe(node);
  }

  xml::ProduktInfo test_get_produktinfo(const pugi::xml_node& node)
  {
    return get_produktinfo(node);
  }

  xml::Reseptgyldighet test_get_reseptgyldighet(const pugi::xml_node& node)
  {
    return get_reseptgyldighet(node);
  }

  xml::SortertVirkestoff test_get_sorteringvirkestoffmedstyrke(const pugi::xml_node& node)
  {
    return get_sorteringvirkestoffmedstyrke(node);
  }

  xml::SortertVirkestoff test_get_sorteringvirkestoffutenstyrke(const pugi::xml_node& node)
  {
    return get_sorteringvirkestoffutenstyrke(node);
  }

#endif

} // namespace
