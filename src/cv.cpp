//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

// Coded Value
// V, S and DN is manidatory values in the Xml fest file

#include "cv.h"

namespace festlib {
namespace xml {

Cv::Cv(std::string_view V, std::string_view S, std::string_view DN)
    : m_v{V}, m_s{S}, m_dn{DN} {}

Cv Cv::operator=(const Cv &other) {
  if (this == &other)
    return *this;

  m_dn = other.m_dn;
  m_s = other.m_s;
  m_v = other.m_v;

  return *this;
}

// no--member functions

// compare the V values
bool operator==(const Cv &lhs, const Cv &rhs) {
  return lhs.value() == rhs.value();
}

// compare V values
bool operator==(const Cv &lhs, const char *str) {
  const std::string compare_string{str};
  return compare_string.compare(lhs.value()) == 0;
}

xml::Cv get_cv(const pugi::xml_node &node, std::string_view attribute) {
  pugi::xml_node child{node};

  if (attribute.length() > 0) {
    child = node.child(attribute.data());
  }

  const std::string v{child.attribute("V").value()};
  const std::string s{child.attribute("S").value()};
  const std::string dn{child.attribute("DN").value()};

  return xml::Cv{v, s, dn};
}

} // namespace xml
} // namespace festlib
