//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pakningskomponent.h"

namespace festlib {
namespace xml {

Pakningskomponent::Pakningskomponent(const Cv &pakningstype, const Pq &mengde,
                                     std::string_view antall)
    : m_pakningstype{pakningstype}, m_mengde{mengde}, m_antall{antall} {}

// non-member functions
namespace {

xml::Pakningskomponent get_one_pakningskomponent(const pugi::xml_node &node) {
  const Cv pakningstype{get_cv(node, "Pakningstype")};
  const Pq mengde{get_pq(node, "Mengde")};

  const std::string antall{get_value(node, "Mengde")};
  // const int antall{std::stoi(antall_str)};

  return xml::Pakningskomponent{pakningstype, mengde, antall};
}
} // namespace

Container<Pakningskomponent> get_pakningskomponent(const pugi::xml_node &node) {
  return get_container<Pakningskomponent>(
      node, "Pakningskomponent",
      [](const pugi::xml_node &n) { return get_one_pakningskomponent(n); });
}

} // namespace xml
} // namespace festlib
