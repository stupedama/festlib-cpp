#include "enkeltoppforing.h"

namespace festlib
{
  namespace xml
  {

    Enkeltoppforing::Enkeltoppforing(std::string_view id, std::string_view date, bool status)
      : m_id{id}, m_date{date}, m_status{status}
    {
    }

    std::string Enkeltoppforing::id() const
    {
      return m_id; // unique ID.
    }

    std::string Enkeltoppforing::date() const
    {
      return m_date;
    }

    bool Enkeltoppforing::status() const
    {
      return m_status;
    }

    // no--member functions

    // Enkeltoppforing contains a unique ID.
    bool operator==(const Enkeltoppforing& lhs, const Enkeltoppforing& rhs)
    {
      return lhs.id() == rhs.id();
    }

    // Enkeltoppforing contains a unique ID.
    bool operator==(const Enkeltoppforing& lhs, const char* str)
    {
      std::string compare_string{str};
      return compare_string.compare(lhs.id()) == 0;
    }
    
    xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node& node)
    {
      std::string id{get_value(node, "Id")};
      std::string date{get_value(node, "Tidspunkt")}; // Tidspunkt = Entry date
      std::string status{node.child("Status").first_attribute().value()};

      bool oppforing_status{false};

      if(status.compare("A") == 0)
        oppforing_status = true;

      return xml::Enkeltoppforing{id, date, oppforing_status};
    }

  } // namespace
} // namespace
