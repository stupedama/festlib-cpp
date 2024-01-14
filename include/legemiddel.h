#ifndef LEGEMIDDEL_H_
#define LEGEMIDDEL_H_

#include <optional>
#include <string>
#include <string_view>
#include "check_empty.h"
#include "cv.h"
#include "cs.h"
#include "pakningbyttegruppe.h"
#include "refusjon.h"

namespace festlib
{
  namespace xml
  {
    using Name = std::string;
    using Reference = std::string;

    // Legemiddel = Drug.
    // Contains drug information.
    // Is used as a component by classes:
    // - Legemiddeldose (Drug dosage)
    // - Legemiddelvirkestoff (Drug active ingredient)
    // - Legemiddelmerkevare
    // - Legemiddelpakningmerkevare
    class Legemiddel
    {

      public:
        Legemiddel() = default;
        explicit Legemiddel(const Cv& atc, const Name& navnformstyrke, 
            const Cs& reseptgruppe, const Cv& legemiddelformkort, 
            const Reference& refvilkar, const Cs& preparattype,
            const Cs& typesoknadslv, bool opioidsoknad, 
            const Cv& svarttrekant, const Refusjon& refusjon,
            const PakningByttegruppe& pakningbyttegruppe);
        ~Legemiddel() = default;

        // getters
        Cv atc() const;
        Name navnformstyrke() const;
        Cs reseptgruppe() const;
        Cv legemiddelformkort() const;
        Reference refvilkar() const;
        Cs preparattype() const;
        Cs typesoknadslv() const;
        bool opioidsoknad() const;
        Cv svarttrekant() const;
        std::optional<Refusjon> refusjon() const;
        std::optional<PakningByttegruppe> pakningbyttegruppe() const;
      private:
        // named as they are in the xml file, only all lowercase.
        Cv m_atc{};
        Name m_navnformstyrke{};
        Cs m_reseptgruppe{};
        Cv m_legemiddelformkort{};
        Reference m_refvilkar{};
        Cs m_preparattype{};
        Cs m_typesoknadslv{};
        bool m_opioidsoknad{};
        Cv m_svarttrekant{};
        Refusjon m_refusjon{};
        PakningByttegruppe m_pakningbyttegruppe{};
    };

  } // namespace
} // namespace

#endif
