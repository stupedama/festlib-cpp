#ifndef PREPARATOMTALEAVSNITT_H_
#define PREPARATOMTALEAVSNITT_H_

#include "cs.h"
#include "lenke.h"

namespace festlib
{
  namespace xml
  {

    // contains data about SPC and link to SPC
    class Preparatomtaleavsnitt
    {
      public:
        Preparatomtaleavsnitt() = default;
        explicit Preparatomtaleavsnitt(const Cs& avsnittoverskrift,
            const Lenke& lenke);
        Cs avsnittoverskrift() const;
        Lenke lenke() const;
      private:
        Cs m_avsnittoverskrift{};
        Lenke m_lenke{};
    };

  } // namespace
} // namespace

#endif
