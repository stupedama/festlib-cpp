Festlib [![Github Releases](https://img.shields.io/github/release/stupedama/festlib.svg)](https://github.com/stupedama/festlib/releases/)[![Default build](https://github.com/stupedama/festlib/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/stupedama/festlib/actions/workflows/cmake-single-platform.yml)
=======

Festlib is a C++17 library for reading the Forskrivnings- og ekspedisjonsstøtte (FEST) xml file 
from The Norwegian Medical Products Agency (NOMA) (old Legemiddelverket/Norwegian Medicines Agency).

**Example find generic products**
```cpp
#include <festlib/festlib.h>
#include <iostream>

int main()
{
  festlib::Festlib fest{};
  const auto res{fest.load_file("fest251.xml")};

  const auto container{festlib::catalog_legemiddelpakning(fest)};

  // LegemiddelPakning class contains pakningbyttegruppe().refbyttegruppe()
  // find generic by <RefProduktByttegruppe>
  // container[0].pakningbyttegruppe().refbyttegruppe()
  const auto generic{festlib::generic_legemiddelpakning(container,
    "ID_E73943DE-753C-4A44-9959-2203FDAD4E53")};

  for (const auto& result : generic)
  {
    std::cout << result.varenr() << " " << result.varenavn() << '\n';
  }

  return 0;
}
```

**Example find generic products by item number**
```cpp
#include <festlib/festlib.h>
#include <iostream>

int main() {
  festlib::Festlib fest{};
  const auto res{fest.load_file("fest251.xml")};

  const auto container{festlib::catalog_legemiddelpakning(fest)};
  auto product_container{festlib::map_catalog_legemiddelpakning(fest)};

  // find generic for itemnum 116772 Triatec Tab 10 mg 98 tablets
  const auto generic{festlib::generic_legemiddelpakning(
      container, product_container["116772"])};

  for (const auto& result : generic) {
    std::cout << result.varenr() << " " << result.varenavn() << '\n';
  }

  return 0;
}                              
```

**Dependencies**
* [Pugixml 1.x](https://pugixml.org/)

**Optional dependencies**
* [Catch2 (for tests)](https://github.com/catchorg/Catch2)

## Build and install

1. Clone the repo
```sh
git clone git@github.com:stupedama/festlib.git
```
2. Create build dir
```sh
cd festlib && mkdir build && cd build
```
3. Build the project
```sh
cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
```
4. Install
```sh
make && sudo cmake --install .
```

## Read more about FEST and download
* For more [information about FEST](https://www.dmp.no/om-oss/distribusjon-av-legemiddeldata/fest)
* Website [for downloading FEST](https://www.dmp.no/om-oss/distribusjon-av-legemiddeldata/fest/nedlasting-av-fest-og-safest)

## More
* Issues and bugs can be raised on the [Issue tracker on Github](https://github.com/stupedama/festlib/issues)
* contact me [Fredrik Fjeldvær (fredrik@ffj.no)](mailto:fredrik@ffj.no).
