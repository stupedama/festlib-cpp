//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PQ_H_
#define PQ_H_

#include "get_value.h"
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// contains value and unit
struct Pq {
  std::string v{};
  std::string u{};
};

xml::Pq get_pq(const pugi::xml_node &node, std::string_view attribute);
xml::Pq get_pq(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
