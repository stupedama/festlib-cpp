//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ENKELTOPPFORING_H_
#define ENKELTOPPFORING_H_

#include "get_value.h"
#include <pugixml.hpp>
#include <string>

namespace festlib {
namespace xml {

// Enkeltoppforing = Entry.
// All the entries of the xml file contains a "Enkeltoppforing".
// Shows information if the entry is active, entry date and unique ID.
class Enkeltoppforing {
public:
  constexpr Enkeltoppforing() = default;
  explicit Enkeltoppforing(std::string id, std::string date, bool status);
  constexpr const auto &id() const { return m_id; }
  constexpr const auto &date() const { return m_date; }
  constexpr bool status() const { return m_status; };

private:
  std::string m_id{};
  std::string m_date{};
  bool m_status{};
};

// non-member functions

bool operator==(const Enkeltoppforing &lhs, const Enkeltoppforing &rhs);
bool operator==(const Enkeltoppforing &lhs, const char *str);

// Enkeltoppforing = Entry.
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root
//
// node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare");
// auto entry = get_enkeltoppforing(node);
xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
