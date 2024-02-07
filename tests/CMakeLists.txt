find_package(pugixml CONFIG REQUIRED)

if(ENABLE_TESTING)
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)
endif()

add_executable(
    festlib_unit_tests
    ${PROJECT_SOURCE_DIR}/tests/festlib.cpp
    cv.cpp
    cs.cpp
    pq.cpp
    pakningskomponent.cpp
    enkeltoppforing.cpp
    legemiddel.cpp
    refusjon.cpp
    get_container.cpp
    administrering_legemiddel.cpp
    preparatomtaleavsnitt.cpp
    pakningbyttegruppe.cpp
    produktinfo.cpp
    pakningsinfo.cpp
    prisvare.cpp
    markedsforingsinfo.cpp
    reseptgyldighet.cpp
    sortertvirkestoffmedstyrke.cpp
    sortertvirkestoffutenstyrke.cpp
    lenke.cpp
    legemiddelmerkevare.cpp
    legemiddelpakning.cpp
    generic_legemiddelpakning.cpp
    xml.cpp
)

target_link_libraries(festlib_unit_tests PRIVATE Catch2::Catch2WithMain festlib pugixml)

target_compile_features(festlib_unit_tests PRIVATE cxx_std_17)

add_test(NAME festlib-unit-tests COMMAND $<TARGET_FILE:festlib_unit_tests>)

include(CTest)
include(Catch)
catch_discover_tests(festlib_unit_tests)

