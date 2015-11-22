#include "scallop/SDLScallopShell.hpp"

#define FONT_VSPACING 0
#define CONSOLE_HSPACING 5

/**
* Create a new ScallopShell for SDL
*
* @param const std::string& title Title of the shell
*/
SDLScallopShell::SDLScallopShell(const std::string& title, const std::size_t lines, const std::size_t columns)
  : SimpleScallopShellData(columns, lines),
    title_(title)
{

  if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0) {
    throw "SDL Initialisation error." + std::string(SDL_GetError());
  }

  if (TTF_Init() != 0) {
    throw "SDL_ttf Initialisation error." + std::string(TTF_GetError());
  }

  font_ = TTF_OpenFont("./data/fonts/VeraMono-Bold.ttf", 16);

  // Better with a wrapping class
  if (font_ == nullptr) {
    throw "Font loading error... Data folder is in executable directory ?" + std::string(TTF_GetError());
  }

  if (TTF_SizeText(font_, "w", &charWidth_, &charHeight_)) {
    throw "Font rendering error... Woaow..." + std::string(TTF_GetError());
  }

  windowWidth_ = (charWidth_)*lines + CONSOLE_HSPACING * 2;
  windowHeight_ = (charHeight_ + FONT_VSPACING * 2)*columns;

  int check = SDL_CreateWindowAndRenderer(
    windowWidth_,
    windowHeight_,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS,
    &window_,
    &renderer_
  );

  SDL_SetWindowPosition(window_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
  SDL_SetWindowTitle(window_, title_.c_str());

  if (check != 0) {
    throw "SDL Window and Renderer creation error." + std::string(SDL_GetError());
  }

  SDLScallopShell::render();

}

/**
* Render the shell.
*/
void SDLScallopShell::render()
{
  // Fill with dark color
  if (SDL_SetRenderDrawColor(renderer_, 30, 30, 30, 255) != 0) throw "Error during rendering";
  if (SDL_RenderClear(renderer_) != 0) throw "Error during rendering";

  // Draw characters
  char toPrint[2];
  toPrint[1] = 0;

  SDL_Color fg = { 255, 255, 255 };

  for (std::size_t y = 0; y < getHeight(); ++y) {
    for (std::size_t x = 0; x < getWidth(); ++x) {
      toPrint[0] = getChar(x, y);
      SDL_Surface* surface_char = TTF_RenderUTF8_Solid(font_, toPrint, fg);
      if (surface_char == nullptr) throw "Error during rendering";

      SDL_Texture* texture_char = SDL_CreateTextureFromSurface(renderer_, surface_char);
      if (texture_char == nullptr) throw "Error during rendering";

      SDL_Rect char_dimensions = { 0, 0, 0, 0 };
      SDL_QueryTexture(texture_char, nullptr, nullptr, &char_dimensions.w, &char_dimensions.h);
      SDL_Rect final_location = { 
        CONSOLE_HSPACING + y * charWidth_, 
        FONT_VSPACING + FONT_VSPACING * 2 * x + charHeight_*x,
        char_dimensions.w,
        char_dimensions.h
      };

      SDL_RenderCopy(renderer_, texture_char, &char_dimensions, &final_location);

      SDL_FreeSurface(surface_char);
      SDL_DestroyTexture(texture_char);
    }
  }

  SDL_RenderPresent(renderer_);

}

void SDLScallopShell::waitEnter()
{
  const Uint8* state = nullptr;

  do {
    SDL_PumpEvents();
    state = SDL_GetKeyboardState(nullptr);
  } while (!state[SDL_SCANCODE_SPACE]);

  do {
    SDL_PumpEvents();
    state = SDL_GetKeyboardState(nullptr);
  } while (state[SDL_SCANCODE_SPACE]);
}

SDLScallopShell::~SDLScallopShell()
{


  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;

  SDL_DestroyWindow(window_);
  window_ = nullptr;

  TTF_CloseFont(font_);
  font_ = nullptr;

  SDL_Quit();
  TTF_Quit();
}
