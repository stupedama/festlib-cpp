//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "reseptgyldighet.h"

namespace festlib {
namespace xml {

std::optional<Cs> Reseptgyldighet::kjonn() const {
  return check_empty(m_kjonn);
}

// non-member functions

xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node &node) {
  const pugi::xml_node gyldighet_node{node.child("Reseptgyldighet")};

  xml::Cs kjonn{get_cs(gyldighet_node, "Kjonn")};
  std::string varighet{get_value(gyldighet_node, "Varighet")};

  return xml::Reseptgyldighet{std::move(kjonn), std::move(varighet)};
}

} // namespace xml
} // namespace festlib
