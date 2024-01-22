//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "legemiddelpakning.h"

namespace festlib {
namespace xml {

Legemiddelpakning::Legemiddelpakning(
    const Enkeltoppforing &enkeltoppforing, const IDREF &id,
    std::string_view varenr, const Container<std::string> &ean,
    const Legemiddel &legemiddel, const Container<Pakningsinfo> &pakningsinfo,
    const Markedsforingsinfo &markedsforingsinfo,
    const Container<PrisVare> &prisvare,
    const AdministreringLegemiddel &administreringlegemiddel,
    const Container<Preparatomtaleavsnitt> &preparatomtaleavsnitt)
    : m_enkeltoppforing{enkeltoppforing}, m_id{id}, m_varenr{varenr},
      m_ean{ean}, m_legemiddel{legemiddel}, m_pakningsinfo{pakningsinfo},
      m_markedsforingsinfo{markedsforingsinfo}, m_prisvare{prisvare},
      m_administreringlegemiddel{administreringlegemiddel},
      m_preparatomtaleavsnitt{preparatomtaleavsnitt} {}

std::optional<Container<std::string>> Legemiddelpakning::ean() const {
  if (m_ean.empty())
    return {};

  return m_ean;
}

std::optional<std::string> Legemiddelpakning::oppbevaring() const {
  if (m_oppbevaring.v.empty())
    return {};

  return m_oppbevaring.v;
}
std::optional<PakningByttegruppe>
Legemiddelpakning::pakningbyttegruppe() const {
  return m_legemiddel.pakningbyttegruppe();
}

// non-member functions
xml::Legemiddelpakning get_legemiddelpakning(const pugi::xml_node &node) {

  const xml::Enkeltoppforing enkeltoppforing{get_enkeltoppforing(node)};

  // move node
  const pugi::xml_node pakning_node{node.child("Legemiddelpakning")};

  // parts unique to legemiddelpakning
  const std::string id{get_value(pakning_node, "Id")};
  const std::string varenr{get_value(pakning_node, "Varenr")};
  const Container<std::string> ean{get_container<std::string>(
      pakning_node, "Ean",
      [](const pugi::xml_node &n) { return get_value(n); })};
  const Legemiddel legemiddel{get_legemiddel(pakning_node)};
  const Container<Pakningsinfo> pakningsinfo{get_pakningsinfo(pakning_node)};
  const Markedsforingsinfo markedsforingsinfo{
      get_markedsforingsinfo(pakning_node)};
  const Container<PrisVare> prisvare{get_prisvare(pakning_node)};
  const AdministreringLegemiddel administreringlegemiddel{
      get_administreringlegemiddel(pakning_node)};
  const Container<Preparatomtaleavsnitt> preparatomtaleavsnitt{
      get_preparatomtaleavsnitt(pakning_node)};

  return xml::Legemiddelpakning{enkeltoppforing,
                                id,
                                varenr,
                                ean,
                                legemiddel,
                                pakningsinfo,
                                markedsforingsinfo,
                                prisvare,
                                administreringlegemiddel,
                                preparatomtaleavsnitt};
}

} // namespace xml
} // namespace festlib
