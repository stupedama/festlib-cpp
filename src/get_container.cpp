//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "get_container.h"

namespace festlib {
namespace xml {

bool compare_value(std::string_view attribute,
                   const pugi::xml_node &child_node) {
  return attribute.compare(child_node.name()) == 0 ? true : false;
}

} // namespace xml
} // namespace festlib
