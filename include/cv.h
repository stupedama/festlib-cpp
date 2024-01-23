//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef CV_H_
#define CV_H_

#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {
// Coded Value
// V, S and DN is manidatory values in the Xml fest file
class Cv {
public:
  constexpr Cv() = default;
  explicit Cv(std::string_view V, std::string_view S, std::string_view DN);
  ~Cv() = default;
  Cv operator=(const Cv &other);
  constexpr const auto &value() const { return m_v; }
  constexpr const auto &long_value() const { return m_dn; }

private:
  std::string m_v{};
  std::string m_s{};
  std::string m_dn{};
};

// non-member functions

bool operator==(const Cv &lhs, const Cv &rhs);
bool operator==(const Cv &lhs, const char *str);

// CV (Coded Value) from node
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root.
//
// node =
// node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Cv atc = get_cv(node, "Atc");
xml::Cv get_cv(const pugi::xml_node &node, std::string_view attribute);
xml::Cv get_cv(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
