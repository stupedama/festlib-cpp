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
    Enkeltoppforing enkeltoppforing, IDREF id, std::string varenavn,
    std::string legemiddelformlang, Cs smak,
    AdministreringLegemiddel administreringlegemiddel, Legemiddel legemiddel,
    Preparatomtaleavsnitt preparatomtaleavsnitt, ProduktInfo produktinfo,
    Reseptgyldighet reseptgyldighet,
    SortertVirkestoff sortertvirkestoffmedstyrke)
    : m_enkeltoppforing{std::move(enkeltoppforing)}, m_id{std::move(id)},
      m_varenavn{std::move(varenavn)},
      m_legemiddelformlang{std::move(legemiddelformlang)},
      m_smak{std::move(smak)},
      m_administreringlegemiddel{std::move(administreringlegemiddel)},
      m_legemiddel{std::move(legemiddel)},
      m_preparatomtaleavsnitt{std::move(preparatomtaleavsnitt)},
      m_produktinfo{std::move(produktinfo)},
      m_reseptgyldighet{std::move(reseptgyldighet)},
      m_sortertvirkestoffmedstyrke{std::move(sortertvirkestoffmedstyrke)} {}

// non-member functions

xml::LegemiddelMerkevare get_legemiddelmerkevare(const pugi::xml_node &node) {
  const pugi::xml_node merkevare_node{node.child("LegemiddelMerkevare")};

  xml::Enkeltoppforing enkeltoppforing{get_enkeltoppforing(node)};

  // get the parts what is unique to LegemiddelMerkevare
  std::string id{get_value(merkevare_node, "Id")};
  std::string varenavn{get_value(merkevare_node, "Varenavn")};
  std::string legemiddelformlang{
      get_value(merkevare_node, "LegemiddelformLang")};
  xml::Cs smak{get_cs(merkevare_node, "Smak")};

  // shared parts
  xml::AdministreringLegemiddel administreringlegemiddel{
      get_administreringlegemiddel(merkevare_node)};
  xml::Legemiddel legemiddel{get_legemiddel(merkevare_node)};
  xml::Preparatomtaleavsnitt preparatomtaleavsnitt{
      get_preparatomtaleavsnitt(merkevare_node)};
  xml::ProduktInfo produktinfo{get_produktinfo(merkevare_node)};
  xml::Reseptgyldighet reseptgyldighet{get_reseptgyldighet(merkevare_node)};
  xml::SortertVirkestoff sortervirkestoffmedstyrke{
      get_sorteringvirkestoffmedstyrke(merkevare_node)};

  return xml::LegemiddelMerkevare{std::move(enkeltoppforing),
                                  std::move(id),
                                  std::move(varenavn),
                                  std::move(legemiddelformlang),
                                  std::move(smak),
                                  std::move(administreringlegemiddel),
                                  std::move(legemiddel),
                                  std::move(preparatomtaleavsnitt),
                                  std::move(produktinfo),
                                  std::move(reseptgyldighet),
                                  std::move(sortervirkestoffmedstyrke)};
}

} // namespace xml
} // namespace festlib
