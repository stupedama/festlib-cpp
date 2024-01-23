//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "festlib.h"

namespace festlib {

Festlib::Festlib() : m_doc{}, m_parse_result{} {}

pugi::xml_parse_result Festlib::load_file(std::string_view filename) {
  // if xml_document is already loaded, the xml_tree will be
  // reset and populated again.
  m_parse_result = m_doc.load_file(filename.data(), pugi::encoding_auto);
  return m_parse_result;
}

pugi::xml_parse_result Festlib::load_string(std::string_view xml_string) {
  // if xml_document is already loaded, the xml_tree will be
  // reset and populated again.
  m_parse_result = m_doc.load_string(xml_string.data(), pugi::encoding_auto);
  return m_parse_result;
}

// return the root of the Fest XML
pugi::xml_node Festlib::get_node() const { return m_doc.child("FEST"); }

// helper functions
namespace {

Container<xml::Legemiddelpakning>
find_generic(const Container<xml::Legemiddelpakning> &container,
             const xml::IDREF &reference) {

  Container<xml::Legemiddelpakning> result{};

  for (const auto &id : container) {
    if (id.pakningbyttegruppe() == reference)
      result.push_back(id);
  }

  return result;
}

} // namespace

// no--member functions

// Get the creation date (<FEST><HentetDato> timestamp </HentetDato></FEST>)
// from the FEST xml file.
Date created_date(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};
  return xml::get_value(node, "HentetDato");
}

Container<xml::LegemiddelMerkevare>
catalog_legemiddelmerkevare(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  const auto container{
      festlib::xml::get_category<festlib::xml::LegemiddelMerkevare>(
          node, "KatLegemiddelMerkevare", [](const pugi::xml_node &n) {
            return festlib::xml::get_legemiddelmerkevare(n);
          })};

  return container;
}

Map<std::string, xml::LegemiddelMerkevare>
map_catalog_legemiddelmerkevare(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  const Map<std::string, xml::LegemiddelMerkevare> container{
      xml::get_category_map<xml::LegemiddelMerkevare>(
          node, "KatLegemiddelMerkevare", [](const pugi::xml_node &n) {
            return xml::get_legemiddelmerkevare(n);
          })};
  return container;
}

Container<xml::Legemiddelpakning>
catalog_legemiddelpakning(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  const auto container{xml::get_category<xml::Legemiddelpakning>(
      node, "KatLegemiddelpakning", [](const pugi::xml_node &n) {
        return festlib::xml::get_legemiddelpakning(n);
      })};
  return container;
}

Map<std::string, xml::Legemiddelpakning>
map_catalog_legemiddelpakning(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  const Map<std::string, xml::Legemiddelpakning> container{
      xml::get_category_map<xml::Legemiddelpakning>(
          node, "KatLegemiddelpakning", [](const pugi::xml_node &n) {
            return xml::get_legemiddelpakning(n);
          })};
  return container;
}

Map<std::string, xml::Legemiddelpakning> map_catalog_legemiddelpakning(
    const Container<xml::Legemiddelpakning> &container) {

  Map<std::string, xml::Legemiddelpakning> map_container{};

  for (const auto &value : container) {
    map_container.emplace(value.key(), value);
  }

  return map_container;
}

Container<xml::Legemiddelpakning>
generic_legemiddelpakning(const Container<xml::Legemiddelpakning> &container,
                          const xml::IDREF &reference) {
  return find_generic(container, reference);
}

Container<xml::Legemiddelpakning>
generic_legemiddelpakning(const Container<xml::Legemiddelpakning> &container,
                          const xml::Legemiddelpakning &legemiddelpakning) {
  return find_generic(container,
                      legemiddelpakning.pakningbyttegruppe()->refbyttegruppe());
}

} // namespace festlib
