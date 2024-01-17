#include "preparatomtaleavsnitt.h"

namespace festlib {
namespace xml {

Preparatomtaleavsnitt::Preparatomtaleavsnitt(const Cs &avsnittoverskrift,
                                             const Lenke &lenke)
    : m_avsnittoverskrift{avsnittoverskrift}, m_lenke{lenke} {}

// non-member functions

xml::Preparatomtaleavsnitt
get_preparatomtaleavsnitt(const pugi::xml_node &node) {
  const pugi::xml_node avsnitt_node{node.child("Preparatomtaleavsnitt")};

  const xml::Cs avsnittoverskrift{get_cs(avsnitt_node, "Avsnittoverskrift")};
  const xml::Lenke lenke{get_lenke(avsnitt_node)};

  return xml::Preparatomtaleavsnitt{avsnittoverskrift, lenke};
}

} // namespace xml
} // namespace festlib
