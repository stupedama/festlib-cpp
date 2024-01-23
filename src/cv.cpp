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
Cv::Cv(Cv &&other)
    : m_v{std::move(other.m_v)}, m_s{std::move(other.m_s)},
      m_dn{std::move(other.m_dn)} {}
Cv::Cv(const Cv &other) : m_v{other.m_v}, m_s{other.m_s}, m_dn{other.m_dn} {}

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

xml::Cv get_cv(const pugi::xml_node &node) {
  const std::string v{node.attribute("V").value()};
  const std::string s{node.attribute("S").value()};
  const std::string dn{node.attribute("DN").value()};

  return xml::Cv{v, s, dn};
}

xml::Cv get_cv(const pugi::xml_node &node, std::string_view attribute) {
  const std::string v{node.child(attribute.data()).attribute("V").value()};
  const std::string s{node.child(attribute.data()).attribute("S").value()};
  const std::string dn{node.child(attribute.data()).attribute("DN").value()};

  return xml::Cv{v, s, dn};
}

} // namespace xml
} // namespace festlib
