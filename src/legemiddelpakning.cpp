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
    Enkeltoppforing enkeltoppforing, IDREF id, std::string varenr,
    Container<std::string> ean, Legemiddel legemiddel,
    Container<Pakningsinfo> pakningsinfo, Markedsforingsinfo markedsforingsinfo,
    Container<PrisVare> prisvare,
    AdministreringLegemiddel administreringlegemiddel,
    Container<Preparatomtaleavsnitt> preparatomtaleavsnitt)
    : m_enkeltoppforing{std::move(enkeltoppforing)}, m_id{std::move(id)},
      m_varenr{std::move(varenr)}, m_ean{std::move(ean)},
      m_legemiddel{std::move(legemiddel)},
      m_pakningsinfo{std::move(pakningsinfo)},
      m_markedsforingsinfo{std::move(markedsforingsinfo)},
      m_prisvare{std::move(prisvare)},
      m_administreringlegemiddel{std::move(administreringlegemiddel)},
      m_preparatomtaleavsnitt{std::move(preparatomtaleavsnitt)} {}

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

  xml::Enkeltoppforing enkeltoppforing{get_enkeltoppforing(node)};

  // move node
  const pugi::xml_node pakning_node{node.child("Legemiddelpakning")};

  // parts unique to legemiddelpakning
  std::string id{get_value(pakning_node, "Id")};
  std::string varenr{get_value(pakning_node, "Varenr")};
  Container<std::string> ean{get_container<std::string>(
      pakning_node, "Ean",
      [](const pugi::xml_node &n) { return get_value(n); })};
  Legemiddel legemiddel{get_legemiddel(pakning_node)};
  Container<Pakningsinfo> pakningsinfo{get_pakningsinfo(pakning_node)};
  Markedsforingsinfo markedsforingsinfo{get_markedsforingsinfo(pakning_node)};
  Container<PrisVare> prisvare{get_prisvare(pakning_node)};
  AdministreringLegemiddel administreringlegemiddel{
      get_administreringlegemiddel(pakning_node)};
  Container<Preparatomtaleavsnitt> preparatomtaleavsnitt{
      get_preparatomtaleavsnitt(pakning_node)};

  return xml::Legemiddelpakning{std::move(enkeltoppforing),
                                std::move(id),
                                std::move(varenr),
                                std::move(ean),
                                std::move(legemiddel),
                                std::move(pakningsinfo),
                                std::move(markedsforingsinfo),
                                std::move(prisvare),
                                std::move(administreringlegemiddel),
                                std::move(preparatomtaleavsnitt)};
}

} // namespace xml
} // namespace festlib
