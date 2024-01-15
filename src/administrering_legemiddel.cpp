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

    // non-member functions

    xml::AdministreringLegemiddel get_administreringlegemiddel(const pugi::xml_node& node)
    {
      using festlib::xml::Cv;
      using festlib::xml::Cs;

      const pugi::xml_node admin_node{node.child("AdministreringLegemiddel")};

      // TODO: use the pugi:: to return .bool()
      bool blandingsveske{false};
      const std::string blandingsveske_string{get_value(admin_node, "Blandingsveske")};

      if(blandingsveske_string.compare("true") == 0)
        blandingsveske = true;

      const Container<xml::IDREF> refbladingsveske{get_container<xml::IDREF>(admin_node, "RefBlandingsVeske", [](const pugi::xml_node& n)
      {
        xml::IDREF ref{get_value(n)};
        return ref;
      })};

      const Container<Cv> administrasjonsvei{get_container<Cv>(admin_node, "Administrasjonsvei", [](const pugi::xml_node& n)
      {
        Cv vei{get_cv(n)};
        return vei;
      })};

      const Cs kanknuses{get_cs(node, "KanKnuses")};
      const Cs kanapnes{get_cs(node, "KanApnes")};
      const Cs bolus{get_cs(node, "Bolus")};
      const Cs injeksjonshastighetbolus{get_cs(node, "InjeksjonshastighetBolus")};
      const Cs deling{get_cs(node, "Deling")};

      const Container<Cv> enhetdosering{get_container<Cv>(admin_node, "EnhetDosering", [](const pugi::xml_node& n)
          {
            Cv enhet{get_cv(n)};
            return enhet;
          })};

      const Container<Cv> kortdose{get_container<Cv>(admin_node, "Kortdose", [](const pugi::xml_node& n)
          {
            Cv dose{get_cv(n)};
            return dose;
          })};

      const Container<Cv> forhandsregelinntak{get_container<Cv>(admin_node, "ForhandsregelInntak", [](const pugi::xml_node& n)
          {
            Cv regel{get_cv(n)};
            return regel;
          })};

      return xml::AdministreringLegemiddel{
        blandingsveske,
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

  } // namespace
} // namespace
