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
    const bool operator==(const Cv& lhs, const Cv& rhs)
    {
      return lhs.value() == rhs.value();
    }

    // compare V values
    const bool operator==(const Cv& lhs, const char* str)
    {
      const std::string compare_string{str};
      return compare_string.compare(lhs.value()) == 0;
    }

    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute)
    {
      pugi::xml_node child{node};

      if(attribute.length() > 0)
      {
        child = node.child(attribute.data());
      }

      const std::string v{child.attribute("V").value()};
      const std::string s{child.attribute("S").value()};
      const std::string dn{child.attribute("DN").value()};

      return xml::Cv{v, s, dn};
    }

  } // namespace
} // namespace
