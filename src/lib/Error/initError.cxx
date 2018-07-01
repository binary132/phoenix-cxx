#include <string>
#include <sstream>

#include "initError.hpp"
#include "SDL.h"

using namespace error;

InitError::InitError():
     exception()
{
     msg.append(unknown);
     msg.append(SDL_GetError());
}

InitError::InitError(std::string&& s):
     exception(),
     msg(std::forward<std::string>(s)) {}

InitError::InitError(std::stringstream& ss):
     exception(),
     msg(std::move(ss.str())) {}

const char* InitError::what() const noexcept
{
     return msg.c_str();
}
