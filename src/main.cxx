#include "app.hpp"
#include "renderer.hpp"
#include "glRenderer.hpp"

int main(int argc, char* argv[])
{
     app::App<sdl::Renderer> a;
     // app::App<sdl::GLRenderer> a;

     a.run();

     return 0;
}
