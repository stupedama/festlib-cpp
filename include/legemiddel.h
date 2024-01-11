#ifndef LEGEMIDDEL_H_
#define LEGEMIDDEL_H_

#include <string>
#include <string_view>
#include "cv.h"
#include "cs.h"

namespace festlib
{
  namespace xml
  {

    // Class that is included in all Medicines categories, like KatLegemiddelMerkevare and KatLegemiddelpakning.
    // all categories that contains data about drugs contains this class.
    class Legemiddel
    {
      using Name = std::string;
      using Reference = std::string;

      public:
        Legemiddel() = default;
        explicit Legemiddel(Cv atc, Name navnformstyrke, Cs reseptgruppe,
            Cv legemiddelformkort, Reference refvilkar, Cs preparattype,
            Cs typesoknadslv, bool opioidsoknad, Cv svarttrekant);
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
    };

  } // namespace
} // namespace

#endif
