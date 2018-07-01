project(Phoenix CXX C)

set(App_SRCS
  app.cxx
  appMain.cxx
)

add_library(App STATIC ${App_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(App PUBLIC
  ${SDL2_INCLUDE_DIR}
  ${Phoenix_INCLUDE_DIR}/error
  ${Phoenix_INCLUDE_DIR}/world
  ${Phoenix_INCLUDE_DIR}/app
  ${Phoenix_INCLUDE_DIR}/sdl
  ${Phoenix_INCLUDE_DIR}/graphics
)

target_link_libraries(App
  ${SDL2_LIBRARY}
  Error
  SDLUtil
  World
  Graphics
)

set_property(TARGET App PROPERTY CXX_STANDARD 17)
set_property(TARGET App PROPERTY CXX_STANDARD_REQUIRED ON)
