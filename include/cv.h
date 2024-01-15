#ifndef CV_H_
#define CV_H_

#include <string>
#include <string_view>
#include <pugixml.hpp>

namespace festlib
{
  namespace xml
  {
    // Coded Value
    // V, S and DN is manidatory values in the Xml fest file
    class Cv
    {
      public:
        Cv() = default;
        explicit Cv(std::string_view V, std::string_view S, std::string_view DN);
        ~Cv() = default;
        Cv operator=(const Cv& other);
        const std::string& value() const;
        const std::string& long_value() const;
      private:
        std::string m_v{};
        std::string m_s{};
        std::string m_dn{};
    };

    // non-member functions

    bool operator==(const Cv& lhs, const Cv& rhs);
    bool operator==(const Cv& lhs, const char* str);

    // CV (Coded Value) from node
    // Example:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Cv atc = get_cv(node, "Atc");
    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute = "");

  } // namespace
} // namespace

#endif
