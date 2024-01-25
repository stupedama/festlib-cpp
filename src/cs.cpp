//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

// CS = Coded Simple Value.
// V and DN is manidatory values in the Xml fest file

#include "cs.h"

namespace festlib {
namespace xml {

Cs::Cs(std::string v, std::string dn)
    : m_v{std::move(v)}, m_dn{std::move(dn)} {}

// no--member functions

// compare the V attributes
bool operator==(const Cs &lhs, const Cs &rhs) {
  return lhs.value() == rhs.value();
}

// compare the V attributes
bool operator==(const Cs &lhs, const char *str) {
  const std::string_view compare_string{str};
  return compare_string.compare(lhs.value()) == 0;
}

xml::Cs get_cs(const pugi::xml_node &node, std::string_view attribute) {
  std::string v{node.child(attribute.data()).attribute("V").value()};
  std::string dn{node.child(attribute.data()).attribute("DN").value()};

  return xml::Cs{std::move(v), std::move(dn)};
}

xml::Cs get_cs(const pugi::xml_node &node) {
  std::string v{node.attribute("V").value()};
  std::string dn{node.attribute("DN").value()};

  return xml::Cs{std::move(v), std::move(dn)};
}

} // namespace xml
} // namespace festlib
