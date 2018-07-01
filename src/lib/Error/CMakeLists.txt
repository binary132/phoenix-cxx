project(Phoenix CXX C)

set(Error_SRCS
  initError.cxx
)

add_library(Error STATIC ${Error_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(Error PUBLIC
  ${Phoenix_INCLUDE_DIR}/error
  ${SDL2_INCLUDE_DIR}
)

target_link_libraries(Error
  ${SDL2_LIBRARY}
)

set_property(TARGET Error PROPERTY CXX_STANDARD 17)
set_property(TARGET Error PROPERTY CXX_STANDARD_REQUIRED ON)
