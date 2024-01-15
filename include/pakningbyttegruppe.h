#ifndef PAKNINGBYTTEGRUPPE_H_
#define PAKNINGBYTTEGRUPPE_H_

#include <optional>
#include <pugixml.hpp>
#include "check_empty.h"
#include "date.h"
#include "idref.h"
#include "get_value.h"

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

    // non-member functions

    // PakningByttegruppe identifies what generic group it is.
    // RefByttegruppe ID is a link to other generics
    xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node& node);

  } // namespace
} // namespace

#endif
