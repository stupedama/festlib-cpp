//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "refusjon.h"

namespace festlib {
namespace xml {

Refusjon::Refusjon(const Container<IDREF> &refrefusjonsgruppe,
                   std::string_view gyldigfradato,
                   std::string_view forskrivestildato,
                   std::string_view utleverestildato)
    : m_refrefusjonsgruppe{refrefusjonsgruppe}, m_gyldigfradato{gyldigfradato},
      m_forskrivestildato{forskrivestildato},
      m_utleverestildato{utleverestildato} {}

std::optional<Date> Refusjon::forskrivestildato() const {
  return check_empty(m_forskrivestildato);
}

std::optional<Date> Refusjon::utleverestildato() const {
  return check_empty(m_utleverestildato);
}

// non-member functions

xml::Refusjon get_refusjon(const pugi::xml_node &node) {
  const pugi::xml_node refusjon_node{node.child("Refusjon")};

  const Container<xml::IDREF> refrefusjonsgruppe{get_container<xml::IDREF>(
      refusjon_node, "RefRefusjonsgruppe",
      [](const pugi::xml_node &n) { return get_value(n); })};

  const Date gyldigfradato{get_value(refusjon_node, "GyldigFraDato")};
  const Date forskrivestildato{get_value(refusjon_node, "ForskrivesTilDato")};
  const Date utleverestildato{get_value(refusjon_node, "UtleveresTilDato")};

  return xml::Refusjon{refrefusjonsgruppe, gyldigfradato, forskrivestildato,
                       utleverestildato};
}

} // namespace xml
} // namespace festlib
