#include <memory>
#include <time.h>

#include "SDL.h"

#include "app.hpp"

using namespace app;

void App::run()
{
     srand(time(NULL));

     const int numPoints = 30000;
     bool finished = false;
     bool lmbDown = false;

     int xMid = w() / 2.0;
     int yMid = h() / 2.0;

     int mouseX = xMid, mouseY = yMid;

     SDL_Event event = SDL_Event{ 0 };

     std::allocator<Part> ps;
     Part* parts = ps.allocate(numPoints);

     for( int i = 0; i < numPoints; i++ ) {
          parts[i] = Part(xMid - (int)(w()/4.0) + rand()%(int)(w()/4.0),
                          yMid - (int)(h()/4.0) + rand()%(int)(h()/4.0));
     }

     while (!finished) {
          while (SDL_PollEvent(&event)) {
               switch(event.type) {
               case SDL_QUIT:
                    finished = true;
                    break;
               case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                         finished = true;
                    }
                    break;
               case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                         lmbDown = false;
                    break;
               case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                         lmbDown = true;
                         mouseX = event.button.x;
                         mouseY = event.button.y;
                    }
                    break;
               case SDL_MOUSEMOTION:
                    if (lmbDown)
                    {
                         mouseX = event.motion.x;
                         mouseY = event.motion.y;
                    }
                    break;
               }
          }

          for( int i = 0; i < numPoints; i++ ) {
               if(lmbDown) {
                    parts[i].grav(mouseX, mouseY);
               }
               parts[i].update();
               graphics.drawBlob(
		    std::move(parts[i].x),
		    std::move(parts[i].y),
		    std::move(parts[i].r),
		    std::move(parts[i].color)
	       );
          }

          graphics.update();
          graphics.draw();
          graphics.clear();
     }

     ps.deallocate(parts, numPoints);
}
