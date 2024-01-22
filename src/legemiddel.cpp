#include "legemiddel.h"

namespace festlib {
namespace xml {

Legemiddel::Legemiddel(const Cv &atc, const Name &navnformstyrke,
                       const Cs &reseptgruppe, const Cv &legemiddelformkort,
                       const Reference &refvilkar, const Cs &preparattype,
                       const Cs &typesoknadslv, bool opioidsoknad,
                       const Cv &svarttrekant, const Refusjon &refusjon,
                       const PakningByttegruppe &pakningbyttegruppe)
    : m_atc{atc}, m_navnformstyrke{navnformstyrke},
      m_reseptgruppe{reseptgruppe}, m_legemiddelformkort{legemiddelformkort},
      m_refvilkar{refvilkar}, m_preparattype{preparattype},
      m_typesoknadslv{typesoknadslv}, m_opioidsoknad{opioidsoknad},
      m_svarttrekant{svarttrekant}, m_refusjon{refusjon},
      m_pakningbyttegruppe{pakningbyttegruppe} {}

std::optional<Refusjon> Legemiddel::refusjon() const {
  if (m_refusjon.refrefusjonsgruppe().empty())
    return {};

  return m_refusjon;
}

std::optional<PakningByttegruppe> Legemiddel::pakningbyttegruppe() const {
  if (m_pakningbyttegruppe.refbyttegruppe().empty())
    return {};

  return m_pakningbyttegruppe;
}

// non-member functions

xml::Legemiddel get_legemiddel(const pugi::xml_node &node) {
  const Cv atc{xml::get_cv(node, "Atc")};
  const std::string navnformstyrke{get_value(node, "NavnFormStyrke")};
  const Cs reseptgruppe{get_cs(node, "Reseptgruppe")};
  const Cv legemiddelformkort{get_cv(node, "LegemiddelformKort")};
  const std::string refvilkar{get_value(node, "RefVilkar")};
  const Cs preparattype{get_cs(node, "Preparattype")};
  const Cs typesoknadslv{get_cs(node, "TypeSoknadSlv")};

  // get OpioidSoknad. It is stored as a string value: true or false
  const std::string opioid_string{get_value(node, "Opioidsoknad")};
  bool opioid{false};

  if (opioid_string.compare("true") == 0)
    opioid = true;

  const Cv svarttrekant{get_cv(node, "SvartTrekant")};

  const xml::Refusjon refusjon{get_refusjon(node)};
  const xml::PakningByttegruppe byttegruppe{get_pakningbyttegruppe(node)};

  return xml::Legemiddel{
      atc,          navnformstyrke, reseptgruppe,  legemiddelformkort,
      refvilkar,    preparattype,   typesoknadslv, opioid,
      svarttrekant, refusjon,       byttegruppe};
}

} // namespace xml
} // namespace festlib
