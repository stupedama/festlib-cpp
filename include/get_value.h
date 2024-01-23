//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef GET_VALUE_H_
#define GET_VALUE_H_

#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

using Value = std::string;

// Get a simple attribute value.
// Example <HentetDato>TimeStamp</HentetDato>:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root.
//
// Value date = get_value(node, "HentetDato");
Value get_value(const pugi::xml_node &node, std::string_view attribute);
Value get_value(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
