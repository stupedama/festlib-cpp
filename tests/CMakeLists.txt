find_package(Catch2 3 REQUIRED)
find_package(pugixml CONFIG REQUIRED)

add_executable(
    festlib_unit_tests
    ${PROJECT_SOURCE_DIR}/tests/festlib.cpp
    cv.cpp
    cs.cpp
    pq.cpp
    pakningskomponent.cpp
    xml.cpp
    enkeltoppforing.cpp
    legemiddel.cpp
    refusjon.cpp
    get_container.cpp
    administrering_legemiddel.cpp
    preparatomtaleavsnitt.cpp
    pakningbyttegruppe.cpp
    produktinfo.cpp
    reseptgyldighet.cpp
    sortertvirkestoffmedstyrke.cpp
    sortertvirkestoffutenstyrke.cpp
    lenke.cpp
    legemiddelmerkevare.cpp
)

target_link_libraries(festlib_unit_tests PRIVATE Catch2::Catch2WithMain festlib pugixml)

target_compile_features(festlib_unit_tests PRIVATE cxx_std_17)

add_test(NAME festlib-unit-tests COMMAND $<TARGET_FILE:festlib_unit_tests>)

include(CTest)
include(Catch)
catch_discover_tests(festlib_unit_tests)
