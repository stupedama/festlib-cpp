//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "markedsforingsinfo.h"

namespace festlib {
namespace xml {

// non-member functions

xml::Markedsforingsinfo get_markedsforingsinfo(const pugi::xml_node &node) {
  const pugi::xml_node child{node.child("Markedsforingsinfo")};

  const std::string varenrutgaende{get_value(child, "VarenrUtgaende")};
  const Date markedsforingsdato{get_value(child, "Markedsforingsdato")};
  const Date avregdato{get_value(child, "AvregDato")};
  const Date midlutgattdato{get_value(child, "MidlUtgattDato")};
  const std::string ompakkeravendose{get_value(child, "OmpakkerAvEndose")};

  return xml::Markedsforingsinfo{varenrutgaende, markedsforingsdato, avregdato,
                                 midlutgattdato, ompakkeravendose};
}

} // namespace xml
} // namespace festlib
