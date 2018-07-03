#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "initVideo.hpp"

using namespace sdl;

InitVideo::InitVideo() noexcept(false) {
	if (SDL_GetNumVideoDrivers() > 0) {
		if (int v = SDL_VideoInit(NULL) != 0) {
			std::stringstream ss;
			ss << "SDL_VideoInit failed with code " << v << ": "
			   << SDL_GetError();
			throw error::InitError(ss);
		}
	} else {
		std::stringstream ss;
		ss << "0 drivers found";
		throw error::InitError(ss);
	}

	if (int numDisp = SDL_GetNumVideoDisplays() < 1) {
		std::stringstream ss;
		ss << "SDL_GetNumVideoDisplays returned " << numDisp;
		throw error::InitError(ss);
	}
}
