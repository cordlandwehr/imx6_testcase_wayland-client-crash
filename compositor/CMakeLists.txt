include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${CARE_INCLUDE_DIRS}
)

set(compositor_SRCS
    main.cpp
)
qt5_add_resources(compositor_SRCS
    qml.qrc
)

add_executable(compositor ${compositor_SRCS})
target_link_libraries(compositor
LINK_PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::WaylandCompositor
)
install(TARGETS compositor DESTINATION usr/bin)
