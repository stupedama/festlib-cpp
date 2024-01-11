#ifndef CS_H_
#define CS_H_

#include <string>
#include <string_view>

namespace festlib
{
  namespace xml
  {
    // Coded Simple Value
    // V and DN is manidatory values in the Fest xml file
    class Cs
    {
      public:
        Cs() = default;
        explicit Cs(std::string_view V, std::string_view DN);
        ~Cs() = default;
        Cs operator=(const Cs& other);
        const std::string& value() const;
        const std::string& long_value() const;
      private:
        std::string m_v{};
        std::string m_dn{};
    };

    bool operator==(const Cs& lhs, const Cs& rhs);
    bool operator==(const Cs& lhs, const char* str);
  } // namespace
} // namespace

#endif
