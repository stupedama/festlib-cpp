#include "legemiddelmerkevare.h"

namespace festlib
{
  namespace xml
  {

    LegemiddelMerkevare::LegemiddelMerkevare(
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
        const SortertVirkestoff& sortertvirkestoffutenstyrke)
      :
      m_enkeltoppforing{enkeltoppforing},
      m_varenavn{varenavn},
      m_legemiddelformlang{legemiddelformlang},
      m_smak{smak},
      m_administreringlegemiddel{administreringlegemiddel},
      m_legemiddel{legemiddel},
      m_preparatomtaleavsnitt{preparatomtaleavsnitt},
      m_produktinfo{produktinfo},
      m_reseptgyldighet{reseptgyldighet},
      m_sortertvirkestoffmedstyrke{sortertvirkestoffmedstyrke},
      m_sortertvirkestoffutenstyrke{sortertvirkestoffutenstyrke}
    {
    }
    
    Enkeltoppforing LegemiddelMerkevare::enkeltoppforing() const
    {
      return m_enkeltoppforing;
    }
    
    std::string LegemiddelMerkevare::varenavn() const
    {
      return m_varenavn;
    }

    std::string LegemiddelMerkevare::legemiddelformlang() const
    {
      return m_legemiddelformlang;
    }

  } // namespace
} // namespace
