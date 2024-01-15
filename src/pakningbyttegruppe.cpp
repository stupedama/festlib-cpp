#include "pakningbyttegruppe.h"

namespace festlib
{
  namespace xml
  {
    PakningByttegruppe::PakningByttegruppe(const IDREF& refbyttegruppe,
            const Date& gyldigfradato, const Date& gyldigtildato)
      : m_refbyttegruppe{refbyttegruppe}, m_gyldigfradato{gyldigfradato},
      m_gyldigtildato{gyldigtildato}
    {
    }
    IDREF PakningByttegruppe::refbyttegruppe() const
    {
      return m_refbyttegruppe;
    }

    Date PakningByttegruppe::gyldigfradato() const
    {
      return m_gyldigfradato;
    }

    std::optional<Date> PakningByttegruppe::gyldigtildato() const
    {
      return check_empty(m_gyldigtildato);
    }

    // non-member functions

    xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node& node)
    {
      const pugi::xml_node pakning_node{node.child("PakningByttegruppe")};

      xml::IDREF refbyttegruppe{get_value(pakning_node, "RefByttegruppe")};
      Date gyldigfradato{get_value(pakning_node, "GyldigFraDato")};
      Date gyldigtildato{get_value(pakning_node, "GyldigTilDato")};

      return xml::PakningByttegruppe{refbyttegruppe, gyldigfradato, gyldigtildato};
    }

  } // namespace
} // namespace

