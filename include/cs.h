#ifndef CS_H_
#define CS_H_

#include <pugixml.hpp>
#include <string>
#include <string_view>

namespace festlib {
namespace xml {
// Coded Simple Value
// V and DN is manidatory values in the Fest xml file
class Cs {
public:
  Cs() = default;
  explicit Cs(std::string_view V, std::string_view DN);
  ~Cs() = default;
  Cs operator=(const Cs &other);
  const auto &value() const { return m_v; }
  const auto &long_value() const { return m_dn; }

private:
  std::string m_v{};
  std::string m_dn{};
};

// non-member functions

const bool operator==(const Cs &lhs, const Cs &rhs);
const bool operator==(const Cs &lhs, const char *str);

// CS (Coded Simple Value)
// Example:
//
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto node = node.get_node(); // gets the root.
//
// node =
// node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
// Cs preparattype = get_cs(node, "Preparattype");
xml::Cs get_cs(const pugi::xml_node &node, std::string_view attribute = "");

} // namespace xml
} // namespace festlib

#endif
