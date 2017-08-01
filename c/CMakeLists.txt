# our library
configure_file(config.h.in config.h @ONLY)

add_library(c_wrapper c_wrapper.cc)