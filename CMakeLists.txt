cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

# Download eigen dependency
INCLUDE(ExternalProject)

SET(THIRD_PARTY_PATH ${CMAKE_CURRENT_BINARY_DIR}/thirdparty)
SET(EIGEN_SOURCE_DIR ${THIRD_PARTY_PATH}/eigen3)

INCLUDE_DIRECTORIES(${EIGEN_SOURCE_DIR}/src/extern_eigen3)

ExternalProject_Add(
    extern_eigen3
    ${EXTERNAL_PROJECT_LOG_ARGS}
    GIT_REPOSITORY  "https://github.com/RLovelett/eigen.git"
    GIT_TAG         "master"
    PREFIX          ${EIGEN_SOURCE_DIR}
    UPDATE_COMMAND  ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    TEST_COMMAND      ""
)

if (${CMAKE_VERSION} VERSION_LESS "3.3.0")
    set(dummyfile ${CMAKE_CURRENT_BINARY_DIR}/eigen3_dummy.c)
    file(WRITE ${dummyfile} "const char * dummy_eigen3 = \"${dummyfile}\";")
    add_library(eigen3 STATIC ${dummyfile})
else()
    add_library(eigen3 INTERFACE)
endif()

add_dependencies(eigen3 extern_eigen3)

LIST(APPEND external_project_dependencies eigen3)

# build a test program
add_executable(just_a_test ${CMAKE_SOURCE_DIR}/example/test_eigen.cc)
add_dependencies(just_a_test extern_eigen3)

add_subdirectory(c)
