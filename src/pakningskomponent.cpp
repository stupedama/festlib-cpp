//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pakningskomponent.h"

namespace festlib {
namespace xml {
Pakningskomponent::Pakningskomponent(Cv pakningstype, Pq mengde,
                                     std::string antall)
    : m_pakningstype{std::move(pakningstype)}, m_mengde{std::move(mengde)},
      m_antall{std::move(antall)} {}

// non-member functions
namespace {

xml::Pakningskomponent get_one_pakningskomponent(const pugi::xml_node &node) {
  Cv pakningstype{get_cv(node, "Pakningstype")};
  Pq mengde{get_pq(node, "Mengde")};

  std::string antall{get_value(node, "Mengde")};
  // const int antall{std::stoi(antall_str)};

  return xml::Pakningskomponent{std::move(pakningstype), std::move(mengde),
                                std::move(antall)};
}
} // namespace

Container<Pakningskomponent> get_pakningskomponent(const pugi::xml_node &node) {
  return get_container<Pakningskomponent>(
      node, "Pakningskomponent",
      [](const pugi::xml_node &n) { return get_one_pakningskomponent(n); });
}

} // namespace xml
} // namespace festlib
