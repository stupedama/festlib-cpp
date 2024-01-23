//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "get_bool.h"

namespace festlib {
namespace xml {

bool get_bool(const pugi::xml_node &node, std::string_view attribute) {
  std::string_view bool_string{node.child_value(attribute.data())};

  return bool_string.compare("true") == 0 ? true : false;
}

} // namespace xml
} // namespace festlib
