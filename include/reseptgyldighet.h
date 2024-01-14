#ifndef RESEPTGYLDIGHET_H_
#define RESEPTGYLDIGHET_H_

#include <optional>
#include <string>
#include <string_view>
#include "check_empty.h"
#include "cs.h"

namespace festlib 
{
  namespace xml
  {
    
    // Defines the duration fo the prescription
    class Reseptgyldighet
    {
      public:
        Reseptgyldighet() = default;
        Reseptgyldighet(const Cs& kjonn, std::string_view varighet);
        std::optional<Cs> kjonn() const;
        std::string varighet() const;
      private:
        // gender defines the gender for the duration
        // <KodeVerk> 3101
        Cs m_kjonn{};
        // duration of the prescription
        // <KodeVerk> 3101
        std::string m_varighet{};
    };

  } // namespace
} // namespace

#endif
