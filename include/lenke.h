#ifndef LENKE_H_
#define LENKE_H_

#include <pugixml.hpp>
#include <string>

namespace festlib {
namespace xml {

using Lenke = std::string;

// Lenke = URL
// Example:
//
// node =
// node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
// Lenke www = get_lenke(node);
xml::Lenke get_lenke(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
