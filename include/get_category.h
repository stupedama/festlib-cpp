//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef GET_CATEGORY_H_
#define GET_CATEGORY_H_

#include "container.h"
#include <functional>
#include <pugixml.hpp>
#include <string_view>

namespace festlib {
namespace xml {

// Categories of the fest file, like <KatLegemiddelMerkevare>,
// <KatLegemiddelpakning>. <FEST>
//  <KatLegemiddelMerkevare>
//    <OppfLegemiddelMerkevare></OppfLeggmiedelMerkevare>
//  </KateLegemiddelMerkevare>
// </FEST>
template <typename T>
Container<T> get_category(const pugi::xml_node &node, std::string_view category,
                          std::function<T(const pugi::xml_node &node)> func) {
  // categories contains alot of data
  // reserve space
  constexpr int container_reserve{12000};
  Container<T> container = Container<T>{};
  container.reserve(container_reserve);

  for (const auto &data : node.child(category.data())) {
    container.push_back(func(data));
  }

  return std::move(container);
}

// use Set insted of Container
template <typename T>
Map<std::string, T>
get_category_map(const pugi::xml_node &node, std::string_view category,
                 std::function<T(const pugi::xml_node &node)> func) {
  const pugi::xml_node category_node{node.child(category.data())};

  Map<std::string, T> container = Map<std::string, T>{};

  for (const auto &data : category_node) {
    const auto result = func(data);
    container.try_emplace(result.key(), result);
  }

  return std::move(container);
}

} // namespace xml
} // namespace festlib

#endif
