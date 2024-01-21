#include "pakningbyttegruppe.h"

namespace festlib {
namespace xml {
PakningByttegruppe::PakningByttegruppe(const IDREF &refbyttegruppe,
                                       const Date &gyldigfradato,
                                       const Date &gyldigtildato)
    : m_refbyttegruppe{refbyttegruppe}, m_gyldigfradato{gyldigfradato},
      m_gyldigtildato{gyldigtildato} {}

std::optional<Date> PakningByttegruppe::gyldigtildato() const {
  return check_empty(m_gyldigtildato);
}

// non-member functions
//

namespace {

constexpr bool compare(std::string_view lhs, std::string_view rhs) {
  return (lhs.compare(rhs) == 0) ? true : false;
}

} // namespace

const bool operator==(const PakningByttegruppe &lhs,
                      const PakningByttegruppe &rhs) {
  return compare(lhs.refbyttegruppe(), rhs.refbyttegruppe());
}

const bool operator==(const PakningByttegruppe &lhs,
                      std::string_view reference) {
  return compare(lhs.refbyttegruppe(), reference);
}

const bool operator!=(const PakningByttegruppe &lhs,
                      const PakningByttegruppe &rhs) {
  return compare(lhs.refbyttegruppe(), rhs.refbyttegruppe()) ? false : true;
}

const bool operator!=(const PakningByttegruppe &lhs,
                      std::string_view reference) {
  return compare(lhs.refbyttegruppe(), reference) ? false : true;
}

xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node &node) {
  const pugi::xml_node pakning_node{node.child("PakningByttegruppe")};

  const xml::IDREF refbyttegruppe{get_value(pakning_node, "RefByttegruppe")};
  const Date gyldigfradato{get_value(pakning_node, "GyldigFraDato")};
  const Date gyldigtildato{get_value(pakning_node, "GyldigTilDato")};

  return xml::PakningByttegruppe{refbyttegruppe, gyldigfradato, gyldigtildato};
}

} // namespace xml
} // namespace festlib
