#ifndef PQ_H_
#define PQ_H_

#include <string>
#include <string_view>
#include <pugixml.hpp>
#include "get_value.h"

namespace festlib
{
  namespace xml
  {

    // contains value and unit
    struct Pq
    {
      std::string v{};
      std::string u{};
    };


    xml::Pq get_pq(const pugi::xml_node& node, std::string_view attribute = "");

  } // namespace
} // namespace

#endif
