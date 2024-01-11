#include "cv.h"

// Coded Value
// V, S and DN is manidatory values in the Xml fest file

namespace festlib
{
  namespace xml
  {

    Cv::Cv(std::string_view V, std::string_view S, std::string_view DN)
      : m_v{V}, m_s{S}, m_dn{DN}
    {
    }

    const std::string& Cv::value() const
    {
      return m_v;
    }

    const std::string& Cv::long_value() const
    {
      return m_dn;
    }

    Cv Cv::operator=(const Cv& other)
    {
      if(this == &other)
        return *this;

      m_dn = other.m_dn;
      m_s = other.m_s;
      m_v = other.m_v;

      return *this;
    }

    // no--member functions

    // compare the V values
    bool operator==(const Cv& lhs, const Cv& rhs)
    {
      return lhs.value() == rhs.value();
    }

    // compare V values
    bool operator==(const Cv& lhs, const char* str)
    {
      std::string compare_string{str};
      return compare_string.compare(lhs.value()) == 0;
    }

  } // namespace
} // namespace
