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
  Cv type{get_cv(node, "Type")};
  Pq pris{get_pq(node, "Pris")};
  Date gyldigfradato{get_value(node, "GyldigFraDato")};
  Date gyldigtildato{get_value(node, "GyldigTilDato")};

  return xml::PrisVare{std::move(type), std::move(pris),
                       std::move(gyldigfradato), std::move(gyldigtildato)};
}
} // namespace

Container<xml::PrisVare> get_prisvare(const pugi::xml_node &node) {
  return get_container<xml::PrisVare>(
      node, "PrisVare",
      [](const pugi::xml_node &n) { return get_one_prisvare(n); });
}

} // namespace xml
} // namespace festlib
