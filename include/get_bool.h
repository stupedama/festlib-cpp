//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include <pugixml.hpp>
#include <string_view>

namespace festlib {
namespace xml {

// compare node.child_value() to "true"
bool get_bool(const pugi::xml_node &node, std::string_view attribute);

} // namespace xml
} // namespace festlib
