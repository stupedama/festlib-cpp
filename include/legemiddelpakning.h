#ifndef LEGEMIDDELPAKNING_H_
#define LEGEMIDDELPAKNING_H_

#include "legemiddel.h"
#include "pakningsinfo.h"

namespace festlib {
namespace xml {

class Legemiddelpakning {
public:
  Legemiddelpakning() = default;
  ~Legemiddelpakning() = default;

private:
  Legemiddel m_legemiddel{};
  Pakningsinfo m_pakningsinfo{};
};

} // namespace xml
} // namespace festlib

#endif
