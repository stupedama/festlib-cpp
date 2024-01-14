#ifndef PAKNINGBYTTEGRUPPE_H_
#define PAKNINGBYTTEGRUPPE_H_

#include <optional>
#include "check_empty.h"
#include "date.h"
#include "idref.h"

namespace festlib
{
  namespace xml
  {

    // PakningByttegruppe stores data for generics
    // IDREF m_refbyttegruppe identifies which generics group it is part of.
    class PakningByttegruppe
    {
      public:
        PakningByttegruppe() = default;
        explicit PakningByttegruppe(const IDREF& refbyttegruppe,
            const Date& gyldigfradato, const Date& gyldigtildato);
        IDREF refbyttegruppe() const;
        Date gyldigfradato() const;
        std::optional<Date> gyldigtildato() const;
      private:
        IDREF m_refbyttegruppe{};
        // group is available from date
        Date m_gyldigfradato{};
        // group is available to date
        Date m_gyldigtildato{};
    };

  } // namespace
} // namespace

#endif
