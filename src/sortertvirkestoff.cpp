//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "sortertvirkestoff.h"

namespace festlib {
namespace xml {

bool SortertVirkestoff::push_back(const std::string &sortering,
                                  const IDREF &refvirkestoff) {
  // if (!check_container(sortering)) {
  m_sortering.push_back(std::pair{sortering, refvirkestoff});
  // return true;
  //}
  // return false;
  return true;
}

// bool SortertVirkestoff::check_container(int sortering) const {
//   for (const auto &value : m_sortering) {
//     if (value.first == sortering)
//       return true;
//   }
//   return false;
// }

// non-member functions

xml::SortertVirkestoff
get_sorteringvirkestoffmedstyrke(const pugi::xml_node &node) {
  xml::SortertVirkestoff sortertmedstyrke{};

  // get the sortering and reference
  Container<std::pair<std::string, xml::IDREF>> sortering =
      get_container<std::pair<std::string, xml::IDREF>>(
          node, "SortertVirkestoffMedStyrke", [](const pugi::xml_node &n) {
            const std::string sort{get_value(n, "Sortering")};
            // const int sort_num = std::stoi(sort);

            const xml::IDREF ref{get_value(n, "RefVirkestoffMedStyrke")};
            return std::pair<std::string, xml::IDREF>{sort, ref};
          });

  for (const auto &pair : sortering) {
    // the pair.first should be unique, starting from 0
    // .push_back() checks if container already contains a 'sorting'
    sortertmedstyrke.push_back(pair.first, pair.second);
  }

  return sortertmedstyrke;
}

xml::SortertVirkestoff
get_sorteringvirkestoffutenstyrke(const pugi::xml_node &node) {
  xml::SortertVirkestoff sortertmedstyrke{};

  // get the sortering and reference
  Container<std::pair<std::string, xml::IDREF>> sortering =
      get_container<std::pair<std::string, xml::IDREF>>(
          node, "SortertVirkestoffUtenStyrke", [](const pugi::xml_node &n) {
            const std::string sort{get_value(n, "Sortering")};
            // const int sort_num = std::stoi(sort);

            const xml::IDREF ref{get_value(n, "RefVirkestoff")};
            return std::pair<std::string, xml::IDREF>{sort, ref};
          });

  for (const auto &pair : sortering) {
    // the pair.first should be unique, starting from 0
    // .push_back() checks if container already contains a 'sorting'
    sortertmedstyrke.push_back(pair.first, pair.second);
  }

  return sortertmedstyrke;
}

} // namespace xml
} // namespace festlib
