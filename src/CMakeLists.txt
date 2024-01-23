add_library(${PROJECT_NAME} SHARED
    festlib.cpp
    enkeltoppforing.cpp
    legemiddel.cpp
    administrering_legemiddel.cpp
    legemiddelmerkevare.cpp
    legemiddelpakning.cpp
    preparatomtaleavsnitt.cpp
    pakningbyttegruppe.cpp
    markedsforingsinfo.cpp
    sortertvirkestoff.cpp
    refusjon.cpp
    get_container.cpp
    produktinfo.cpp
    get_bool.cpp
    cv.cpp
    lenke.cpp
    produktinfo.cpp
    prisvare.cpp
    reseptgyldighet.cpp
    pakningskomponent.cpp
    pakningsinfo.cpp
    pq.cpp
    get_value.cpp
    cs.cpp)

set_target_properties(festlib PROPERTIES
                              VERSION ${PROJECT_VERSION}
                            SOVERSION ${PROJECT_VERSION_MAJOR})
