//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "legemiddel.h"

namespace festlib {
namespace xml {

std::optional<Refusjon> Legemiddel::refusjon() const {
  if (m_refusjon.refrefusjonsgruppe().empty())
    return {};

  return m_refusjon;
}

std::optional<PakningByttegruppe> Legemiddel::pakningbyttegruppe() const {
  if (m_pakningbyttegruppe.refbyttegruppe().empty())
    return {};

  return m_pakningbyttegruppe;
}

// non-member functions

xml::Legemiddel get_legemiddel(const pugi::xml_node &node) {
  Cv atc{xml::get_cv(node, "Atc")};
  std::string navnformstyrke{get_value(node, "NavnFormStyrke")};
  Cs reseptgruppe{get_cs(node, "Reseptgruppe")};
  Cv legemiddelformkort{get_cv(node, "LegemiddelformKort")};
  std::string refvilkar{get_value(node, "RefVilkar")};
  Cs preparattype{get_cs(node, "Preparattype")};
  Cs typesoknadslv{get_cs(node, "TypeSoknadSlv")};

  const bool opioid{get_bool(node, "Opioidsoknad")};

  Cv svarttrekant{get_cv(node, "SvartTrekant")};

  xml::Refusjon refusjon{get_refusjon(node)};
  xml::PakningByttegruppe byttegruppe{get_pakningbyttegruppe(node)};

  return xml::Legemiddel{
      std::move(atc),           std::move(navnformstyrke),
      std::move(reseptgruppe),  std::move(legemiddelformkort),
      std::move(refvilkar),     std::move(preparattype),
      std::move(typesoknadslv), opioid,
      std::move(svarttrekant),  std::move(refusjon),
      std::move(byttegruppe)};
}

} // namespace xml
} // namespace festlib
