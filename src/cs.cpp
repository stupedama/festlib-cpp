#include "cs.h"

// CS = Coded Simple Value.
// V and DN is manidatory values in the Xml fest file

namespace festlib
{
  namespace xml
  {

    Cs::Cs(std::string_view V, std::string_view DN)
      : m_v{V}, m_dn{DN}
    {
    }

    Cs Cs::operator=(const Cs& other)
    {
      if(this == &other)
        return *this;

      m_dn = other.m_dn;
      m_v = other.m_v;

      return *this;
    }

    const std::string& Cs::value() const
    {
      return m_v;
    }

    const std::string& Cs::long_value() const
    {
      return m_dn;
    }

    // no--member functions

    // compare the V attributes
    bool operator==(const Cs& lhs, const Cs& rhs)
    {
      return lhs.value() == rhs.value();
    }

    // compare the V attributes
    bool operator==(const Cs& lhs, const char* str)
    {
      std::string compare_string{str};
      return compare_string.compare(lhs.value()) == 0;
    }

  } // namespace
} // namespace
