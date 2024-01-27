//              Copyright Festlib Authors
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.gnu.org/licenses/gpl-3.0.txt)

//  SPDX-FileCopyrightText: 2024 Fredrik Fjeldvær <fredrik@ffj.no>
//  SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ADMINISTRERING_LEGEMIDDEL_H_
#define ADMINISTRERING_LEGEMIDDEL_H_

#include "check_empty.h"
#include "container.h"
#include "cs.h"
#include "cv.h"
#include "get_bool.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"
#include <optional>
#include <pugixml.hpp>
#include <string>

namespace festlib {
namespace xml {

// Used only by class LegemiddelMerkevare and LegemiddelVirkestoff.
class AdministreringLegemiddel {
public:
  constexpr AdministreringLegemiddel() = default;
  explicit AdministreringLegemiddel(
      bool blandingsveske, Container<IDREF> refbladingsveske,
      Container<Cv> administrasjonsvei, Cs kanknuses, Cs kanapnes, Cs bolus,
      Cs injeksjonshastighetbolus, Cs deling, Container<Cv> enhetdosering,
      Container<Cv> kortdose, Container<Cv> forhandsregelinntak);
  constexpr bool blandingsveske() const { return m_blandingsveske; };
  std::optional<Container<IDREF>> refbladingsveske() const;
  constexpr const auto &administrasjonsvei() const {
    return m_administrasjonsvei;
  }
  std::optional<Cs> kanknuses() const;
  std::optional<Cs> kanapnes() const;
  std::optional<Cs> bolus() const;
  std::optional<Cs> injeksjonshastighetbolus() const;
  std::optional<Cs> deling() const;
  std::optional<Container<Cv>> enhetdosering() const;
  std::optional<Container<Cv>> kortdose() const;
  std::optional<Container<Cv>> forhandsregelinntak() const;

private:
  // used for all drugs that can be mixed liquid.
  // it will be set to true, other drugs that are not mixing liquids
  // does not contain this attribute
  bool m_blandingsveske{false};

  // only used for drugs that is mixed in mixing liquids.
  // IDRED to one or more mixing liquids, in the form of
  // class LegemiddelMerkevare or class LegemiddelVirkestoff.
  // The reference will go to to LegemiddelMerkevare or LegemiddelVirkestoff
  // if it have the attribute "Er blandingsvæske", primary to
  // LegemiddelVirkestoff.
  //
  // If the drug is not represented in LegemiddelVirkestoff, it will reference
  // to LegemiddelMerkevare.
  Container<IDREF> m_refblandingsveske{};

  // administration route that is permitted by the SPC.
  // <KodeVerk> 7477
  Container<Cv> m_administrasjonsvei{};

  // indicates if the drug can be pulverized.
  // Used only in class LegemiddelMerkevare.
  // Not all generics contains the same
  // information and therefor not used in
  // LegemiddelVirkestoff.
  //
  // drugs that this is not relevant does not contain this attribute
  // <KodeVerk> 1103
  Cs m_kanknuses{};

  // indicates if the drug can be opened.
  // Information only in class LegemiddelMerkevare.
  // Not all generics contains the same
  // information and therefor not used in
  // LegemiddelVirkestoff.
  //
  // drugs that this is not relevant does not contain this attribute
  // <KodeVerk> 1103
  Cs m_kanapnes{};

  // true on injections that can be given as bolusdose.
  // also set as true when its not recommended in every context.
  // <KodeVerk> 7470
  Cs m_bolus{};

  // defines injectionspeed of drugs that can be given as bolus.
  // <KodeVerk> 7471
  Cs m_injeksjonshastighetbolus{};

  // seperation of dosage, for example tablets.
  // only in class LegemiddelMerkevare and only for
  // formulations that is relevant.
  // <KodeVerk> 7472
  Cs m_deling{};

  // unit for dosage. suggestion for what should
  // be typed on the pharmacy label.
  // See page 77 in documentation.
  // KodeVerk: 7480
  Container<Cv> m_enhetdosering{};

  // contains dosage guideance with text for the patient
  // KodeVerk: 7478
  Container<Cv> m_kortdose{};

  // precautions before intake.
  // there should be room on the pharmacy label for this field.
  // there could be more than one precautions for one medicine
  // KodeVerk: 7479
  Container<Cv> m_forhandsregelinntak{};

  // description of what the medicine is used for.
  // optional, how it is used.
  // used for the pharmacy label.
  // KodeVerk: 7488
  Container<Cv> m_bruksomradeetikett{};
};

// non-member functions

// AdministreringLegemiddel
// only used in class LegemiddelMerkevare and LegemiddelVirkestoff
// contains information about administration of the drug
// for example: precautions for intake, usage/indication on pharmacy label.
xml::AdministreringLegemiddel
get_administreringlegemiddel(const pugi::xml_node &node);

} // namespace xml
} // namespace festlib

#endif
