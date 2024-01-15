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

#include <functional>
#include <string>
#include <string_view>
#include <pugixml.hpp>
#include "administrering_legemiddel.h"
#include "date.h"
#include "container.h"
#include "cv.h"
#include "cs.h"
#include "enkeltoppforing.h"
#include "idref.h"
#include "legemiddel.h"
#include "preparatomtaleavsnitt.h"
#include "refusjon.h"
#include "lenke.h"
#include "pakningbyttegruppe.h"
#include "produktinfo.h"
#include "reseptgyldighet.h"
#include "sortertvirkestoff.h"
#include "legemiddelmerkevare.h"

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

    // CS (Coded Simple Value)
    // Example:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // node = node.child("KatLegemiddelMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Cs preparattype = get_cs(node, "Preparattype");
    xml::Cs get_cs(const pugi::xml_node& node, std::string_view attribute = "");

    // Get a simple attribute value.
    // Example <HentetDato>TimeStamp</HentetDato>:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node(); // gets the root.
    //
    // Value date = get_value(node, "HentetDato");
    Value get_value(const pugi::xml_node& node, std::string_view attribute = "");

    // Iterates over a attribute that contains one or more values
    // template<typename T>
    template<typename T>
    Container<T> get_container(const pugi::xml_node& node, std::string_view attribute, std::function<T(const pugi::xml_node& node)> func)
    {
      Container<T> node_container = Container<T>{};

      for(const auto& child_node : node)
      {
        if(attribute.compare(child_node.name()) == 0)
        {
          node_container.push_back(func(child_node));
        }
      }

      return node_container;
    }

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

    // Refusjon = Refund. Contains reference to refundgroup and periode the refund is valid
    // Example:
    //
    // Festlib fest{};
    // bool load = fest.load_file(filename);
    // auto node = node.get_node();
    //
    // node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
    // Refusjon refusjon = get_refusjon(node);
    xml::Refusjon get_refusjon(const pugi::xml_node& node);


    // Contains SPC and url to SPC.
    // Example:
    //
    // node = node.child("KatLegemiddeMerkevare").child("OppfLegemiddelMerkevare").child("LegemiddelMerkevare");
    // Preparatomtaleavsnitt avsnitt = get_preparatomtaleavsnitt(node);
    xml::Preparatomtaleavsnitt get_preparatomtaleavsnitt(const pugi::xml_node& node);

    // Lenke = URL
    // Example:
    //
    // node = node.child("KatLegemiddelpakning").child("OppfLegemiddelpakning").child("Legemiddelpakning");
    // Lenke www = get_lenke(node);
    xml::Lenke get_lenke(const pugi::xml_node& node);

    // AdministreringLegemiddel
    // only used in class LegemiddelMerkevare and LegemiddelVirkestoff
    // contains information about administration of the drug
    // for example: precautions for intake, usage/indication on pharmacy label.
    xml::AdministreringLegemiddel get_administreringlegemiddel(const pugi::xml_node& node);

    // PakningByttegruppe identifies what generic group it is.
    // RefByttegruppe ID is a link to other generics
    xml::PakningByttegruppe get_pakningbyttegruppe(const pugi::xml_node& node);

    // ProductInfo.
    // Contains information about marketing authorization and
    // name of producer.
    xml::ProduktInfo get_produktinfo(const pugi::xml_node& node);

    // Prescription duration
    // defines the duration of the prescription
    xml::Reseptgyldighet get_reseptgyldighet(const pugi::xml_node& node);

    // Sorts the active ingridient after strength and reference to active ingridient
    xml::SortertVirkestoff get_sorteringvirkestoffmedstyrke(const pugi::xml_node& node);

    // Sorts the active ingridient without strength and reference to active ingridient
    xml::SortertVirkestoff get_sorteringvirkestoffutenstyrke(const pugi::xml_node& node);

    // LegemiddelMerkevare is a top entry of the category KatLegemiddelMerkevare.
    // contains information about name of product, taste, formulation etc.
    xml::LegemiddelMerkevare get_legemiddelmerkevare(const pugi::xml_node& node);

  } // namespace

  // library interface

  // Return the <FEST><HentetDato>Timestamp</HentetDato></FEST>
  Date created_date(const Festlib& fest);

// give access to inline functions for testing purposes
#ifdef ENABLE_TESTING

  xml::Cs test_get_cs(const pugi::xml_node& node, std::string_view attribute = "");
  xml::Cv test_get_cv(const pugi::xml_node& node, std::string_view attribute = "");
  xml::Legemiddel test_get_legemiddel(const pugi::xml_node& node);
  xml::Refusjon test_get_refusjon(const pugi::xml_node& node);
  xml::Preparatomtaleavsnitt test_get_preparatomtaleavsnitt(const pugi::xml_node& node);
  xml::Lenke test_get_lenke(const pugi::xml_node& node);
  xml::AdministreringLegemiddel test_get_administreringlegemiddel(const pugi::xml_node& node);
  xml::PakningByttegruppe test_get_pakningbyttegruppe(const pugi::xml_node& node);
  xml::ProduktInfo test_get_produktinfo(const pugi::xml_node& node);
  xml::Reseptgyldighet test_get_reseptgyldighet(const pugi::xml_node& node);
  xml::SortertVirkestoff test_get_sorteringvirkestoffmedstyrke(const pugi::xml_node& node);
  xml::SortertVirkestoff test_get_sorteringvirkestoffutenstyrke(const pugi::xml_node& node);
  xml::LegemiddelMerkevare test_get_legemiddelmerkevare(const pugi::xml_node& node);

  template<typename T>
  Container<T> test_get_container(const pugi::xml_node& node, std::string_view attribute, std::function<T(const pugi::xml_node& n)> func)
  {
    return get_container(node, attribute, func);
  }

#endif

} // namespace

#endif
