#include "lenke.h"

namespace festlib {
namespace xml {

xml::Lenke get_lenke(const pugi::xml_node &node) {
  return node.child("Lenke").child("Www").attribute("V").value();
}

} // namespace xml
} // namespace festlib
