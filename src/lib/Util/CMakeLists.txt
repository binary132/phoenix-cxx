project(Phoenix CXX C)

set(Util_SRCS
  initUtil.cxx
)

add_library(Util STATIC ${Util_SRCS})

target_include_directories(Util PUBLIC
  ${Phoenix_INCLUDE_DIR}/error
  ${Phoenix_INCLUDE_DIR}/util
)

target_link_libraries(Util
  Error
)

set_property(TARGET Util PROPERTY CXX_STANDARD 17)
set_property(TARGET Util PROPERTY CXX_STANDARD_REQUIRED ON)
