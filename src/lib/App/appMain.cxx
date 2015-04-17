#include <memory>
#include <time.h>

#include "SDL.h"

#include "app.hpp"

using namespace app;

void App::run()
{
     srand(time(NULL));

     const int numPoints = 1000;
     bool finished = false;
     bool lmbDown = false;

     int xMid = w() / 2.0;
     int yMid = h() / 2.0;

     int mouseX = xMid, mouseY = yMid;

     SDL_Event event = SDL_Event{ 0 };

     std::allocator<Part> ps;
     Part* parts = ps.allocate(numPoints);

     for( int i = 0; i < numPoints; i++ ) {
          parts[i] = Part(xMid + rand()%(int)(w()/4.0), yMid + rand()%(int)(h()/4.0), w(), h());
     }

     while (!finished) {
          graphics.update();
          mouseX = xMid, mouseY = yMid;

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
                         mouseX = event.motion.x;
                         mouseY = event.motion.y;
                    }
                    break;
               case SDL_MOUSEMOTION:
                    if (lmbDown)
                    {
                         mouseX = event.motion.x;
                         mouseY = event.motion.y;
                    }
               }
               break;
          }

          for( int i = 0; i < numPoints; i++ ) {
               if(lmbDown) {
                    parts[i].grav(mouseX, mouseY);
               }
               parts[i].update();
               graphics.drawPoint(parts[i].x, parts[i].y);
          }

          graphics.draw();
          //graphics.clear();
     }

     ps.deallocate(parts, numPoints);
}
