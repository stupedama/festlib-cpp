//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "get_value.h"

namespace festlib {
namespace xml {

Value get_value(const pugi::xml_node &node, std::string_view attribute) {
  if (attribute.length() > 0) {
    return node.child_value(attribute.data());
  } else {
    return node.child_value();
  }
}

} // namespace xml
} // namespace festlib
