cmake_minimum_required (VERSION 3.13)

project( zipsa_dq1_test )

set( CMAKE_CXX_FLAGS "-Wall -pthread" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

find_package( Threads )

include_directories (${CMAKE_SOURCE_DIR}/cpp/inc)

set( MAIN_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ServerSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClientSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Socket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Queue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CmdExecutor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mockup_server_main.cpp
)

add_executable( mockup_server ${MAIN_SOURCE_FILES} )
target_link_libraries( mockup_server ${CMAKE_THREAD_LIBS_INIT} )
#install( TARGETS mockup_server 
#    RUNTIME_DESTINATION ${CMAKE_SOURCE_DIR}/bin 
#    )
