//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "festlib.h"

namespace festlib {

Festlib::Festlib() : m_doc{} {}

void Festlib::load_file(std::string_view filename) {
  // if xml_document is already loaded, the xml_tree will be
  // reset and populated again.
  const auto result = m_doc.load_file(filename.data(), pugi::encoding_auto);

  // throw exception if bad things
  check_result(result);
  validate_file();
}

void Festlib::load_string(std::string_view xml_string) {
  // if xml_document is already loaded, the xml_tree will be
  // reset and populated again.
  const auto result = m_doc.load_string(xml_string.data(), pugi::encoding_auto);

  // throw exception if bad things
  check_result(result);
  validate_file();
}

// return the root of the Fest XML
pugi::xml_node Festlib::get_node() const { return m_doc.child("FEST"); }

// private functions
void Festlib::check_result(const pugi::xml_parse_result &result) const {
  switch (result.status) {
  case pugi::status_ok:
    break;
  case pugi::status_file_not_found:
    throw exceptions::FileNotFound(result.description());
  case pugi::status_io_error:
    throw exceptions::IoError(result.description());
  case pugi::status_out_of_memory:
    throw exceptions::OutOfMemory(result.description());
  case pugi::status_no_document_element:
    throw exceptions::NoDocument(result.description());

  // this is intended
  case pugi::status_bad_end_element:
  case pugi::status_bad_start_element:
  case pugi::status_bad_attribute:
  case pugi::status_bad_pi:
  case pugi::status_end_element_mismatch:
  case pugi::status_bad_doctype:
  case pugi::status_bad_pcdata:
  case pugi::status_bad_comment:
    throw exceptions::BadDocument(result.description());
  default:
    throw std::runtime_error("Unkown xml error");
  }
}

void Festlib::validate_file() const {
  const auto node = get_node();
  std::string_view node_name{node.name()};

  if (node_name.compare("FEST") != 0)
    throw exceptions::BadFestFormat("root is not named FEST");
}

// helper functions
namespace {

Container<xml::OppfLegemiddelpakning>
find_generic(const Container<xml::OppfLegemiddelpakning> &container,
             const xml::IDREF &reference) {

  Container<xml::OppfLegemiddelpakning> result{};

  for (const auto &id : container) {
    if (id.pakningbyttegruppe() == reference)
      result.push_back(std::move(id));
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

  return festlib::xml::get_category<festlib::xml::LegemiddelMerkevare>(
      node, "KatLegemiddelMerkevare", [](const pugi::xml_node &n) {
        return festlib::xml::get_legemiddelmerkevare(n);
      });
}

Map<std::string, xml::LegemiddelMerkevare>
map_catalog_legemiddelmerkevare(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  return xml::get_category_map<xml::LegemiddelMerkevare>(
      node, "KatLegemiddelMerkevare",
      [](const pugi::xml_node &n) { return xml::get_legemiddelmerkevare(n); });
}

Container<xml::OppfLegemiddelpakning>
catalog_legemiddelpakning(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  return {xml::get_category<xml::OppfLegemiddelpakning>(
      node, "KatLegemiddelpakning", [](const pugi::xml_node &n) {
        return festlib::xml::get_oppflegemiddelpakning(n);
      })};
}

Map<std::string, xml::OppfLegemiddelpakning>
map_catalog_legemiddelpakning(const Festlib &fest) {
  const pugi::xml_node node{fest.get_node()};

  return xml::get_category_map<xml::OppfLegemiddelpakning>(
      node, "KatLegemiddelpakning",
      [](const pugi::xml_node &n) { return xml::get_oppflegemiddelpakning(n); });
}

Map<std::string, xml::OppfLegemiddelpakning> map_catalog_legemiddelpakning(
    const Container<xml::OppfLegemiddelpakning> &container) {

  Map<std::string, xml::OppfLegemiddelpakning> map_container{};

  for (const auto &value : container) {
    map_container.emplace(std::move(value.key()), std::move(value));
  }

  return map_container;
}

std::optional<xml::OppfLegemiddelpakning>
find_legemiddelpakning(const Container<xml::OppfLegemiddelpakning> &container,
                       const std::string &varenr) {

  for (auto const &pakning : container) {
    if (pakning.key().compare(varenr) == 0) {
      return pakning;
    }
  }
  return {};
}

std::optional<xml::OppfLegemiddelpakning> find_legemiddelpakning(
    const Map<std::string, xml::OppfLegemiddelpakning> &container,
    const std::string &varenr) {

  try {
    return container.at(varenr);
  } catch (const std::out_of_range &) {
    return {};
  }
}

Container<xml::OppfLegemiddelpakning>
generic_legemiddelpakning(const Container<xml::OppfLegemiddelpakning> &container,
                          const xml::IDREF &reference) {
  return find_generic(container, reference);
}

Container<xml::OppfLegemiddelpakning> generic_legemiddelpakning(
    const Container<xml::OppfLegemiddelpakning> &container,
    std::optional<xml::OppfLegemiddelpakning> legemiddelpakning) {

  if (legemiddelpakning.has_value()) {
    return find_generic(
        container,
        legemiddelpakning.value().pakningbyttegruppe()->refbyttegruppe());
  } else {
    return {};
  }
}

} // namespace festlib
