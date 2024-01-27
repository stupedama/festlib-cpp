//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PAKNINGSINFO_H_
#define PAKNINGSINFO_H_

#include "container.h"
#include "cv.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"
#include "pakningskomponent.h"
#include <pugixml.hpp>

namespace festlib {
namespace xml {

// TODO: add ddd, statistikkfaktor
// Packageinformation
class Pakningsinfo {
public:
  constexpr Pakningsinfo() = default;
  explicit Pakningsinfo(IDREF reflegemiddelmerkevare, std::string pakningsstr,
                        Cv enhetpakning, const Cv &pakningstype,
                        std::string multippel, std::string antall,
                        std::string mengde, std::string sortering,
                        const Pq &ddd, std::string statistikkfaktor,
                        Container<Pakningskomponent> pakningskomponent);
  constexpr const auto &reflegemiddelmerkevare() const {
    return m_reflegemiddelmerkevare;
  }
  // int pakningsstr() const {
  //   return (m_antall * m_multippel * std::stoi(m_pakningsstr));
  // }

private:
  // reference to LegemiddelMerkevare
  IDREF m_reflegemiddelmerkevare{};
  // package size
  std::string m_pakningsstr{};
  // unit for package
  // "Stk", "pkn", "par", "ml", "IE"
  // <KodeVerk> 7452
  // TODO: make enum class?
  Cv m_enhetpakning{};
  // package type
  // <KodeVerk> 7449
  Cv m_pakningstype{};
  // Package size =
  // multippel * antall * mengde
  // used by multiple packages
  std::string m_multippel{}; // TODO: should be int
  // number of containers in package
  std::string m_antall{}; // TODO: should be int
  // size per container
  std::string m_mengde{}; // TODO: actually a double
  // defines the order of packageinfo
  // that belongs to same package
  // starts with 1.
  // only used when there is more than
  // 1 info on package
  std::string m_sortering{}; // TODO: should be int
  // defined daily dose
  // <KodeVerk> 7489
  Pq m_ddd{};
  // used to calculate how many ddd
  // it is in each package.
  // must be used with member m_ddd.
  std::string m_statistikkfaktor{}; // TODO: actually a double
  // information about each komponent when
  // the package contains two or more components
  // that needs to be mixed before administration.
  // example: liquid and powder
  // only used when its relevant
  Container<Pakningskomponent> m_pakningskomponent{};
};

// non-member functions

Container<xml::Pakningsinfo> get_pakningsinfo(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
