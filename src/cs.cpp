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

Cs::Cs(std::string_view V, std::string_view DN) : m_v{V}, m_dn{DN} {}
Cs::Cs(Cs &&other) : m_v{std::move(other.m_v)}, m_dn{std::move(other.m_dn)} {}
Cs::Cs(const Cs &other) : m_v{other.m_v}, m_dn{other.m_dn} {}

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
  const std::string v{node.child(attribute.data()).attribute("V").value()};
  const std::string dn{node.child(attribute.data()).attribute("DN").value()};

  return xml::Cs{v, dn};
}

xml::Cs get_cs(const pugi::xml_node &node) {
  const std::string v{node.attribute("V").value()};
  const std::string dn{node.attribute("DN").value()};

  return xml::Cs{v, dn};
}

} // namespace xml
} // namespace festlib
