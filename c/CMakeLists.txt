# our library
configure_file(config.h.in config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(c_wrapper SHARED c_wrapper.cc)
add_dependencies(c_wrapper extern_eigen3)