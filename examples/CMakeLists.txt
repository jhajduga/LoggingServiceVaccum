add_executable(LogSvcExample
    Main.cpp
    Pizza.cpp
    Physic.cpp
)

target_include_directories(LogSvcExample PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/externals
)

target_link_libraries(LogSvcExample PRIVATE LogSvc)
