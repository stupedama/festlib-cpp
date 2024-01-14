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
        Date m_gyldigfradato{};
        Date m_gyldigtildato{};
    };

  } // namespace
} // namespace

#endif
