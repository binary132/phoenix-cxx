#ifndef SDLINITUTIL_H
#define SDLINITUTIL_H

namespace sdl
{
     // InitUtil simply handles SDL_Init and SDL_Quit
     class InitUtil
     {
     public:
          InitUtil(Uint32 flags = 0) noexcept(false);
          ~InitUtil();
     };
}

#endif
