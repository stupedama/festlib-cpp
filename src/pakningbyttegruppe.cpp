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

  } // namespace
} // namespace

