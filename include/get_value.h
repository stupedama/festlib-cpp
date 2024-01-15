#ifndef GET_VALUE_H_
#define GET_VALUE_H_

#include <string>
#include <string_view>
#include <pugixml.hpp>

namespace festlib
{
  namespace xml
  {

    using Value = std::string;

    // Get a simple attribute value.
    // Example <HentetDato>TimeStamp</HentetDato>:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // Value date = get_value(node, "HentetDato");
    Value get_value(const pugi::xml_node& node, std::string_view attribute = "");

  } // namespace
} // namespace

#endif
