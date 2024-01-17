#ifndef PQ_H_
#define PQ_H_

#include "get_value.h"
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// contains value and unit
struct Pq {
  std::string v{};
  std::string u{};
};

xml::Pq get_pq(const pugi::xml_node &node, std::string_view attribute = "");

} // namespace xml
} // namespace festlib

#endif
