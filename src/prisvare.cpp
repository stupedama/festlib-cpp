#include "prisvare.h"

namespace festlib {
namespace xml {

PrisVare::PrisVare(const Cv &type, const Pq &pris, const Date &gyldigfradato,
                   const Date &gyldigtildato)
    : m_type{type}, m_pris{pris}, m_gyldigfradato{gyldigfradato},
      m_gyldigtildato{gyldigtildato} {}

// non-member functions

namespace {
xml::PrisVare get_one_prisvare(const pugi::xml_node &node) {
  const Cv type{get_cv(node, "Type")};
  const Pq pris{get_pq(node, "Pris")};
  const Date gyldigfradato{get_value(node, "GyldigFraDato")};
  const Date gyldigtildato{get_value(node, "GyldigTilDato")};

  return xml::PrisVare{type, pris, gyldigfradato, gyldigtildato};
}
} // namespace

Container<xml::PrisVare> get_prisvare(const pugi::xml_node &node) {
  return get_container<xml::PrisVare>(
      node, "PrisVare",
      [](const pugi::xml_node &n) { return get_one_prisvare(n); });
}

} // namespace xml
} // namespace festlib
