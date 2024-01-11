#ifndef FESTLIB_H_
#define FESTLIB_H_

#include <string>
#include <string_view>
#include <pugixml.hpp>
#include "enkeltoppforing.h"
#include "legemiddel.h"
#include "cv.h"
#include "cs.h"

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

  namespace {

    using Value = std::string;
    using Date = std::string;

    // find different child types
    // CV = Coded Value
    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute);
    // CS = Coded Simple Value
    xml::Cs get_cs(const pugi::xml_node& node, std::string_view attribute);
    // get attribute value
    Value get_value(const pugi::xml_node& node, std::string_view attribute);

    // Enkeltoppforing contains if the entry is active, id and date.
    xml::Enkeltoppforing get_enkeltoppforing(const pugi::xml_node& node);
    // Legemiddel contains all shareable/common data about the drugs
    xml::Legemiddel get_legemiddel(const pugi::xml_node& node);

  } // namespace

  Date created_date(const Festlib& fest);


// give access to inline functions for testing purposes
#ifdef ENABLE_TESTING
  xml::Legemiddel test_get_legemiddel(const pugi::xml_node& node);
#endif 

} // namespace

#endif
