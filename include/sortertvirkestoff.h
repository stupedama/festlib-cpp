//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SORTERTVIRKESTOFF_H_
#define SORTERTVIRKESTOFF_H_

#include "container.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"
#include <functional>
#include <pugixml.hpp>
#include <utility>

namespace festlib {
namespace xml {

// TODO: sortering is actually a int

// sorting of active ingredient.
// sorts the order of the ingredient
class SortertVirkestoff {
public:
  constexpr SortertVirkestoff() = default;
  explicit SortertVirkestoff(const std::string &sortering,
                             const IDREF &refvirkestoff);
  ~SortertVirkestoff() = default;
  constexpr const auto &sortering() const { return m_sortering; };
  bool push_back(const std::string &sortering, const IDREF &refvirkestoff);

private:
  // check if m_sortering already contains sortering value
  // bool check_container(int sortering) const;

private:
  // the pair contains sorting number of active ingredient,
  // starting with 0. Sorting as they are named in <NavnFormStyrke>.
  // the IDREF identifies/reference what active ingredient with strenght
  Container<std::pair<std::string, IDREF>> m_sortering{};
};

// non-member functions

// Sorts the active ingridient after strength and reference to active ingridient
xml::SortertVirkestoff
get_sorteringvirkestoffmedstyrke(const pugi::xml_node &node);

// Sorts the active ingridient without strength and reference to active
// ingridient
xml::SortertVirkestoff
get_sorteringvirkestoffutenstyrke(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
