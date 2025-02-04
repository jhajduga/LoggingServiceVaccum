#----------------------------------------------------------------------------
# Library setup for LogSvc
add_library(LogSvc STATIC LogSvc.cpp ${EXTERNALS_DIR}/loguru.cpp)

# Include directories
target_include_directories(LogSvc PUBLIC ${INCLUDE_DIR} ${EXTERNALS_DIR})

# Link libraries
find_package(fmt REQUIRED)
target_link_libraries(LogSvc PUBLIC fmt::fmt pthread dl)