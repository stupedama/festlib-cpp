//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef RESEPTGYLDIGHET_H_
#define RESEPTGYLDIGHET_H_

#include "check_empty.h"
#include "cs.h"
#include "get_value.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// Defines the duration of the prescription
class Reseptgyldighet {
public:
  explicit Reseptgyldighet(Cs kjonn, std::string varighet);
  std::optional<Cs> kjonn() const;
  constexpr const auto &varighet() const { return m_varighet; }

private:
  // gender defines the gender for the duration
  // <KodeVerk> 3101
  Cs m_kjonn;
  // duration of the prescription
  // <KodeVerk> 3101
  std::string m_varighet{};
};

// non-member functions

// Prescription duration
// defines the duration of the prescription
xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
