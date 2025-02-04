#----------------------------------------------------------------------------
# Add example executable
add_executable(example_app main.cpp physic.cpp simulation.cpp)

# Include directories
target_include_directories(example_app PRIVATE ${INCLUDE_DIR} ${EXTERNALS_DIR})

# Link libraries
target_link_libraries(example_app PRIVATE LogSvc pthread dl)

# Ensure loguru uses FMT
target_compile_definitions(example_app PRIVATE LOGURU_USE_FMTLIB=1)
