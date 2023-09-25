add_compile_definitions(BOOST_UUID_FORCE_AUTO_LINK)
add_compile_definitions(BOOST_AUTO_LINK_NOMANGLE)
find_package(Boost REQUIRED)
message("BOOST FOUND PATH ${Boost_INCLUDE_DIR}")

add_library(AUE_core STATIC main.cpp
        BaseWorld/point.cpp
        BaseWorld/point.h
        BaseModels/baseobject.h
        BaseModels/baseobject.cpp
        BaseWorld/worldmap.cpp
        BaseWorld/worldmap.h
        constatns.cpp
        constants.h
        EventLoop/eventloop.cpp
        EventLoop/eventloop.h
        BaseModels/Living/baseliving.cpp
        BaseModels/Living/baseliving.h
        BaseModels/Service/basemunicipal.cpp
        BaseModels/Service/basemunicipal.h
        helpers.cpp helpers.h
        BaseModels/Routes/baseroute.cpp
        BaseModels/Routes/baseroute.h
        types.cpp
        types.h
        BaseWorld/dummyobject.cpp
        BaseWorld/dummyobject.h
        Metrics/basemetric.cpp
        Metrics/basemetric.h
        core.cpp
        core.h
        BaseWorld/routesmap.cpp
        BaseWorld/routesmap.h
        BaseModels/baseregisters.cpp
        BaseModels/baseregisters.h
)
target_include_directories(AUE_core PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(AUE_core ${Boost_LIBRARIES})