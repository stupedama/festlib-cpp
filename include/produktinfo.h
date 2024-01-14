#ifndef PRODUKTINFO_H_
#define PRODUKTINFO_H_

#include <optional>
#include <string>
#include "cv.h"
#include "check_empty.h"

namespace festlib
{
  namespace xml
  {

    class ProduktInfo
    {
      public:
        ProduktInfo() = default;
        explicit ProduktInfo(bool varseltrekant, std::string_view referanseprodukt,
            const Cv& vaksinestandard, std::string_view produsent);
        std::optional<bool> varseltrekant() const;
        std::optional<std::string> referanseprodukt() const;
        std::optional<Cv> vaksinestandard() const;
        std::optional<std::string> produsent() const;
      private:
        // identifies if theres a warning triangle
        // on the package
        bool m_varseltrekant{false};
        // defines the tradename of a other product that
        // is generic to this product
        std::string m_referanseprodukt{};
        // identifies vacinestandard for those drugs
        // that is vacines.
        // follow NLS
        // <KodeVerk> 7447
        Cv m_vaksinestandard{};
        // contains the name of the marketting authorization
        // if theres not no marketting authorization, the producer
        // like hospital pharmacy that is listed
        std::string m_produsent;
    };

  } // namespace
} // namespace

#endif
