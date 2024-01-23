//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef LEGEMIDDELMERKEVARE_H_
#define LEGEMIDDELMERKEVARE_H_

#include "administrering_legemiddel.h"
#include "enkeltoppforing.h"
#include "legemiddel.h"
#include "preparatomtaleavsnitt.h"
#include "produktinfo.h"
#include "reseptgyldighet.h"
#include "sortertvirkestoff.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// LegemiddelMerkevare is a entry for drugs without
// package size.
// is the entry class <OppfLegemiddelMerkevare>
// in the <KatLegemiddelMerkevare>
// is one of many main categories for the fest file
class LegemiddelMerkevare {
public:
  constexpr LegemiddelMerkevare() = default;
  explicit LegemiddelMerkevare(
      const Enkeltoppforing &enkeltoppforing, const IDREF &id,
      std::string_view varenavn, std::string_view legemiddelformlang,
      const Cs &smak, const AdministreringLegemiddel &administreringlegemiddel,
      const Legemiddel &legemiddel,
      const Preparatomtaleavsnitt &preparatomtaleavsnitt,
      const ProduktInfo &produktinfo, const Reseptgyldighet &reseptgyldighet,
      const SortertVirkestoff &sortertvirkestoffmedstyrke);
  ~LegemiddelMerkevare() = default;
  constexpr const auto &enkeltoppforing() const { return m_enkeltoppforing; };
  constexpr const auto &varenavn() const { return m_varenavn; };
  constexpr const auto &legemiddelformlang() const {
    return m_legemiddelformlang;
  };
  constexpr const auto &id() const { return m_id; }
  constexpr const auto &key() const { return id(); }

private:
  Enkeltoppforing m_enkeltoppforing{}; // id and status
  IDREF m_id{};                        // reference to this/stable id
  std::string m_varenavn{};            // Trade name
  std::string m_legemiddelformlang{};  // Long name of formulation
  Cs m_smak{};                         // Taste
  AdministreringLegemiddel m_administreringlegemiddel{};
  Legemiddel m_legemiddel{}; // drug information
  Preparatomtaleavsnitt m_preparatomtaleavsnitt{};
  ProduktInfo m_produktinfo{};                      // productinfo
  Reseptgyldighet m_reseptgyldighet{};              // prescription duration
  SortertVirkestoff m_sortertvirkestoffmedstyrke{}; // sorting from 0 of
                                                    // active ingridient
                                                    // contains reference
};

// non-member functions

// LegemiddelMerkevare is a top entry of the category KatLegemiddelMerkevare.
// contains information about name of product, taste, formulation etc.
// does not contain the package size.
xml::LegemiddelMerkevare get_legemiddelmerkevare(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
