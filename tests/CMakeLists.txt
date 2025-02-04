#----------------------------------------------------------------------------
# Add test executable
add_executable(test_app main_test.cpp)

# Link the LogSvc library
target_link_libraries(test_app PRIVATE LogSvc)

# Enable testing
enable_testing()

# Add tests
add_test(NAME LogSvcTest COMMAND test_app)
