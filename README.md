# phoenix-cxx
A port of Phoenix to C++ -- see https://github.com/synapse-garden/phoenix

# Using Phoenix

Just press `esc` to leave the program.

# Build and run Phoenix

## Linux

You need SDL 2.0.4 and CMake 3.1.0 or higher.  You'll also need a C++ compiler
with C++11 support and a make utility.
[ninja](https://martine.github.io/ninja/) is highly recommended.

```bash
git clone git@github.com:synapse-garden/phoenix-cxx.git
cd phoenix-cxx
cd build
cmake .. # -G "Ninja" if you want to build using Ninja
make # or ninja
cd target
./Phoenix
```

---

## Windows

Phoenix can be built on Windows using Visual Studio.  You can also use MinGW
via the Linux instructions, but why would you want to do that?

### Setup

First, you'll need Visual Studio 2013+.  [Express 2013 for Windows Desktop](https://www.visualstudio.com/en-us/products/visual-studio-express-vs.aspx)
will suffice.  This has C++11 support.  Earlier versions will not build 
Phoenix.

You'll also need to download and install
[SDL 2.0.4](https://www.libsdl.org/download-2.0.php) for Windows.  Select
"Development Libraries".  You should put this in its own folder in your
libraries path, and
[set an environment variable named SDL2DIR](https://www.microsoft.com/resources/documentation/windows/xp/all/proddocs/en-us/sysdm_advancd_environmnt_addchange_variable.mspx?mfr=true)
to the location.  This will let CMake find the library.

On that note, you'll also need
[CMake 3.1.0 or higher](http://www.cmake.org/download/) to actually build the
software.

#### Building Phoenix

You'll need to be working in your [developer terminal](https://msdn.microsoft.com/en-us/library/ms229859(v=vs.110).aspx).

```bash
git clone git@github.com:synapse-garden/phoenix-cxx.git
cd phoenix-cxx
cd build
cmake .. -G "NMake Makefiles" # Or -G "Ninja" if using Ninja build.
nmake # Or ninja
```

Now copy SDL2.dll from %SDL2DIR%\lib to the build\target folder.  `Phoenix.exe`
requires it in the same location in order to run.

---

Please [open an issue](https://github.com/synapse-garden/phoenix-cxx/issues/new)
if you experience any problems.  Thanks!
