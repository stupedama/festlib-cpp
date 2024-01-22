//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#include "administrering_legemiddel.h"

namespace festlib {
namespace xml {
AdministreringLegemiddel::AdministreringLegemiddel(
    bool blandingsveske, const Container<IDREF> &refbladingsveske,
    const Container<Cv> &administrasjonsvei, const Cs &kanknuses,
    const Cs &kanapnes, const Cs &bolus, const Cs &injeksjonshastighetbolus,
    const Cs &deling, const Container<Cv> &enhetdosering,
    const Container<Cv> &kortdose, const Container<Cv> &forhandsregelinntak)
    : m_blandingsveske{blandingsveske}, m_refblandingsveske{refbladingsveske},
      m_administrasjonsvei{administrasjonsvei}, m_kanknuses{kanknuses},
      m_kanapnes{kanapnes}, m_bolus{bolus},
      m_injeksjonshastighetbolus{injeksjonshastighetbolus}, m_deling{deling},
      m_enhetdosering{enhetdosering}, m_kortdose{kortdose},
      m_forhandsregelinntak{forhandsregelinntak} {}

std::optional<Container<IDREF>>
AdministreringLegemiddel::refbladingsveske() const {
  return check_empty(m_refblandingsveske);
}

std::optional<Cs> AdministreringLegemiddel::kanknuses() const {
  return check_empty(m_kanknuses);
}

std::optional<Cs> AdministreringLegemiddel::kanapnes() const {
  return check_empty(m_kanapnes);
}

std::optional<Cs> AdministreringLegemiddel::bolus() const {
  return check_empty(m_bolus);
}

std::optional<Cs> AdministreringLegemiddel::injeksjonshastighetbolus() const {
  return check_empty(m_injeksjonshastighetbolus);
}

std::optional<Cs> AdministreringLegemiddel::deling() const {
  return check_empty(m_deling);
}

std::optional<Container<Cv>> AdministreringLegemiddel::enhetdosering() const {
  return check_empty(m_enhetdosering);
}

std::optional<Container<Cv>> AdministreringLegemiddel::kortdose() const {
  return check_empty(m_kortdose);
}

std::optional<Container<Cv>>
AdministreringLegemiddel::forhandsregelinntak() const {
  return check_empty(m_forhandsregelinntak);
}

// non-member functions

xml::AdministreringLegemiddel
get_administreringlegemiddel(const pugi::xml_node &node) {
  const pugi::xml_node admin_node{node.child("AdministreringLegemiddel")};

  // TODO: use the pugi:: to return .bool()
  bool blandingsveske{false};
  const std::string blandingsveske_string{
      get_value(admin_node, "Blandingsveske")};

  if (blandingsveske_string.compare("true") == 0)
    blandingsveske = true;

  const Container<xml::IDREF> refbladingsveske{get_container<xml::IDREF>(
      admin_node, "RefBlandingsVeske",
      [](const pugi::xml_node &n) { return get_value(n); })};

  const Container<Cv> administrasjonsvei{
      get_container<Cv>(admin_node, "Administrasjonsvei",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  const Cs kanknuses{get_cs(node, "KanKnuses")};
  const Cs kanapnes{get_cs(node, "KanApnes")};
  const Cs bolus{get_cs(node, "Bolus")};
  const Cs injeksjonshastighetbolus{get_cs(node, "InjeksjonshastighetBolus")};
  const Cs deling{get_cs(node, "Deling")};

  const Container<Cv> enhetdosering{
      get_container<Cv>(admin_node, "EnhetDosering",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  const Container<Cv> kortdose{
      get_container<Cv>(admin_node, "Kortdose",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  const Container<Cv> forhandsregelinntak{
      get_container<Cv>(admin_node, "ForhandsregelInntak",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  return xml::AdministreringLegemiddel{blandingsveske,
                                       refbladingsveske,
                                       administrasjonsvei,
                                       kanknuses,
                                       kanapnes,
                                       bolus,
                                       injeksjonshastighetbolus,
                                       deling,
                                       enhetdosering,
                                       kortdose,
                                       forhandsregelinntak};
}

} // namespace xml
} // namespace festlib
