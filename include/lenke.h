//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef LENKE_H_
#define LENKE_H_

#include <pugixml.hpp>
#include <string>

namespace festlib {
namespace xml {

using Lenke = std::string;

// Lenke = URL
// Example:
//
// node =
// node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
// Lenke www = get_lenke(node);
xml::Lenke get_lenke(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
