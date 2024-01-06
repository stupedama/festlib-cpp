#ifndef FESTLIB_H_
#define FESTLIB_H_

#include <string>
#include <string_view>

namespace festlib {
  class Festlib
  {
    public:
      Festlib(std::string_view filename);
    private:
      std::string filename;
  };
} // namespace

#endif
