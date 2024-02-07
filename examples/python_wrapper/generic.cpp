#include <festlib/festlib.h>

#include <iostream>

extern "C" void print_generic() {
  festlib::Festlib fest{};

  try {
    fest.load_file("fest251.xml");
  } catch (const festlib::exceptions::FileNotFound& e) {
    std::cout << "error:" << e.what() << '\n';
  }

  const auto container{festlib::catalog_legemiddelpakning(fest)};
  const auto pakning{festlib::find_legemiddelpakning(container, "116772")};
  // const auto pakning{festlib::find_legemiddelpakning(container, "11222")};

  // find generic for itemnum 116772 Triatec Tab 10 mg 98 tablets
  const auto generic{festlib::generic_legemiddelpakning(container, pakning)};

  for (const auto& result : generic) {
    std::cout << result.varenr() << " " << result.varenavn() << '\n';
  }
}
