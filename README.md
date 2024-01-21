# festlib
A C++ library for reading the FEST xml file from Legemiddelverket (the Norwegian Medicines Agency)

## dependencies
* pugixml 1.x

### optional dependencies
* Catch2 (for tests)

## build and install
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

## usage
```c++
#include <festlib/festlib.h>
#include <iostream>

int main()
{
  festlib::Festlib fest{};
  auto res = fest.load_file("fest251.xml");

  if(res)
  {
    const auto container{catalog_legemiddelpakning(fest)};
    const auto generics{generic_legemiddelpakning(catalog_legemiddelpakning, 
    "ID_E73943DE-753C-4A44-9959-2203FDAD4E53")};

     for (const auto& res : generic) 
     {
       std::cout << res.varenr() << " " << res.varenavn() << '\n';
     }                                            
  }

  return 0;
}
```
