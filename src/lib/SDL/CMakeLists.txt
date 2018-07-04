project(Phoenix CXX C)

add_subdirectory(InitUtil)
add_subdirectory(InitVideo)
add_subdirectory(Display)
add_subdirectory(Window)
add_subdirectory(Renderer)
add_subdirectory(GLRenderer)
add_subdirectory(Texture)

set(SDLUtil_SRCS
  sdlUtil.cxx
)

add_library(SDLUtil STATIC ${SDLUtil_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(SDLUtil PUBLIC
  ${SDL2_INCLUDE_DIR}
  ${Phoenix_INCLUDE_DIR}/error
  ${Phoenix_INCLUDE_DIR}/sdl
)

target_link_libraries(SDLUtil
  ${SDL2_LIBRARY}
  Error
  SDLInitUtil
  SDLInitVideo
  SDLDisplay
  SDLWindow
  Graphics
)

set_property(TARGET SDLUtil PROPERTY CXX_STANDARD 17)
set_property(TARGET SDLUtil PROPERTY CXX_STANDARD_REQUIRED ON)
