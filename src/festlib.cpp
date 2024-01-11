#include "festlib.h"

#include <iostream>

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

  pugi::xml_node Festlib::get_node() const
  {
    return m_doc.child("FEST");
  }

  // no--member functions

  namespace {

    // Enkeltoppforing = Entry.
    // Shows information if the entry is active, entry date and ID.
    // All the entries of the xml file contains a "Enkeltoppforing".
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

    // CV (Coded Value)
    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute)
    {
      pugi::xml_node child{node.child(attribute.data())};

      std::string_view v{child.attribute("V").value()};
      std::string_view s{child.attribute("S").value()};
      std::string_view dn{child.attribute("DN").value()};

      return xml::Cv{v, s, dn};
    }

    // CS (Coded Simple Value)
    xml::Cs get_cs(const pugi::xml_node& node, std::string_view attribute)
    {
      pugi::xml_node child{node.child(attribute.data())};

      std::string_view v{child.attribute("V").value()};
      std::string_view dn{child.attribute("DN").value()};

      return xml::Cs{v, dn};
    }

    Value get_value(const pugi::xml_node& node, std::string_view attribute)
    {
      return node.child_value(attribute.data());
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

      // get OpioidSoknad. It is stored as a string as true or false
      const std::string opioid_string{get_value(node, "Opioidsoknad")};
      bool opioid{false};

      if(opioid_string.compare("true") == 0)
        opioid = true;

      const Cv svarttrekant{get_cv(node, "SvartTrekant")};

      return xml::Legemiddel{atc, navnformstyrke, reseptgruppe, legemiddelformkort,
        refvilkar, preparattype, typesoknadslv, opioid, svarttrekant};
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
  xml::Legemiddel test_get_legemiddel(const pugi::xml_node& node)
  {
    return get_legemiddel(node);
  }
#endif

} // namespace
