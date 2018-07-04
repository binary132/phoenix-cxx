namespace app {
     template<class T>
     App<T>::App(const std::string& titleIn) noexcept(false) :
	  title(titleIn),
	  sdlUtil(title,
		  SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI |
		  SDL_WINDOW_OPENGL     | SDL_WINDOW_INPUT_GRABBED),
	  graphics(sdlUtil.windowHandle(),
		   sdlUtil.w(), sdlUtil.h()) { }
}
