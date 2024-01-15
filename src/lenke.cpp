#include "lenke.h"

namespace festlib
{
  namespace xml
  {

    xml::Lenke get_lenke(const pugi::xml_node& node)
    {
      const pugi::xml_node lenke_node{node.child("Lenke").child("Www")};
      return lenke_node.attribute("V").value();
    }

  } // namespace
} // namespace
