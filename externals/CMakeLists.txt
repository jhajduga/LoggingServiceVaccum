add_library(loguru STATIC loguru.cpp)
target_include_directories(loguru PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(loguru PUBLIC LOGURU_USE_FMTLIB=1) # <--- dodaj to!
target_link_libraries(loguru PUBLIC pthread dl fmt) # <-- fmt również tutaj!
