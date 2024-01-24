//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

// Main class that handles the reading of the XML file or string.
// after loading the source, it contains a pugi::xml_node and the
// pugi::xml_document. non-member functions is used to get the data.
//
// Example: get the HentetDato (Fest XML update date):
// Festlib fest{};
// try {
//  bool load = fest.load_file(filename);
// } catch (const festlib::exceptions::FileNotFound& e) {
//   std::cerr << e.what();
// }
// auto date = fest.created_date(fest);

#ifndef FESTLIB_H_
#define FESTLIB_H_

#include "container.h"
#include "date.h"
#include "exceptions.h"
#include "get_category.h"
#include "get_value.h"
#include "idref.h"
#include "legemiddelmerkevare.h"
#include "legemiddelpakning.h"
#include <pugixml.hpp>
#include <string_view>

namespace festlib {

class Festlib {
public:
  Festlib();
  ~Festlib() = default;
  void load_file(std::string_view filename);
  void load_string(std::string_view xml_string);
  pugi::xml_node get_node() const;

private:
  // check the pugi::xml_parse_result and throw exception if
  // some sort of error
  void check_result(const pugi::xml_parse_result &result) const;
  // validate the FEST file
  void validate_file() const;

private:
  pugi::xml_document m_doc{};
};

// library interface

// return the <FEST><HentetDato>Timestamp</HentetDato></FEST>
// Example:
//
// auto fest = festlib::Festlib{};
// fest.load_file("fest251.xml");
// auto date = created_date(fest);
Date created_date(const Festlib &fest);

// return the catalog <KatLegemiddelMerkevare>
// Example:
//
// auto fest = festlib::Festlib{};
// fest.load_file("fest251.xml");
// auto container = catalog_legemiddelmerkevare(fest);
Container<xml::LegemiddelMerkevare>
catalog_legemiddelmerkevare(const Festlib &fest);

// return the catalog <KatLegemiddelMerkevare> as a Map.
// (unoredered map). Stores id/refLegemiddelMerkevare as key as a
// std::string.
//
// Example:
// auto fest = festlib::Festlib{};
// fest.load_file("fest251.xml");
// auto container = map_catalog_legemiddelmerkevare(fest);
// auto item = container["ID_000A27B8-3930-4264-80F9-CDB14C895662"];
Map<std::string, xml::LegemiddelMerkevare>
map_catalog_legemiddelmerkevare(const Festlib &fest);

// return the catalog <KatLegemiddelpakning>
// used in for example to find generic drugs,
// for use in function generic_legemiddelpakning().
// Example:
//
// auto fest = festlib::Festlib{};
// fest.load_file("fest251.xml");
// auto container = catalog_legemiddelpakning(fest);
Container<xml::Legemiddelpakning>
catalog_legemiddelpakning(const Festlib &fest);

// return the catalog <KatLegemiddelpakning> as a Map.
// (unoredered map). Stores varenr/itemnum as key as a
// std::string.
//
// Example:
// auto fest = festlib::Festlib{};
// fest.load_file("fest251.xml");
//   auto container = map_catalog_legemiddelpakning(fest);
//   auto item = container["116772"];
Map<std::string, xml::Legemiddelpakning>
map_catalog_legemiddelpakning(const Festlib &fest);

// Create Map container from Container, insted of
// reading the xml file again
//
// Example:
// auto container = catalog_legemiddelpakning(fest);
// auto map_container = map_container_legemiddelpakning(container);
Map<std::string, xml::Legemiddelpakning> map_catalog_legemiddelpakning(
    const Container<xml::Legemiddelpakning> &container);

// Uses catalog_legemiddelpakning() to find a generic drug
Container<xml::Legemiddelpakning>
generic_legemiddelpakning(const Container<xml::Legemiddelpakning> &container,
                          const xml::Legemiddelpakning &legemiddelpakning);

// Uses catalog_legemiddelpakning() to find a generic drug
Container<xml::Legemiddelpakning>
generic_legemiddelpakning(const Container<xml::Legemiddelpakning> &container,
                          const xml::IDREF &id);

} // namespace festlib

#endif
