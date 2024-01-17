#ifndef RESEPTGYLDIGHET_H_
#define RESEPTGYLDIGHET_H_

#include "check_empty.h"
#include "cs.h"
#include "get_value.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// Defines the duration of the prescription
class Reseptgyldighet {
public:
  Reseptgyldighet() = default;
  Reseptgyldighet(const Cs &kjonn, std::string_view varighet);
  std::optional<Cs> kjonn() const;
  const auto &varighet() const { return m_varighet; }

private:
  // gender defines the gender for the duration
  // <KodeVerk> 3101
  Cs m_kjonn{};
  // duration of the prescription
  // <KodeVerk> 3101
  std::string m_varighet{};
};

// non-member functions

// Prescription duration
// defines the duration of the prescription
xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
