#ifndef PAKNINGSKOMPONENT_H_
#define PAKNINGSKOMPONENT_H_

#include "container.h"
#include "cv.h"
#include "get_container.h"
#include "get_value.h"
#include "pq.h"
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// information about each component
// when there is two or more components
// that is mixed together.
// example: liquid and powder
class Pakningskomponent {
public:
  constexpr Pakningskomponent() = default;
  explicit Pakningskomponent(const Cv &pakningstype, const Pq &mengde,
                             std::string_view antall);
  ~Pakningskomponent() = default;
  constexpr const auto &pakningstype() const { return m_pakningstype; }

private:
  // same as attribute in packagetype
  // <KodeVerk> 7449
  Cv m_pakningstype{};
  // same as attribute in PakningsInformasjon
  // <KodeVerk> 7452
  Pq m_mengde{};
  // same as attribute in PakningsInformasjon
  std::string m_antall{}; // TODO: actually a int.
};

// non-member functions

Container<xml::Pakningskomponent>
get_pakningskomponent(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
