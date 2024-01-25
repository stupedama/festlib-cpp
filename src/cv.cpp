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

Cv::Cv(std::string v, std::string s, std::string dn)
    : m_v{std::move(v)}, m_s{std::move(s)}, m_dn{std::move(dn)} {}

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
  std::string v{node.attribute("V").value()};
  std::string s{node.attribute("S").value()};
  std::string dn{node.attribute("DN").value()};

  return xml::Cv{std::move(v), std::move(s), std::move(dn)};
}

xml::Cv get_cv(const pugi::xml_node &node, std::string_view attribute) {
  std::string v{node.child(attribute.data()).attribute("V").value()};
  std::string s{node.child(attribute.data()).attribute("S").value()};
  std::string dn{node.child(attribute.data()).attribute("DN").value()};

  return xml::Cv{std::move(v), std::move(s), std::move(dn)};
}

} // namespace xml
} // namespace festlib
