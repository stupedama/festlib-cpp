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
    bool blandingsveske, Container<IDREF> refbladingsveske,
    Container<Cv> administrasjonsvei, Cs kanknuses, Cs kanapnes, Cs bolus,
    Cs injeksjonshastighetbolus, Cs deling, Container<Cv> enhetdosering,
    Container<Cv> kortdose, Container<Cv> forhandsregelinntak)
    : m_blandingsveske{blandingsveske},
      m_refblandingsveske{std::move(refbladingsveske)},
      m_administrasjonsvei{std::move(administrasjonsvei)},
      m_kanknuses{std::move(kanknuses)}, m_kanapnes{std::move(kanapnes)},
      m_bolus{std::move(bolus)},
      m_injeksjonshastighetbolus{std::move(injeksjonshastighetbolus)},
      m_deling{std::move(deling)}, m_enhetdosering{std::move(enhetdosering)},
      m_kortdose{std::move(kortdose)},
      m_forhandsregelinntak{std::move(forhandsregelinntak)} {}

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

  const bool blandingsveske{get_bool(admin_node, "Blandingsveske")};

  Container<xml::IDREF> refbladingsveske{get_container<xml::IDREF>(
      admin_node, "RefBlandingsVeske",
      [](const pugi::xml_node &n) { return get_value(n); })};

  Container<Cv> administrasjonsvei{
      get_container<Cv>(admin_node, "Administrasjonsvei",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  Cs kanknuses{get_cs(node, "KanKnuses")};
  Cs kanapnes{get_cs(node, "KanApnes")};
  Cs bolus{get_cs(node, "Bolus")};
  Cs injeksjonshastighetbolus{get_cs(node, "InjeksjonshastighetBolus")};
  Cs deling{get_cs(node, "Deling")};

  Container<Cv> enhetdosering{
      get_container<Cv>(admin_node, "EnhetDosering",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  Container<Cv> kortdose{
      get_container<Cv>(admin_node, "Kortdose",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  Container<Cv> forhandsregelinntak{
      get_container<Cv>(admin_node, "ForhandsregelInntak",
                        [](const pugi::xml_node &n) { return get_cv(n); })};

  return xml::AdministreringLegemiddel{blandingsveske,
                                       std::move(refbladingsveske),
                                       std::move(administrasjonsvei),
                                       std::move(kanknuses),
                                       std::move(kanapnes),
                                       std::move(bolus),
                                       std::move(injeksjonshastighetbolus),
                                       std::move(deling),
                                       std::move(enhetdosering),
                                       std::move(kortdose),
                                       std::move(forhandsregelinntak)};
}

} // namespace xml
} // namespace festlib
