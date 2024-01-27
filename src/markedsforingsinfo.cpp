//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "markedsforingsinfo.h"

namespace festlib {
namespace xml {
Markedsforingsinfo::Markedsforingsinfo(std::string varenrutgaende,
                                       Date markedsforingsdato, Date avregdato,
                                       Date midlutgattdato,
                                       std::string ompakkeravendose)
    : m_varenrutgaende{std::move(varenrutgaende)},
      m_markedsforingsdato{std::move(markedsforingsdato)},
      m_avregdato{std::move(avregdato)},
      m_midlutgattdato{std::move(midlutgattdato)},
      m_ompakkeravendose{std::move(ompakkeravendose)} {}

// non-member functions

xml::Markedsforingsinfo get_markedsforingsinfo(const pugi::xml_node &node) {
  const pugi::xml_node child{node.child("Markedsforingsinfo")};

  std::string varenrutgaende{get_value(child, "VarenrUtgaende")};
  Date markedsforingsdato{get_value(child, "Markedsforingsdato")};
  Date avregdato{get_value(child, "AvregDato")};
  Date midlutgattdato{get_value(child, "MidlUtgattDato")};
  std::string ompakkeravendose{get_value(child, "OmpakkerAvEndose")};

  return xml::Markedsforingsinfo{
      std::move(varenrutgaende), std::move(markedsforingsdato),
      std::move(avregdato), std::move(midlutgattdato),
      std::move(ompakkeravendose)};
}

} // namespace xml
} // namespace festlib
