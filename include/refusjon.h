#ifndef REFUSJON_H_
#define REFUSJON_H_

#include <optional>
#include <string_view>
#include "check_empty.h"
#include "container.h"
#include "date.h"
#include "idref.h"

namespace festlib
{
  namespace xml
  {

    class Refusjon
    {
      public:
        Refusjon() = default;
        explicit Refusjon(const Container<IDREF>& refrefusjonsgruppe,
            std::string_view gyldigfradato,
            std::string_view forskrivestildato,
            std::string_view utleverestildato);

        Container<IDREF> refrefusjonsgruppe() const;
        Date gyldigfradato() const;
        std::optional<Date> forskrivestildato() const;
        std::optional<Date> utleverestildato() const;

      private:
        // Reference to what refundgroup this package belongs to
        Container<IDREF> m_refrefusjonsgruppe{};
        // Date the refund is available from
        Date m_gyldigfradato{};
        // Date the refund is available to
        Date m_forskrivestildato{};
        // Date for how long it can be handed over
        Date m_utleverestildato{};
    };

  } // namespace
} // namespace

#endif
