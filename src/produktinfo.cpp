#include "produktinfo.h"
#include "check_empty.h"

namespace festlib
{
  namespace xml
  {
    ProduktInfo::ProduktInfo(bool varseltrekant, std::string_view referanseprodukt,
            const Cv& vaksinestandard, std::string_view produsent)
      : m_varseltrekant{varseltrekant}, m_referanseprodukt{referanseprodukt},
      m_vaksinestandard{vaksinestandard}, m_produsent{produsent}
    {
    }

    std::optional<bool> ProduktInfo::varseltrekant() const
    {
      if(!m_varseltrekant)
        return {};

      return m_varseltrekant;
    }

    std::optional<std::string> ProduktInfo::referanseprodukt() const
    {
      return check_empty(m_referanseprodukt);
    }

    std::optional<Cv> ProduktInfo::vaksinestandard() const
    {
      return check_empty(m_vaksinestandard);
    }

    std::optional<std::string> ProduktInfo::produsent() const
    {
      return check_empty(m_produsent);
    }

    // non-member functions

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

  } // namespace
} // namespace
