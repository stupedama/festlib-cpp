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
        std::string id() const;
        std::string date() const;
        bool status() const;
      private:
        std::string m_id{};
        std::string m_date{};
        bool m_status{};
    };

    // non-member functions

    bool operator==(const Enkeltoppforing& lhs, const Enkeltoppforing& rhs);
    bool operator==(const Enkeltoppforing& lhs, const char* str);

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
