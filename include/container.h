#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <unordered_map>
#include <vector>

namespace festlib {
// default container used

template <typename T> using Container = std::vector<T>;
template <typename T, typename U> using Set = std::unordered_map<T, U>;

} // namespace festlib

#endif
