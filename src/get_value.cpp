#include "get_value.h"

namespace festlib {
namespace xml {

Value get_value(const pugi::xml_node &node, std::string_view attribute) {
  if (attribute.length() > 0) {
    return node.child_value(attribute.data());
  } else {
    return node.child_value();
  }
}

} // namespace xml
} // namespace festlib
