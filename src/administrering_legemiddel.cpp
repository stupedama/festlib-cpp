#include "administrering_legemiddel.h"

namespace festlib
{
  namespace xml
  {
    AdministreringLegemiddel::AdministreringLegemiddel(
            bool blandingsveske,
            const Container<IDREF>& refbladingsveske,
            const Container<Cv>& administrasjonsvei,
            const Cs& kanknuses,
            const Cs& kanapnes,
            const Cs& bolus,
            const Cs& injeksjonshastighetbolus,
            const Cs& deling,
            const Container<Cv>& enhetdosering,
            const Container<Cv>& kortdose,
            const Container<Cv>& forhandsregelinntak)
      :
      m_blandingsveske{blandingsveske},
      m_refblandingsveske{refbladingsveske},
      m_administrasjonsvei{administrasjonsvei},
      m_kanknuses{kanknuses},
      m_kanapnes{kanapnes},
      m_bolus{bolus},
      m_injeksjonshastighetbolus{injeksjonshastighetbolus},
      m_deling{deling},
      m_enhetdosering{enhetdosering},
      m_kortdose{kortdose},
      m_forhandsregelinntak{forhandsregelinntak}
    {
    }

    bool AdministreringLegemiddel::blandingsveske() const
    {
      return m_blandingsveske;
    }

    std::optional<Container<IDREF>> AdministreringLegemiddel::refbladingsveske() const
    {
      return check_empty(m_refblandingsveske);
    }

    Container<Cv> AdministreringLegemiddel::administrasjonsvei() const
    {
      return m_administrasjonsvei;
    }

    std::optional<Cs> AdministreringLegemiddel::kanknuses() const
    {
      return check_empty(m_kanknuses);
    }

    std::optional<Cs> AdministreringLegemiddel::kanapnes() const
    {
      return check_empty(m_kanapnes);
    }

    std::optional<Cs> AdministreringLegemiddel::bolus() const
    {
      return check_empty(m_bolus);
    }

    std::optional<Cs> AdministreringLegemiddel::injeksjonshastighetbolus() const
    {
      return check_empty(m_injeksjonshastighetbolus);
    }

    std::optional<Cs> AdministreringLegemiddel::deling() const
    {
      return check_empty(m_deling);
    }

    std::optional<Container<Cv>> AdministreringLegemiddel::enhetdosering() const
    {
      return check_empty(m_enhetdosering);
    }

    std::optional<Container<Cv>> AdministreringLegemiddel::kortdose() const
    {
      return check_empty(m_kortdose);
    }

    std::optional<Container<Cv>> AdministreringLegemiddel::forhandsregelinntak() const
    {
      return check_empty(m_forhandsregelinntak);
    }

  } // namespace
} // namespace
