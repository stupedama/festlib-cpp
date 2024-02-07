//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef CS_H_
#define CS_H_

#include <pugixml.hpp>
#include <string>

namespace festlib {
namespace xml {
// Coded Simple Value
// V and DN is manidatory values in the Fest xml file
class Cs {
public:
  explicit Cs(std::string v, std::string dn);
  constexpr const auto &value() const { return m_v; }
  constexpr const auto &long_value() const { return m_dn; }

private:
  std::string m_v{};
  std::string m_dn{};
};

// non-member functions

bool operator==(const Cs &lhs, const Cs &rhs);
bool operator==(const Cs &lhs, const char *str);

// CS (Coded Simple Value)
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root.
//
// node =
// node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Cs preparattype = get_cs(node, "Preparattype");
xml::Cs get_cs(const pugi::xml_node &node, std::string_view attribute);
xml::Cs get_cs(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
