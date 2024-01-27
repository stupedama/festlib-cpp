//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PRISVARE_H_
#define PRISVARE_H_

#include "container.h"
#include "cv.h"
#include "date.h"
#include "get_container.h"
#include "get_value.h"
#include "pq.h"
#include <pugixml.hpp>

namespace festlib {
namespace xml {

class PrisVare {
public:
  constexpr PrisVare() = default;
  explicit PrisVare(Cv type, Pq pris, Date gyldigfradato, Date gyldigtildato);
  constexpr const auto &pris() const { return m_pris.v; }

private:
  // two different types of prices, one for
  // medicines and one for merchendise
  Cv m_type{};
  // currency/price
  // only price in NOK
  // <KodeVerk> 3304
  // TODO: make own type MO
  Pq m_pris{};
  // price is valid from date
  Date m_gyldigfradato{};
  // price is valid to date
  Date m_gyldigtildato{};
};

// non-member functions

Container<xml::PrisVare> get_prisvare(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
