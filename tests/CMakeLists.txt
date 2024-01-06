find_package(Catch2 3 REQUIRED)

add_executable(
    festlib_unit_tests
    ${PROJECT_SOURCE_DIR}/tests/festlib.cpp
)

target_link_libraries(festlib_unit_tests PRIVATE Catch2::Catch2WithMain festlib)

target_compile_features(festlib_unit_tests PRIVATE cxx_std_17)

add_test(NAME festlib-unit-tests COMMAND $<TARGET_FILE:festlib_unit_tests>)
