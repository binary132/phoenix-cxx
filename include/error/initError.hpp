#ifndef INIT_ERROR_H
#define INIT_ERROR_H

#include <exception>
#include <string>
#include <string_view>

namespace error {
     class InitError: public std::exception {
     private:
	  static constexpr std::string_view unknown = "unknown error: ";
	  std::string msg;
     public:
          InitError ();

	  InitError (std::string&&);
	  InitError (std::stringstream&);

          virtual const char* what() const noexcept;
     };
}

#endif
