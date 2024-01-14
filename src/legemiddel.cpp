#include "legemiddel.h"

namespace festlib
{
  namespace xml
  {

    Legemiddel::Legemiddel(const Cv& atc, const Name& navnformstyrke,
        const Cs& reseptgruppe, const Cv& legemiddelformkort,
        const Reference& refvilkar, const Cs& preparattype,
        const Cs& typesoknadslv, bool opioidsoknad,
        const Cv& svarttrekant, const Refusjon& refusjon,
        const PakningByttegruppe& pakningbyttegruppe)
      : m_atc{atc}, m_navnformstyrke{navnformstyrke}, m_reseptgruppe{reseptgruppe},
      m_legemiddelformkort{legemiddelformkort}, m_refvilkar{refvilkar}, m_preparattype{preparattype},
      m_typesoknadslv{typesoknadslv}, m_opioidsoknad{opioidsoknad}, m_svarttrekant{svarttrekant},
      m_refusjon{refusjon}, m_pakningbyttegruppe{pakningbyttegruppe}
    {
    }

    Cv Legemiddel::atc() const
    {
      return m_atc;
    }

    Name Legemiddel::navnformstyrke() const
    {
      return m_navnformstyrke;
    }

    Cs Legemiddel::reseptgruppe() const
    {
      return m_reseptgruppe;
    }

    Cv Legemiddel::legemiddelformkort() const
    {
      return m_legemiddelformkort;
    }

    Reference Legemiddel::refvilkar() const
    {
      return m_refvilkar;
    }

    Cs Legemiddel::preparattype() const
    {
      return m_preparattype;
    }

    Cs Legemiddel::typesoknadslv() const
    {
      return m_typesoknadslv;
    }

    bool Legemiddel::opioidsoknad() const
    {
      return m_opioidsoknad;
    }

    Cv Legemiddel::svarttrekant() const
    {
      return m_svarttrekant;
    }

    std::optional<Refusjon> Legemiddel::refusjon() const
    {
      if(m_refusjon.refrefusjonsgruppe().empty())
        return {};

      return m_refusjon;
    }

    std::optional<PakningByttegruppe> Legemiddel::pakningbyttegruppe() const
    {
      if(m_pakningbyttegruppe.refbyttegruppe().empty())
        return {};

      return m_pakningbyttegruppe;
    }

  } // namespace
} // namespace
