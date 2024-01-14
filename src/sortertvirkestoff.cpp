#include "sortertvirkestoff.h"
#include <functional>

namespace festlib
{
  namespace xml
  {
    SortertVirkestoff::SortertVirkestoff(
        int sortering, const IDREF& refvirkestoff)
    {
      m_sortering.push_back(std::pair{sortering, refvirkestoff});
    }

    Container<std::pair<int, IDREF>> SortertVirkestoff::sortering() const
    {
      return m_sortering;
    }

    bool SortertVirkestoff::push_back(int sortering, const IDREF& refvirkestoff)
    {
      if(!check_container(sortering)) {
        m_sortering.push_back(std::pair{sortering, refvirkestoff});
        return true;
      }
      return false;
    }

    bool SortertVirkestoff::check_container(int sortering) const
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
