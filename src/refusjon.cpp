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

  } // namespace
} // namespace
