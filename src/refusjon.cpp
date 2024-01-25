//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "refusjon.h"

namespace festlib {
namespace xml {

std::optional<Date> Refusjon::forskrivestildato() const {
  return check_empty(m_forskrivestildato);
}

std::optional<Date> Refusjon::utleverestildato() const {
  return check_empty(m_utleverestildato);
}

// non-member functions

xml::Refusjon get_refusjon(const pugi::xml_node &node) {
  const pugi::xml_node refusjon_node{node.child("Refusjon")};

  Container<xml::IDREF> refrefusjonsgruppe{get_container<xml::IDREF>(
      refusjon_node, "RefRefusjonsgruppe",
      [](const pugi::xml_node &n) { return get_value(n); })};

  Date gyldigfradato{get_value(refusjon_node, "GyldigFraDato")};
  Date forskrivestildato{get_value(refusjon_node, "ForskrivesTilDato")};
  Date utleverestildato{get_value(refusjon_node, "UtleveresTilDato")};

  return xml::Refusjon{std::move(refrefusjonsgruppe), std::move(gyldigfradato),
                       std::move(forskrivestildato),
                       std::move(utleverestildato)};
}

} // namespace xml
} // namespace festlib
