## What is Festlib?

Festlib is a C++17 library for reading the Forskrivnings- og ekspedisjonsstøtte (FEST) xml file 
from The Norwegian Medical Products Agency (NOMA) (old Legemiddelverket/Norwegian Medicines Agency).

**Example read generic product**
```cpp
#include <festlib/festlib.h>
#include <iostream>

int main()
{
  festlib::Festlib fest{};
  const auto res{fest.load_file("fest251.xml")};

  if(res) {
    const auto container{festlib::catalog_legemiddelpakning(fest)};
    const auto generic{festlib::generic_legemiddelpakning(container,
      "ID_E73943DE-753C-4A44-9959-2203FDAD4E53")};

    for (const auto& result : generic)
    {
      std::cout << result.varenr() << " " << result.varenavn() << '\n';
    }
  }

  return 0;
}
```

**Dependencies**
* pugixml 1.x

**Optional dependencies**
* Catch2 (for tests)

## Build and install

1. clone the repo
```sh
git clone git@github.com:stupedama/festlib.git
```
2. create build dir
```sh
cd festlib && mkdir build && cd build
```
3. build the project
```sh
cmake ../ -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
```
4. install
```sh
make && sudo cmake --install .
```

## More
* Issues and bugs can be raised on the [Issue tracker on Github](https://github.com/stupedama/festlib/issues)
* contact me [Fredrik Fjeldvær (fredrik@ffj.no)](mailto:fredrik@ffj.no).
