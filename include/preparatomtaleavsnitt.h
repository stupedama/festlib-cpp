//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PREPARATOMTALEAVSNITT_H_
#define PREPARATOMTALEAVSNITT_H_

#include "cs.h"
#include "lenke.h"
#include <pugixml.hpp>

namespace festlib {
namespace xml {

// contains data about SPC and link to SPC
class Preparatomtaleavsnitt {
public:
  explicit Preparatomtaleavsnitt(Cs avsnittoverskrift, Lenke lenke);
  constexpr const auto &avsnittoverskrift() const {
    return m_avsnittoverskrift;
  }
  constexpr const auto &lenke() const { return m_lenke; }

private:
  Cs m_avsnittoverskrift;
  Lenke m_lenke{};
};

// non-member functions

// Contains SPC and url to SPC.
// Example:
//
// node =
// node.child("KatLegemiddeMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Preparatomtaleavsnitt avsnitt = get_preparatomtaleavsnitt(node);
xml::Preparatomtaleavsnitt
get_preparatomtaleavsnitt(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
