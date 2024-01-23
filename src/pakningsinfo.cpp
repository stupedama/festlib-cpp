//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "pakningsinfo.h"

namespace festlib {
namespace xml {

// non-member functions

namespace {

xml::Pakningsinfo get_one_pakningsinfo(const pugi::xml_node &node) {
  // const pugi::xml_node child = node.child("Pakningsinfo");
  // TODO: handle invalid_argument from std::stoi
  // TODO: use pugi::xml to_int()?

  // try {
  const IDREF reflegemiddelmerkevare{get_value(node, "RefLegemiddelMerkevare")};
  const std::string pakningsstr{get_value(node, "Pakningsstr")};
  const Cv enhetpakning{get_cv(node, "EnhetPakning")};
  const Cv pakningstype{get_cv(node, "Pakningstype")};
  const std::string multippel{
      get_value(node, "Multippel")};                   // TODO: should be int
  const std::string antall{get_value(node, "Antall")}; // TODO: should be int
  const std::string mengde{get_value(node, "Mengde")}; // TODO: should be int
  const std::string sortering{
      get_value(node, "Sortering")}; // TODO: should be int
  const Pq ddd{get_pq(node, "DDD")};
  const std::string statistikkfaktor{get_value(node, "Statistikkfaktor")};
  const Container<xml::Pakningskomponent> pakningskomponent{
      get_pakningskomponent(node)};

  //} catch (const std::invalid_argument &) {

  return xml::Pakningsinfo{reflegemiddelmerkevare,
                           pakningsstr,
                           enhetpakning,
                           pakningstype,
                           multippel,
                           antall,
                           mengde,
                           sortering,
                           ddd,
                           statistikkfaktor,
                           pakningskomponent};
}

} // namespace

Container<xml::Pakningsinfo> get_pakningsinfo(const pugi::xml_node &node) {
  return get_container<xml::Pakningsinfo>(
      node, "Pakningsinfo",
      [](const pugi::xml_node &n) { return get_one_pakningsinfo(n); });
}

} // namespace xml
} // namespace festlib
