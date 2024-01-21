#include "get_container.h"

namespace festlib {
namespace xml {

bool compare_value(std::string_view attribute,
                   const pugi::xml_node &child_node) {
  return attribute.compare(child_node.name()) == 0 ? true : false;
}

} // namespace xml
} // namespace festlib
