#ifndef PAKNINGSKOMPONENT_H_
#define PAKNINGSKOMPONENT_H_

#include <string>
#include <pugixml.hpp>
#include "container.h"
#include "get_container.h"
#include "cv.h"
#include "get_value.h"
#include "pq.h"

namespace festlib
{
  namespace xml
  {

    // information about each component
    // when there is two or more components 
    // that is mixed together.
    // example: liquid and powder
    class Pakningskomponent
    {
      public:
        Pakningskomponent() = default;
        explicit Pakningskomponent(const Cv& pakningstype,
            const Pq& mengde, int antall);
        ~Pakningskomponent() = default;
      private:
        // same as attribute in packagetype
        // <KodeVerk> 7449
        Cv m_pakningstype{};
        // same as attribute in PakningsInformasjon
        // <KodeVerk> 7452
        Pq m_mengde{};
        // same as attribute in PakningsInformasjon
        int m_antall{1};
    };

    namespace {

      // used in get_container().
      xml::Pakningskomponent get_one_pakningskomponent(const pugi::xml_node& node);

    } // namespace

    // non-member functions

    Container<xml::Pakningskomponent> get_pakningskomponent(const pugi::xml_node& node);

  } // namespace
} // namespace

#endif
