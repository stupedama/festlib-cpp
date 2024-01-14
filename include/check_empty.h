#ifndef CHECK_EMPTY_H_
#define CHECK_EMPTY_H_

#include <optional>
#include <string>
#include "container.h"

namespace festlib
{

  template<typename T>
  std::optional<T> check_empty(const T& value)
  {
    if(value.long_value().empty())
      return {};

    return value;
  }

  template<typename T>
  std::optional<Container<T>> check_empty(const Container<T>& value)
  {
    if(value.empty())
      return {};

    return value;
  }

  template<typename T = std::string>
  std::optional<std::string> check_empty(const std::string& str)
  {
    if(str.empty())
      return {};

    return str;
  }

} // namespace

#endif
