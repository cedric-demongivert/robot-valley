#ifndef __SDL_SCALLOP_SHELL_HPP
#define __SDL_SCALLOP_SHELL_HPP

#include "scallop/ScallopShellInterface.hpp"
#include "scallop/ScallopShellDataInterface.hpp"
#include "scallop/SimpleScallopShellData.hpp"
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "GSL/gsl.h"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* SDL implementation of ScallopShell.
*/
class SDLScallopShell
  : public ScallopShellInterface,
    public SimpleScallopShellData
{
  public:
    /**
    * Create a new ScallopShell for SDL
    *
    * @param const std::string& title Title of the shell
    */
    SDLScallopShell(const std::string& title, const std::size_t lines, const std::size_t columns);
    ~SDLScallopShell();

    /**
    * Render the shell.
    */
    virtual void render();

    /**
    * Wait next key press.
    */
    virtual void waitEnter();

  protected:
    gsl::owner<SDL_Window*> window_;
    gsl::owner<SDL_Renderer*> renderer_;
    gsl::owner<TTF_Font*> font_;
    int windowWidth_;
    int windowHeight_;
    int charWidth_;
    int charHeight_;
    const std::string title_;
};

#endif