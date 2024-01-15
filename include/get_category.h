#ifndef GET_CATEGORY_H_
#define GET_CATEGORY_H_

#include <functional>
#include <string_view>
#include <pugixml.hpp>
#include "container.h"

namespace festlib
{
  namespace xml
  {

    // Categories of the fest file, like <KatLegemiddelMerkevare>, <KatLegemiddelpakning>.
    // <FEST>
    //  <KatLegemiddelMerkevare>
    //    <OppfLegemiddelMerkevare></OppfLeggmiedelMerkevare>
    //  </KateLegemiddelMerkevare>
    // </FEST>
    template<typename T>
    Container<T> get_category(const pugi::xml_node& node, std::string_view category, std::function<T(const pugi::xml_node& node)> func)
    {
      pugi::xml_node category_node{node.child(category.data())};

      // categories contains alot of data
      // reserve space
      constexpr int container_reserve{12000};
      Container<T> container = Container<T>{};
      container.reserve(container_reserve);

      for(const auto& data : category_node)
      {
        container.push_back(func(data));
      }

      return container;
    }

  } // namespace
} // namespace

#endif
