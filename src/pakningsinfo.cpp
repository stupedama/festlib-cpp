//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pakningsinfo.h"

namespace festlib {
namespace xml {

Pakningsinfo::Pakningsinfo(IDREF reflegemiddelmerkevare,
                           std::string pakningsstr, Cv enhetpakning,
                           const Cv &pakningstype, std::string multippel,
                           std::string antall, std::string mengde,
                           std::string sortering, const Pq &ddd,
                           std::string statistikkfaktor,
                           Container<Pakningskomponent> pakningskomponent)
    : m_reflegemiddelmerkevare{std::move(reflegemiddelmerkevare)},
      m_pakningsstr{std::move(pakningsstr)},
      m_enhetpakning{std::move(enhetpakning)},
      m_pakningstype{std::move(pakningstype)},
      m_multippel{std::move(multippel)}, m_antall{std::move(antall)},
      m_mengde{std::move(mengde)}, m_sortering{std::move(sortering)},
      m_ddd{std::move(ddd)}, m_statistikkfaktor{std::move(statistikkfaktor)},
      m_pakningskomponent{std::move(pakningskomponent)} {}
// non-member functions

namespace {

xml::Pakningsinfo get_one_pakningsinfo(const pugi::xml_node &node) {
  // const pugi::xml_node child = node.child("Pakningsinfo");
  // TODO: handle invalid_argument from std::stoi
  // TODO: use pugi::xml to_int()?

  // try {
  IDREF reflegemiddelmerkevare{get_value(node, "RefLegemiddelMerkevare")};
  std::string pakningsstr{get_value(node, "Pakningsstr")};
  Cv enhetpakning{get_cv(node, "EnhetPakning")};
  Cv pakningstype{get_cv(node, "Pakningstype")};
  std::string multippel{get_value(node, "Multippel")}; // TODO: should be int
  std::string antall{get_value(node, "Antall")};       // TODO: should be int
  std::string mengde{get_value(node, "Mengde")};       // TODO: should be int
  std::string sortering{get_value(node, "Sortering")}; // TODO: should be int
  Pq ddd{get_pq(node, "DDD")};
  std::string statistikkfaktor{get_value(node, "Statistikkfaktor")};
  Container<xml::Pakningskomponent> pakningskomponent{
      get_pakningskomponent(node)};

  //} catch (const std::invalid_argument &) {

  return xml::Pakningsinfo{std::move(reflegemiddelmerkevare),
                           std::move(pakningsstr),
                           std::move(enhetpakning),
                           std::move(pakningstype),
                           std::move(multippel),
                           std::move(antall),
                           std::move(mengde),
                           std::move(sortering),
                           std::move(ddd),
                           std::move(statistikkfaktor),
                           std::move(pakningskomponent)};
}

} // namespace

Container<xml::Pakningsinfo> get_pakningsinfo(const pugi::xml_node &node) {
  return get_container<xml::Pakningsinfo>(
      node, "Pakningsinfo",
      [](const pugi::xml_node &n) { return get_one_pakningsinfo(n); });
}

} // namespace xml
} // namespace festlib
