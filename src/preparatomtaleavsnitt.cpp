//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "preparatomtaleavsnitt.h"

namespace festlib {
namespace xml {

// non-member functions

xml::Preparatomtaleavsnitt
get_preparatomtaleavsnitt(const pugi::xml_node &node) {
  const pugi::xml_node avsnitt_node{node.child("Preparatomtaleavsnitt")};

  const xml::Cs avsnittoverskrift{get_cs(avsnitt_node, "Avsnittoverskrift")};
  const xml::Lenke lenke{get_lenke(avsnitt_node)};

  return xml::Preparatomtaleavsnitt{avsnittoverskrift, lenke};
}

} // namespace xml
} // namespace festlib
