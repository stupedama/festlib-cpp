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
  pugi::xml_node child{node};

  if (attribute.length() > 0)
    child = node.child(attribute.data());

  const std::string v{child.attribute("V").value()};
  const std::string u{child.attribute("U").value()};

  return Pq{v, u};
}

} // namespace xml
} // namespace festlib
