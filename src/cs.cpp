#include "cs.h"

// CS = Coded Simple Value.
// V and DN is manidatory values in the Xml fest file

namespace festlib {
namespace xml {

Cs::Cs(std::string_view V, std::string_view DN) : m_v{V}, m_dn{DN} {}

Cs Cs::operator=(const Cs &other) {
  if (this == &other)
    return *this;

  m_dn = other.m_dn;
  m_v = other.m_v;

  return *this;
}

// no--member functions

// compare the V attributes
bool operator==(const Cs &lhs, const Cs &rhs) {
  return lhs.value() == rhs.value();
}

// compare the V attributes
bool operator==(const Cs &lhs, const char *str) {
  const std::string_view compare_string{str};
  return compare_string.compare(lhs.value()) == 0;
}

xml::Cs get_cs(const pugi::xml_node &node, std::string_view attribute) {
  pugi::xml_node child{node};

  if (attribute.length() > 0) {
    child = node.child(attribute.data());
  }

  const std::string v{child.attribute("V").value()};
  const std::string dn{child.attribute("DN").value()};

  return xml::Cs{v, dn};
}

} // namespace xml
} // namespace festlib
