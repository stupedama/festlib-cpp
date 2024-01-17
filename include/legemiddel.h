#ifndef LEGEMIDDEL_H_
#define LEGEMIDDEL_H_

#include "check_empty.h"
#include "cs.h"
#include "cv.h"
#include "pakningbyttegruppe.h"
#include "refusjon.h"
#include <optional>
#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {
using Name = std::string;
using Reference = std::string;

// Legemiddel = Drug.
// Contains drug information.
// Is used as a component by classes:
// - Legemiddeldose (Drug dosage)
// - Legemiddelvirkestoff (Drug active ingredient)
// - Legemiddelmerkevare
// - Legemiddelpakningmerkevare
class Legemiddel {

public:
  Legemiddel() = default;
  explicit Legemiddel(const Cv &atc, const Name &navnformstyrke,
                      const Cs &reseptgruppe, const Cv &legemiddelformkort,
                      const Reference &refvilkar, const Cs &preparattype,
                      const Cs &typesoknadslv, bool opioidsoknad,
                      const Cv &svarttrekant, const Refusjon &refusjon,
                      const PakningByttegruppe &pakningbyttegruppe);
  ~Legemiddel() = default;

  // getters
  const auto &atc() const { return m_atc; }
  const auto &navnformstyrke() const { return m_navnformstyrke; }
  const auto &reseptgruppe() const { return m_reseptgruppe; }
  const auto &legemiddelformkort() const { return m_legemiddelformkort; }
  const auto &refvilkar() const { return m_refvilkar; }
  const auto &preparattype() const { return m_preparattype; }
  const auto &typesoknadslv() const { return m_typesoknadslv; }
  bool opioidsoknad() const;
  const auto &svarttrekant() const { return m_svarttrekant; }
  std::optional<Refusjon> refusjon() const;
  std::optional<PakningByttegruppe> pakningbyttegruppe() const;

private:
  // named as they are in the xml file, only all lowercase.
  Cv m_atc{};
  Name m_navnformstyrke{};
  Cs m_reseptgruppe{};
  Cv m_legemiddelformkort{};
  Reference m_refvilkar{};
  Cs m_preparattype{};
  Cs m_typesoknadslv{};
  bool m_opioidsoknad{};
  Cv m_svarttrekant{};
  Refusjon m_refusjon{};
  PakningByttegruppe m_pakningbyttegruppe{};
};

// non-member functions

// Legemiddel = Drug. Contains ATC, formulation, name and more
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root
//
// node =
// node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Legemiddel lm = get_legemiddel(node);
xml::Legemiddel get_legemiddel(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
