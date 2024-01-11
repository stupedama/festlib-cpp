#ifndef ENKELTOPPFORING_H_
#define ENKELTOPPFORING_H_

#include <string>
#include <string_view>

namespace festlib
{
  namespace xml
  {

    // Enkeltoppforing = Entry.
    // All the entries of the xml file contains a "Enkeltoppforing".
    // Shows information if the entry is active, entry date and unique ID.
    class Enkeltoppforing
    {
      public:
        Enkeltoppforing(std::string_view id, std::string_view date, bool status);
        ~Enkeltoppforing() = default;
        const std::string& id() const;
        const std::string& date() const;
        bool status() const;
      private:
        std::string m_id{};
        std::string m_date{};
        bool m_status{};
    };

    bool operator==(const Enkeltoppforing& lhs, const Enkeltoppforing& rhs);
    bool operator==(const Enkeltoppforing& lhs, const char* str);

  } // namespace
} // namespace

#endif
