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

  // Get the creation date (<FEST><HentetDato> timestamp </HentetDato></FEST>)
  // from the FEST xml file.
  Date created_date(const Festlib& fest)
  {
    const pugi::xml_node node{fest.get_node()};
    return xml::get_value(node, "HentetDato");
  }
  
  Container<xml::LegemiddelMerkevare> catalog_legemiddelmerkevare(const Festlib& fest)
  {
    const pugi::xml_node node = fest.get_node();

    const auto container = festlib::xml::get_category<festlib::xml::LegemiddelMerkevare>(node, "KatLegemiddelMerkevare", [](const pugi::xml_node& n)
      {
        festlib::xml::LegemiddelMerkevare val{festlib::xml::get_legemiddelmerkevare(n)};
        return val;
      });

    return container;
  }

} // namespace
