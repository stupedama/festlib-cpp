#ifndef LEGEMIDDELMERKEVARE_H_
#define LEGEMIDDELMERKEVARE_H_

#include "administrering_legemiddel.h"
#include "enkeltoppforing.h"
#include "legemiddel.h"
#include "preparatomtaleavsnitt.h"
#include "produktinfo.h"
#include "reseptgyldighet.h"
#include "sortertvirkestoff.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {

// LegemiddelMerkevare is a entry for drugs without
// package size.
// is the entry class <OppfLegemiddelMerkevare>
// in the <KatLegemiddelMerkevare>
// is one of many main categories for the fest file
class LegemiddelMerkevare {
public:
  LegemiddelMerkevare() = default;
  explicit LegemiddelMerkevare(
      const Enkeltoppforing &enkeltoppforing, std::string_view varenavn,
      std::string_view legemiddelformlang, const Cs &smak,
      const AdministreringLegemiddel &administreringlegemiddel,
      const Legemiddel &legemiddel,
      const Preparatomtaleavsnitt &preparatomtaleavsnitt,
      const ProduktInfo &produktinfo, const Reseptgyldighet &reseptgyldighet,
      const SortertVirkestoff &sortertvirkestoffmedstyrke);
  const auto &enkeltoppforing() const { return m_enkeltoppforing; };
  const auto &varenavn() const { return m_varenavn; };
  const auto &legemiddelformlang() const { return m_legemiddelformlang; };

private:
  Enkeltoppforing m_enkeltoppforing{}; // id and status
  std::string m_varenavn{};            // Trade name
  std::string m_legemiddelformlang{};  // Long name of formulation
  Cs m_smak{};                         // Taste
  AdministreringLegemiddel m_administreringlegemiddel{};
  Legemiddel m_legemiddel{}; // drug information
  Preparatomtaleavsnitt m_preparatomtaleavsnitt{};
  ProduktInfo m_produktinfo{};                      // productinfo
  Reseptgyldighet m_reseptgyldighet{};              // prescription duration
  SortertVirkestoff m_sortertvirkestoffmedstyrke{}; // sorting from 0 of
                                                    // active ingridient
                                                    // contains reference
};

// non-member functions

// LegemiddelMerkevare is a top entry of the category KatLegemiddelMerkevare.
// contains information about name of product, taste, formulation etc.
// does not contain the package size.
xml::LegemiddelMerkevare get_legemiddelmerkevare(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
