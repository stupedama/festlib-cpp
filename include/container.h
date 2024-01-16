#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <vector>

namespace festlib
{
  // default container used

  template<typename T>
  using Container = std::vector<T>;

} // namespace

#endif
