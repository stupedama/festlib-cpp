#include "pakningskomponent.h"
#include "get_container.h"

namespace festlib
{
  namespace xml
  {

    Pakningskomponent::Pakningskomponent(
        const Cv& pakningstype,
        const Pq& mengde, int antall)
      :
        m_pakningstype{pakningstype},
      m_mengde{mengde}, m_antall{antall}
    {
    }

    namespace {

      xml::Pakningskomponent get_one_pakningskomponent(const pugi::xml_node& node)
      {
        //const pugi::xml_node child = node.child("Pakningskomponent");

        const Cv pakningstype{get_cv(node, "Pakningstype")};
        const Pq mengde{get_pq(node, "Mengde")};

        const std::string antall_str{get_value(node, "Mengde")};
        const int antall{std::stoi(antall_str)};

        return xml::Pakningskomponent{pakningstype, mengde, antall};
      }

    } // namespace

    // non-member functions

    Container<Pakningskomponent> get_pakningskomponent(const pugi::xml_node& node)
    {
      return get_container<Pakningskomponent>(node, "Pakningskomponent", [](const pugi::xml_node& n)
          {
            return get_one_pakningskomponent(n);
          });
    }

  } // namespace
} // namespace
