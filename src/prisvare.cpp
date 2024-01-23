//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "prisvare.h"

namespace festlib {
namespace xml {

// non-member functions

namespace {
xml::PrisVare get_one_prisvare(const pugi::xml_node &node) {
  const Cv type{get_cv(node, "Type")};
  const Pq pris{get_pq(node, "Pris")};
  const Date gyldigfradato{get_value(node, "GyldigFraDato")};
  const Date gyldigtildato{get_value(node, "GyldigTilDato")};

  return xml::PrisVare{type, pris, gyldigfradato, gyldigtildato};
}
} // namespace

Container<xml::PrisVare> get_prisvare(const pugi::xml_node &node) {
  return get_container<xml::PrisVare>(
      node, "PrisVare",
      [](const pugi::xml_node &n) { return get_one_prisvare(n); });
}

} // namespace xml
} // namespace festlib
