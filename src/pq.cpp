//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pq.h"

namespace festlib {
namespace xml {

xml::Pq get_pq(const pugi::xml_node &node, std::string_view attribute) {
  std::string v{node.child(attribute.data()).attribute("V").value()};
  std::string u{node.child(attribute.data()).attribute("U").value()};

  return Pq{std::move(v), std::move(u)};
}

xml::Pq get_pq(const pugi::xml_node &node) {
  std::string v{node.attribute("V").value()};
  std::string u{node.attribute("U").value()};

  return Pq{std::move(v), std::move(u)};
}

} // namespace xml
} // namespace festlib
