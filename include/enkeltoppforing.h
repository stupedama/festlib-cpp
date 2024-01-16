#ifndef ENKELTOPPFORING_H_
#define ENKELTOPPFORING_H_

#include <string>
#include <string_view>
#include <pugixml.hpp>
#include "get_value.h"

namespace festlib
{
  namespace xml
  {

    // Enkeltoppforing = Entry.
    // All the entries of the xml file contains a "Enkeltoppforing".
    // Shows information if the entry is active, entry date and unique ID.
    class Enkeltoppforing
    {
      public:
        Enkeltoppforing() = default;
        explicit Enkeltoppforing(std::string_view id, std::string_view date, bool status);
        ~Enkeltoppforing() = default;
        const auto& id() const { return m_id; }
        const auto& date() const { return m_date; }
        bool status() const;
      private:
        std::string m_id{};
        std::string m_date{};
        bool m_status{};
    };

    // non-member functions

    const bool operator==(const Enkeltoppforing& lhs, const Enkeltoppforing& rhs);
    const bool operator==(const Enkeltoppforing& lhs, const char* str);

    // Enkeltoppforing = Entry.
    // Example:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare");
    // auto entry = get_enkeltoppforing(node);
    xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node& node);

  } // namespace
} // namespace

#endif
