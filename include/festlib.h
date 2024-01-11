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

    // CV (Coded Value) from node
    // Example: 
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Cv atc = get_cv(node, "Atc");
    xml::Cv get_cv(const pugi::xml_node& node, std::string_view attribute);


    // CS (Coded Simple Value)
    // Example: 
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Cs preparattype = get_cs(node, "Preparattype");
    xml::Cs get_cs(const pugi::xml_node& node, std::string_view attribute);

    // Get a simple attribute value.
    // Example <HentetDato>TimeStamp</HentetDato>:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // Value date = get_value(node, "HentetDato");
    Value get_value(const pugi::xml_node& node, std::string_view attribute);

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

    // Legemiddel = Drug. Contains ATC, formulation, name and more
    // Example:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Legemiddel lm = get_legemiddel(node);
    xml::Legemiddel get_legemiddel(const pugi::xml_node& node);

  } // namespace

  // library interface

  // Return the <FEST><HentetDato>Timestamp</HentetDato></FEST>
  Date created_date(const Festlib& fest);


// give access to inline functions for testing purposes
#ifdef ENABLE_TESTING
  xml::Legemiddel test_get_legemiddel(const pugi::xml_node& node);
#endif

} // namespace

#endif
