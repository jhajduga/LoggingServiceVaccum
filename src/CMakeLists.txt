add_library(LogSvc STATIC LogSvc.cpp)
target_include_directories(LogSvc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LogSvc PUBLIC loguru fmt)
