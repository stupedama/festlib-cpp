#include "legemiddel.h"

namespace festlib
{
  namespace xml
  {

    using Name = std::string;
    using Reference = std::string;

    Legemiddel::Legemiddel(Cv atc, Name navnformstyrke, Cs reseptgruppe,
        Cv legemiddelformkort, Reference refvilkar, Cs preparattype,
        Cs typesoknadslv, bool opioidsoknad, Cv svarttrekant)
      : m_atc{atc}, m_navnformstyrke{navnformstyrke}, m_reseptgruppe{reseptgruppe},
      m_legemiddelformkort{legemiddelformkort}, m_refvilkar{refvilkar}, m_preparattype{preparattype},
      m_typesoknadslv{typesoknadslv}, m_opioidsoknad{opioidsoknad}, m_svarttrekant{svarttrekant}
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

  } // namespace
} // namespace
