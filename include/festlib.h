#ifndef FESTLIB_H_
#define FESTLIB_H_

// Main class that handles the reading of the XML file or string.
// after loading the source, it contains a pugi::xml_node and the pugi::xml_document.
// non-member functions is used to get the data.
//
// Example: get the HentetDato (Fest XML update date):
// Festlib fest{};
// bool load = fest.load_file(filename);
// auto date = fest.created_date(fest);

#include <string_view>
#include <pugixml.hpp>
#include "container.h"
#include "get_category.h"
#include "get_value.h"
#include "legemiddelmerkevare.h"
#include "date.h"

namespace festlib {

  class Festlib
  {
    public:
      Festlib();
      ~Festlib() = default;
      bool load_file(std::string_view filename);
      bool load_string(std::string_view xml_string);
      pugi::xml_node get_node() const;
    private:
      pugi::xml_document m_doc{};
      pugi::xml_parse_result m_parse_result{};
      bool m_result{false};
  };

  // library interface

  // return the <FEST><HentetDato>Timestamp</HentetDato></FEST>
  Date created_date(const Festlib& fest);

  // return the catalog <KatLegemiddelMerkevare>
  Container<xml::LegemiddelMerkevare> catalog_legemiddelmerkevare(const Festlib& fest);

} // namespace

#endif
