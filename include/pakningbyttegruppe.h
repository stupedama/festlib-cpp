//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PAKNINGBYTTEGRUPPE_H_
#define PAKNINGBYTTEGRUPPE_H_

#include "check_empty.h"
#include "date.h"
#include "get_value.h"
#include "idref.h"
#include <optional>
#include <pugixml.hpp>

namespace festlib {
namespace xml {

// PakningByttegruppe stores data for generics
// IDREF m_refbyttegruppe identifies which generics group it is part of.
class PakningByttegruppe {
public:
  constexpr PakningByttegruppe() = default;
  template <typename T>
  explicit PakningByttegruppe(T &&refbyttegruppe, T &&gyldigfradato,
                              T &&gyldigtildato)
      : m_refbyttegruppe{std::forward<T>(refbyttegruppe)},
        m_gyldigfradato{std::forward<T>(gyldigfradato)},
        m_gyldigtildato{std::forward<T>(gyldigtildato)} {}
  ~PakningByttegruppe() = default;
  constexpr const auto &refbyttegruppe() const { return m_refbyttegruppe; }
  constexpr const auto &gyldigfradato() const { return m_gyldigfradato; }
  std::optional<Date> gyldigtildato() const;

private:
  IDREF m_refbyttegruppe{};
  // group is available from date
  Date m_gyldigfradato{};
  // group is available to date
  Date m_gyldigtildato{};
};

// non-member functions

bool operator==(const PakningByttegruppe &lhs, const PakningByttegruppe &rhs);
bool operator==(const PakningByttegruppe &lhs, std::string_view reference);
bool operator!=(const PakningByttegruppe &lhs, const PakningByttegruppe &rhs);
bool operator!=(const PakningByttegruppe &lhs, std::string_view reference);

// PakningByttegruppe identifies what generic group it is.
// RefByttegruppe ID is a link to other generics
xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
