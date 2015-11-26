# robot-valley
Projet C++ ESIEE 2015

# authors
Cedric DEMONGIVERT:
  cedric.demongivert@edu.esiee.fr
Alexandre K/OURIO:
  alexandre.kourio@edu.esiee.fr

# Dependencies

## Required
- SDL2 https://www.libsdl.org/download-2.0.php
  - Download the development library for your os
  - Create a environment variable nammed SDL2DIR with the path to our installation directory
- SDL2_ttf https://www.libsdl.org/projects/SDL_ttf/
  - Download the development library for your os
  - Copy includes and libs to your SDL2 installation path
  
Note : for Visual Studio 2015, recompile SDL2 library
Note : for SDL2 libs, keep only libs files for your os (x64 / x86) in your lib folder.

## Optional (for compiling tests)
- Boost http://www.boost.org/
  - Follow boost installation process

# Build the project

- Install cmake for your OS from here : https://cmake.org/download/
- Open your OS CLI and go to the root folder of this project
- Create a new build directory if not exists
- Enter in the new created directory
- Launch CMAKE with the command :
````
cmake ../
````
- Use the created project in the build folder

Note : Some computer architecture needs specifics settings set with the -G flag, for example for visual studio 12 and a x64 architecture :

````
cmake ../ -G "Visual studio 12 2013 Win64"
````

- Copy shared libs to the bin directory (SDL2 + SDL2_ttf + Boost for tests)
- Copy the data directory into the executable directory
- Launch robot-valley.exe (robot-valley-tests.exe)
