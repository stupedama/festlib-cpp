#ifndef LEGEMIDDELMERKEVARE_H_
#define LEGEMIDDELMERKEVARE_H_

#include <optional>
#include <string>
#include <string_view>
#include "administrering_legemiddel.h"
#include "enkeltoppforing.h"
#include "legemiddel.h"
#include "preparatomtaleavsnitt.h"
#include "produktinfo.h"
#include "reseptgyldighet.h"
#include "sortertvirkestoff.h"

namespace festlib
{
  namespace xml
  {

    // is the entry class <OppfLegemiddelMerkevare>
    // in the <KatLegemiddelMerkevare>
    // is one of many main categories for the fest file
    class LegemiddelMerkevare
    {
      public:
        LegemiddelMerkevare() = default;
        explicit LegemiddelMerkevare(
            const Enkeltoppforing& enkeltoppforing,
            std::string_view varenavn,
            std::string_view legemiddelformlang,
            const Cs& smak,
            const AdministreringLegemiddel& administreringlegemiddel,
            const Legemiddel& legemiddel,
            const Preparatomtaleavsnitt& preparatomtaleavsnitt,
            const ProduktInfo& produktinfo,
            const Reseptgyldighet& reseptgyldighet,
            const SortertVirkestoff& sortertvirkestoffmedstyrke,
            const SortertVirkestoff& sortertvirkestoffutenstyrke);
        Enkeltoppforing enkeltoppforing() const;
        std::string varenavn() const;
        std::string legemiddelformlang() const;
      private:
        Enkeltoppforing m_enkeltoppforing{};
        // name of product/drug
        std::string m_varenavn{};
        // long name of formulation, for example:
        // Tablett, filmdrasjert
        std::string m_legemiddelformlang{};
        // Taste
        Cs m_smak{};
        AdministreringLegemiddel m_administreringlegemiddel{};
        Legemiddel m_legemiddel{};
        Preparatomtaleavsnitt m_preparatomtaleavsnitt{};
        ProduktInfo m_produktinfo{};
        Reseptgyldighet m_reseptgyldighet{};
        SortertVirkestoff m_sortertvirkestoffmedstyrke{};
        SortertVirkestoff m_sortertvirkestoffutenstyrke{};
    };

  } // namespace
} // namespace

#endif
