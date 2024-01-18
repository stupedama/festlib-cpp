#include "markedsforingsinfo.h"

namespace festlib {
namespace xml {

Markedsforingsinfo::Markedsforingsinfo(std::string_view varenrutgaende,
                                       const Date &markedsforingsdato,
                                       const Date &avregdato,
                                       const Date &midlutgattdato,
                                       std::string_view ompakkeravendose)
    : m_varenrutgaende{varenrutgaende},
      m_markedsforingsdato{markedsforingsdato}, m_avregdato{avregdato},
      m_midlutgattdato{midlutgattdato}, m_ompakkeravendose{ompakkeravendose} {}

// non-member functions

xml::Markedsforingsinfo get_markedsforingsinfo(const pugi::xml_node &node) {
  const pugi::xml_node child{node.child("Markedsforingsinfo")};

  const std::string varenrutgaende{get_value(child, "VarenrUtgaende")};
  const Date markedsforingsdato{get_value(child, "Markedsforingsdato")};
  const Date avregdato{get_value(child, "AvregDato")};
  const Date midlutgattdato{get_value(child, "MidlUtgattDato")};
  const std::string ompakkeravendose{get_value(child, "OmpakkerAvEndose")};

  return xml::Markedsforingsinfo{varenrutgaende, markedsforingsdato, avregdato,
                                 midlutgattdato, ompakkeravendose};
}

} // namespace xml
} // namespace festlib
