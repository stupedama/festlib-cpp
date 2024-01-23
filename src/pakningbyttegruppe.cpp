//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pakningbyttegruppe.h"

namespace festlib {
namespace xml {

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

bool operator==(const PakningByttegruppe &lhs, const PakningByttegruppe &rhs) {
  return compare(lhs.refbyttegruppe(), rhs.refbyttegruppe());
}

bool operator==(const PakningByttegruppe &lhs, std::string_view reference) {
  return compare(lhs.refbyttegruppe(), reference);
}

bool operator!=(const PakningByttegruppe &lhs, const PakningByttegruppe &rhs) {
  return compare(lhs.refbyttegruppe(), rhs.refbyttegruppe()) ? false : true;
}

bool operator!=(const PakningByttegruppe &lhs, std::string_view reference) {
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
