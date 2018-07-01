project(Phoenix CXX C)

set(World_SRCS
  world.cxx
)

add_library(World STATIC ${World_SRCS})

target_include_directories(World PUBLIC
  ${Phoenix_INCLUDE_DIR}/world
  ${SDL2_INCLUDE_DIR}
)

set_property(TARGET World PROPERTY CXX_STANDARD 17)
set_property(TARGET World PROPERTY CXX_STANDARD_REQUIRED ON)
