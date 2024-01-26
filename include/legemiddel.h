//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef LEGEMIDDEL_H_
#define LEGEMIDDEL_H_

#include "check_empty.h"
#include "cs.h"
#include "cv.h"
#include "get_bool.h"
#include "pakningbyttegruppe.h"
#include "refusjon.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {
using Name = std::string;
using Reference = std::string;

// Legemiddel = Drug.
// Contains drug information.
// Is used as a component by classes:
// - Legemiddeldose (Drug dosage)
// - Legemiddelvirkestoff (Drug active ingredient)
// - Legemiddelmerkevare
// - Legemiddelpakningmerkevare
class Legemiddel {
public:
  constexpr Legemiddel() = default;
  template <typename T, typename U, typename S, typename R, typename P>
  explicit Legemiddel(T &&atc, S &&navnformstyrke, U &&reseptgruppe,
                      T &&legemiddelformkort, S &&refvilkar, U &&preparattype,
                      U &&typesoknadslv, bool opioidsoknad, T &&svarttrekant,
                      R &&refusjon, P &&pakningbyttegruppe)
      : m_atc{std::forward<T>(atc)},
        m_navnformstyrke{std::forward<S>(navnformstyrke)},
        m_reseptgruppe{std::forward<U>(reseptgruppe)},
        m_legemiddelformkort{std::forward<T>(legemiddelformkort)},
        m_refvilkar{std::forward<S>(refvilkar)},
        m_preparattype{std::forward<U>(preparattype)},
        m_typesoknadslv{std::forward<U>(typesoknadslv)},
        m_opioidsoknad{opioidsoknad},
        m_svarttrekant{std::forward<T>(svarttrekant)},
        m_refusjon{std::forward<R>(refusjon)},
        m_pakningbyttegruppe{std::forward<P>(pakningbyttegruppe)} {}

  // getters
  constexpr const auto &atc() const { return m_atc; }
  constexpr const auto &navnformstyrke() const { return m_navnformstyrke; }
  constexpr const auto &reseptgruppe() const { return m_reseptgruppe; }
  constexpr const auto &legemiddelformkort() const {
    return m_legemiddelformkort;
  }
  constexpr const auto &refvilkar() const { return m_refvilkar; }
  constexpr const auto &preparattype() const { return m_preparattype; }
  constexpr const auto &typesoknadslv() const { return m_typesoknadslv; }
  constexpr bool opioidsoknad() const { return m_opioidsoknad; }
  constexpr const auto &svarttrekant() const { return m_svarttrekant; }
  std::optional<Refusjon> refusjon() const;
  std::optional<PakningByttegruppe> pakningbyttegruppe() const;

private:
  // named as they are in the xml file, only all lowercase.
  Cv m_atc{};
  Name m_navnformstyrke{};
  Cs m_reseptgruppe{};
  Cv m_legemiddelformkort{};
  Reference m_refvilkar{};
  Cs m_preparattype{};
  Cs m_typesoknadslv{};
  bool m_opioidsoknad{};
  Cv m_svarttrekant{};
  Refusjon m_refusjon{};
  PakningByttegruppe m_pakningbyttegruppe{};
};

// non-member functions

// Legemiddel = Drug. Contains ATC, formulation, name and more
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root
//
// node =
// node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Legemiddel lm = get_legemiddel(node);
xml::Legemiddel get_legemiddel(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
