#include "sortertvirkestoffmedstyrke.h"
#include <functional>

namespace festlib
{
  namespace xml
  {
    SortertVirkestoffMedStyrke::SortertVirkestoffMedStyrke(
        int sortering, const IDREF& refvirkestoffmedstyrke)
    {
      m_sortering.push_back(std::pair{sortering, refvirkestoffmedstyrke});
    }

    Container<std::pair<int, IDREF>> SortertVirkestoffMedStyrke::sortering() const
    {
      return m_sortering;
    }

    bool SortertVirkestoffMedStyrke::push_back(int sortering, const IDREF& refvirkestoffmedstyrke)
    {
      if(!check_container(sortering)) {
        m_sortering.push_back(std::pair{sortering, refvirkestoffmedstyrke});
        return true;
      }
      return false;
    }

    bool SortertVirkestoffMedStyrke::check_container(int sortering) const
    {
      for(const auto& value : m_sortering)
      {
        if(value.first == sortering)
          return true;
      }
      return false;
    }

  } // namespace
} // namespace
