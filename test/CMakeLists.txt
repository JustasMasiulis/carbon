set(TEST_NAME "main_test")

add_executable(${TEST_NAME} "main.cpp")

target_include_directories(${TEST_NAME} PRIVATE ${CARBON_INCLUDE_BUILD_DIR})
target_link_libraries(${TEST_NAME} ${CARBON_TARGET_NAME})
set_target_properties(${TEST_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++17-extensions")
