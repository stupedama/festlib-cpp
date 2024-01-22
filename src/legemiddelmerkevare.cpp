//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "legemiddelmerkevare.h"

namespace festlib {
namespace xml {

LegemiddelMerkevare::LegemiddelMerkevare(
    const Enkeltoppforing &enkeltoppforing, const IDREF &id,
    std::string_view varenavn, std::string_view legemiddelformlang,
    const Cs &smak, const AdministreringLegemiddel &administreringlegemiddel,
    const Legemiddel &legemiddel,
    const Preparatomtaleavsnitt &preparatomtaleavsnitt,
    const ProduktInfo &produktinfo, const Reseptgyldighet &reseptgyldighet,
    const SortertVirkestoff &sortertvirkestoffmedstyrke)
    : m_enkeltoppforing{enkeltoppforing}, m_id{id}, m_varenavn{varenavn},
      m_legemiddelformlang{legemiddelformlang}, m_smak{smak},
      m_administreringlegemiddel{administreringlegemiddel},
      m_legemiddel{legemiddel}, m_preparatomtaleavsnitt{preparatomtaleavsnitt},
      m_produktinfo{produktinfo}, m_reseptgyldighet{reseptgyldighet},
      m_sortertvirkestoffmedstyrke{sortertvirkestoffmedstyrke} {}

// non-member functions

xml::LegemiddelMerkevare get_legemiddelmerkevare(const pugi::xml_node &node) {
  const pugi::xml_node merkevare_node{node.child("LegemiddelMerkevare")};

  const xml::Enkeltoppforing enkeltoppforing{get_enkeltoppforing(node)};

  // get the parts what is unique to LegemiddelMerkevare
  const std::string id{get_value(merkevare_node, "Id")};
  const std::string varenavn{get_value(merkevare_node, "Varenavn")};
  const std::string legemiddelformlang{
      get_value(merkevare_node, "LegemiddelformLang")};
  const xml::Cs smak{get_cs(merkevare_node, "Smak")};

  // shared parts
  const xml::AdministreringLegemiddel administreringlegemiddel{
      get_administreringlegemiddel(merkevare_node)};
  const xml::Legemiddel legemiddel{get_legemiddel(merkevare_node)};
  const xml::Preparatomtaleavsnitt preparatomtaleavsnitt{
      get_preparatomtaleavsnitt(merkevare_node)};
  const xml::ProduktInfo produktinfo{get_produktinfo(merkevare_node)};
  const xml::Reseptgyldighet reseptgyldighet{
      get_reseptgyldighet(merkevare_node)};
  const xml::SortertVirkestoff sortervirkestoffmedstyrke{
      get_sorteringvirkestoffmedstyrke(merkevare_node)};

  return xml::LegemiddelMerkevare{enkeltoppforing,
                                  id,
                                  varenavn,
                                  legemiddelformlang,
                                  smak,
                                  administreringlegemiddel,
                                  legemiddel,
                                  preparatomtaleavsnitt,
                                  produktinfo,
                                  reseptgyldighet,
                                  sortervirkestoffmedstyrke};
}

} // namespace xml
} // namespace festlib
