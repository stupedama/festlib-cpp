//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "enkeltoppforing.h"

namespace festlib {
namespace xml {

Enkeltoppforing::Enkeltoppforing(std::string id, std::string date, bool status)
    : m_id{std::move(id)}, m_date{std::move(date)}, m_status{status} {}

// no--member functions

namespace {

// A == Active
bool get_status(const pugi::xml_node &node) {
  std::string_view compare_string{
      node.child("Status").first_attribute().value()};

  return compare_string.compare("A") == 0 ? true : false;
}

} // namespace

// Enkeltoppforing contains a unique ID.
bool operator==(const Enkeltoppforing &lhs, const Enkeltoppforing &rhs) {
  return lhs.id() == rhs.id();
}

// Enkeltoppforing contains a unique ID.
bool operator==(const Enkeltoppforing &lhs, const char *str) {
  const std::string compare_string{str};
  return compare_string.compare(lhs.id()) == 0;
}

xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node &node) {
  const std::string id{get_value(node, "Id")};
  const std::string date{
      get_value(node, "Tidspunkt")}; // Tidspunkt = Entry date
  const std::string status{node.child("Status").first_attribute().value()};

  const bool oppforing_status{get_status(node)};

  return xml::Enkeltoppforing{id, date, oppforing_status};
}

} // namespace xml
} // namespace festlib
