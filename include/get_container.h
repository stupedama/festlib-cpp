#ifndef GET_CONTAINER_H_
#define GET_CONTAINER_H_

#include "container.h"
#include <functional>
#include <pugixml.hpp>
#include <string_view>

namespace festlib {
namespace xml {

// Iterates over a attribute that contains one or more values
template <typename T>
Container<T> get_container(const pugi::xml_node &node,
                           std::string_view attribute,
                           std::function<T(const pugi::xml_node &node)> func) {
  Container<T> node_container = Container<T>{};

  for (const auto &child_node : node) {
    if (attribute.compare(child_node.name()) == 0) {
      node_container.push_back(func(child_node));
    }
  }

  return node_container;
}

} // namespace xml
} // namespace festlib

#endif
