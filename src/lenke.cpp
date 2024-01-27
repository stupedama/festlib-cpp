//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "lenke.h"

namespace festlib {
namespace xml {

xml::Lenke get_lenke(const pugi::xml_node &node) {
  return node.child("Lenke").child("Www").attribute("V").value();
}

} // namespace xml
} // namespace festlib
