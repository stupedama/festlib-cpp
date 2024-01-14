#include "preparatomtaleavsnitt.h"

namespace festlib
{
  namespace xml
  {

    Preparatomtaleavsnitt::Preparatomtaleavsnitt(const Cs& avsnittoverskrift,
            const Lenke& lenke)
      : m_avsnittoverskrift{avsnittoverskrift},
      m_lenke{lenke}
    {
    }

    Cs Preparatomtaleavsnitt::avsnittoverskrift() const
    {
      return m_avsnittoverskrift;
    }

    Lenke Preparatomtaleavsnitt::lenke() const
    {
      return m_lenke;
    }

  } // namespace
} // namespace

