#ifndef PREPARATOMTALEAVSNITT_H_
#define PREPARATOMTALEAVSNITT_H_

#include <pugixml.hpp>
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

    // non-member functions

    // Contains SPC and url to SPC.
    // Example:
    //
    // node = node.child("KatLegemiddeMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Preparatomtaleavsnitt avsnitt = get_preparatomtaleavsnitt(node);
    xml::Preparatomtaleavsnitt get_preparatomtaleavsnitt(const pugi::xml_node& node);

  } // namespace
} // namespace

#endif
