#include "refusjon.h"
#include "check_empty.h"

namespace festlib
{
  namespace xml
  {

    Refusjon::Refusjon(const Container<IDREF>& refrefusjonsgruppe,
            std::string_view gyldigfradato,
            std::string_view forskrivestildato,
            std::string_view utleverestildato)
      : m_refrefusjonsgruppe{refrefusjonsgruppe},
      m_gyldigfradato{gyldigfradato},
      m_forskrivestildato{forskrivestildato},
      m_utleverestildato{utleverestildato}
    {
    }

    Container<IDREF> Refusjon::refrefusjonsgruppe() const
    {
      return m_refrefusjonsgruppe;
    }

    Date Refusjon::gyldigfradato() const
    {
      return m_gyldigfradato;
    }

    std::optional<Date> Refusjon::forskrivestildato() const
    {
      return check_empty(m_forskrivestildato);
    }

    std::optional<Date> Refusjon::utleverestildato() const
    {
      return check_empty(m_utleverestildato);
    }

    // non-member functions

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

  } // namespace
} // namespace
