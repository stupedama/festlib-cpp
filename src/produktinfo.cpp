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

  } // namespace
} // namespace
