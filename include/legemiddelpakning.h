#ifndef LEGEMIDDELPAKNING_H_
#define LEGEMIDDELPAKNING_H_

#include "administrering_legemiddel.h"
#include "container.h"
#include "enkeltoppforing.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"
#include "legemiddel.h"
#include "markedsforingsinfo.h"
#include "pakningsinfo.h"
#include "pq.h"
#include "preparatomtaleavsnitt.h"
#include "prisvare.h"
#include <optional>
#include <pugixml.hpp>

namespace festlib {
namespace xml {

// Legemiddelpakning is a entry for drugs with
// package size.
// is the entry class <OppfLegemiddelpakning>
// in the <KatLegemiddelpakning>
// is one of many main categories for the fest file
//
// Example:
// festlib::Festlib fest{};
// auto res = fest.load_file("festxml251.xml");
//
// auto legemiddelpakning = catalog_legemiddelpakning(fest);
class Legemiddelpakning {
public:
  constexpr Legemiddelpakning() = default;
  explicit Legemiddelpakning(
      const Enkeltoppforing &enkeltoppforing, const IDREF &id,
      std::string_view varenr, const Container<std::string> &ean,
      const Legemiddel &legemiddel, const Container<Pakningsinfo> &pakningsinfo,
      const Markedsforingsinfo &markedsforingsinfo,
      const Container<PrisVare> &prisvare,
      const AdministreringLegemiddel &administreringlegemiddel,
      const Container<Preparatomtaleavsnitt> &preparatomtaleavsnitt);
  ~Legemiddelpakning() = default;
  constexpr const auto &varenr() const { return m_varenr; }
  constexpr const auto &id() const { return m_id; }
  std::optional<Container<std::string>> ean() const;
  std::optional<std::string> oppbevaring() const;
  constexpr const auto &varenavn() const {
    return m_legemiddel.navnformstyrke();
  }
  std::optional<PakningByttegruppe> pakningbyttegruppe() const;
  // used in std::set
  constexpr const auto &key() const { return varenr(); }

private:
  Enkeltoppforing m_enkeltoppforing{};
  // unique id, even if varenr changes
  IDREF m_id{};
  // itemnumber
  std::string m_varenr{};
  // ean code
  Container<std::string> m_ean{};
  // conservation
  bool m_ikkekonservering{false};
  // storage condition
  Pq m_oppbevaring{};
  Legemiddel m_legemiddel{};
  Container<Pakningsinfo> m_pakningsinfo{};
  Markedsforingsinfo m_markedsforingsinfo{};
  Container<PrisVare> m_prisvare{};
  AdministreringLegemiddel m_administreringlegemiddel{};
  Container<Preparatomtaleavsnitt> m_preparatomtaleavsnitt{};
};

// non-member functions

// Get a legemiddelpakning from: <KatLegemiddelpakning><OppfLegemiddelpakning>
//
// Example:
// auto fest = Festlib{};
// fest.load_file("fest251.xml");
//
// auto node = fest.get_node();
// node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning");
//
// auto legemiddelpakning = get_legemiddelpakning(node);
xml::Legemiddelpakning get_legemiddelpakning(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
