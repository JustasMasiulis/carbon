cmake_minimum_required(VERSION 3.8)
project(CARBON LANGUAGES CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

option(CARBON_BUILD_TESTS "Build the unit tests when BUILD_TESTING is enabled." ON)


set(CARBON_TARGET_NAME         ${PROJECT_NAME})
set(CARBON_INCLUDE_INSTALL_DIR "include")
set(CARBON_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include/")


add_library(${CARBON_TARGET_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${CARBON_TARGET_NAME} ALIAS ${CARBON_TARGET_NAME})
target_compile_features(${CARBON_TARGET_NAME} INTERFACE cxx_std_17)


target_include_directories(
    ${CARBON_TARGET_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CARBON_INCLUDE_BUILD_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(CTest)

if(BUILD_TESTING AND CARBON_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()


install(
    DIRECTORY ${CARBON_INCLUDE_BUILD_DIR}
    DESTINATION ${CARBON_INCLUDE_INSTALL_DIR}
)

