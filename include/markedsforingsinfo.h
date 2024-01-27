//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef MARKEDSFORINGSINFO_H_
#define MARKEDSFORINGSINFO_H_

#include "date.h"
#include "get_value.h"
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// Marketting information
class Markedsforingsinfo {
public:
  constexpr Markedsforingsinfo() = default;
  explicit Markedsforingsinfo(std::string varenrutgaende,
                              Date markedsforingsdato, Date avregdato,
                              Date midlutgattdato,
                              std::string ompakkeravendose);
  constexpr const auto &varenrutgaende() const { return m_varenrutgaende; }
  constexpr const auto &markedsforingsdato() const {
    return m_markedsforingsdato;
  }

private:
  // used when when theres a change
  // of itemnumber. This is the outgoing
  // number
  std::string m_varenrutgaende{};
  // the date first time it was available in
  // the pharmacy
  Date m_markedsforingsdato{};
  // date for deregistration. package is
  // allowed for sale for 3 months after this date.
  // after 3 months it is taken out of FEST.
  Date m_avregdato{};
  // date for temporary deregistration. package
  // is allowed for sale for 3 months after this date.
  // after 3 months it is taken out of FEST.
  // the date will be removed if the package is available again
  Date m_midlutgattdato{};
  // company that have taken over the packaging of
  // the drug. this company now have the marketting lisence.
  // NavnFormStyrke changes name to the new company.
  // example: SA (SykehusApotek) for hospital pharmacy
  std::string m_ompakkeravendose{};
};

xml::Markedsforingsinfo get_markedsforingsinfo(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
