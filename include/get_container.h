//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef GET_CONTAINER_H_
#define GET_CONTAINER_H_

#include "container.h"
#include <functional>
#include <pugixml.hpp>
#include <string_view>

namespace festlib {
namespace xml {

// compare node.name and attribute
bool compare_value(std::string_view attribute,
                   const pugi::xml_node &child_node);

// Iterates over a attribute that contains one or more values
template <typename T>
Container<T> get_container(const pugi::xml_node &node,
                           std::string_view attribute,
                           std::function<T(const pugi::xml_node &node)> func) {
  Container<T> node_container = Container<T>{};

  for (const auto &child_node : node) {
    if (compare_value(attribute, child_node))
      node_container.push_back(std::move(func(child_node)));
  }

  return node_container;
}

// Iterate over a attribute that contains one or more values
// the type must contain the method .key().
// template <typename T>
// Set<std::string, T> get_set(const pugi::xml_node &node,
//                            std::string_view attribute,
//                            std::function<T(const pugi::xml_node &node)> func)
//                            {
//  Set<std::string, T> node_set = Set<std::string, T>{};
//
//  for (const auto &child_node : node) {
//    if (compare_value(attribute, child_node)) {
//      const T value = func(child_node);
//      node_set.insert(value.key(), value);
//    }
//  }
//
//  return node_set;
//}

} // namespace xml
} // namespace festlib

#endif
