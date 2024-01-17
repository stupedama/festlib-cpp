#include "pq.h"

namespace festlib {
namespace xml {

xml::Pq get_pq(const pugi::xml_node &node, std::string_view attribute) {
  pugi::xml_node child{node};

  if (attribute.length() > 0)
    child = node.child(attribute.data());

  const std::string v{child.attribute("V").value()};
  const std::string u{child.attribute("U").value()};

  return Pq{v, u};
}

} // namespace xml
} // namespace festlib
