include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(client_SRCS
    main.cpp
    proxy.cpp
)
qt5_add_resources(client_SRCS
    qml.qrc
)

add_executable(client ${client_SRCS})
target_link_libraries(client
LINK_PUBLIC
    Qt5::Core
    Qt5::Gui
    Qt5::Quick
)
install(TARGETS client DESTINATION usr/bin)
