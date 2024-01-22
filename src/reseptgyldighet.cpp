#include "reseptgyldighet.h"

namespace festlib {
namespace xml {

Reseptgyldighet::Reseptgyldighet(const Cs &kjonn, std::string_view varighet)
    : m_kjonn{kjonn}, m_varighet{varighet} {}

std::optional<Cs> Reseptgyldighet::kjonn() const {
  return check_empty(m_kjonn);
}

// non-member functions

xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node &node) {
  const pugi::xml_node gyldighet_node{node.child("Reseptgyldighet")};

  const xml::Cs kjonn{get_cs(gyldighet_node, "Kjonn")};
  const std::string varighet{get_value(gyldighet_node, "Varighet")};

  return xml::Reseptgyldighet{kjonn, varighet};
}

} // namespace xml
} // namespace festlib
