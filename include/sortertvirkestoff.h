#ifndef SORTERTVIRKESTOFF_H_
#define SORTERTVIRKESTOFF_H_

#include <functional>
#include <utility>
#include <pugixml.hpp>
#include "container.h"
#include "get_container.h"
#include "get_value.h"
#include "idref.h"

namespace festlib
{
  namespace xml
  {

    // sorting of active ingredient.
    // sorts the order of the ingredient
    class SortertVirkestoff
    {
      public:
        SortertVirkestoff() = default;
        explicit SortertVirkestoff(int sortering,
            const IDREF& refvirkestoff);
        const auto& sortering() const { return m_sortering; };
        bool push_back(int sortering, const IDREF& refvirkestoff);
      private:
        // check if m_sortering already contains sortering value
        bool check_container(int sortering) const;
      private:
        // the pair contains sorting number of active ingredient,
        // starting with 0. Sorting as they are named in <NavnFormStyrke>.
        // the IDREF identifies/reference what active ingredient with strenght
        Container<std::pair<int, IDREF>> m_sortering{};
    };

    // non-member functions

    // Sorts the active ingridient after strength and reference to active ingridient
    xml::SortertVirkestoff get_sorteringvirkestoffmedstyrke(const pugi::xml_node& node);

    // Sorts the active ingridient without strength and reference to active ingridient
    xml::SortertVirkestoff get_sorteringvirkestoffutenstyrke(const pugi::xml_node& node);

  } // namespace
} // namespace

#endif
