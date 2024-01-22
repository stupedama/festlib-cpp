#ifndef REFUSJON_H_
#define REFUSJON_H_

#include "check_empty.h"
#include "container.h"
#include "date.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

class Refusjon {
public:
  constexpr Refusjon() = default;
  explicit Refusjon(const Container<IDREF> &refrefusjonsgruppe,
                    std::string_view gyldigfradato,
                    std::string_view forskrivestildato,
                    std::string_view utleverestildato);
  ~Refusjon() = default;

  constexpr const auto &refrefusjonsgruppe() const {
    return m_refrefusjonsgruppe;
  }
  constexpr const auto &gyldigfradato() const { return m_gyldigfradato; }
  std::optional<Date> forskrivestildato() const;
  std::optional<Date> utleverestildato() const;

private:
  // Reference to what refundgroup this package belongs to
  Container<IDREF> m_refrefusjonsgruppe{};
  // Date the refund is available from
  Date m_gyldigfradato{};
  // Date the refund is available to
  Date m_forskrivestildato{};
  // Date for how long it can be handed over
  Date m_utleverestildato{};
};

// non-member functions

// Refusjon = Refund. Contains reference to refundgroup and periode the refund
// is valid Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node();
//
// node =
// node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
// Refusjon refusjon = get_refusjon(node);
xml::Refusjon get_refusjon(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
