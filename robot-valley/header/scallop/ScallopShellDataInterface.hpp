#ifndef __SCALLOP_SHELL_DATA_INTERFACE_HPP
#define __SCALLOP_SHELL_DATA_INTERFACE_HPP

#include <cstdlib>
#include <string>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* Character data for a ScallopShell.
*
* @class ScallopShellDataInterface
*/
class ScallopShellDataInterface
{
  public:  
    virtual ~ScallopShellDataInterface() {};

    /**
    * Get a character of the shell.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return char Char at the (x,y) position.
    */
    virtual char getChar(const std::size_t x, const std::size_t y) const = 0;

    /**
    * Get a character of the shell.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @param const char ch Character to set.
    */
    virtual void setChar(const std::size_t x, const std::size_t y, const char ch) = 0;

    /**
    * Set the dataset cursor to a specific location.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    */
    virtual void setCursor(const std::size_t x, const std::size_t y) = 0;

    /**
    * Return the dataset cursor location.
    *
    * @return std::size_t X coordinate of the cursor.
    */
    virtual std::size_t getCursorX() const = 0;

    /**
    * Return the dataset cursor location.
    *
    * @return std::size_t Y coordinate of the cursor.
    */
    virtual std::size_t getCursorY() const = 0;

    /**
    * Print a character sequence in the dataset.
    *
    * @param const std::string& toPrint
    */
    virtual void next(const std::string& toPrint) = 0;

    /**
    * Print a character sequence in the dataset and go to the next line.
    *
    * @param const std::string& toPrint
    */
    virtual void nextln(const std::string& toPrint) = 0;

    /**
    * Set the cursor to the next line.
    */
    virtual void nextLine() = 0;

    /**
    * Set the cursor to the next location.
    */
    virtual void next() = 0;

    /**
    * Set a character to the actual cursor location, and set the cursor to the 
    * next location.
    *
    * @param const char ch Character to set.
    */
    virtual void next(const char ch) = 0;

    /**
    * Return the width of the dataset.
    *
    * @return std::size_t Width of the dataset.
    */
    virtual std::size_t getWidth() const = 0;

    /**
    * Return the height of the dataset.
    *
    * @return std::size_t Height of the dataset.
    */
    virtual std::size_t getHeight() const = 0;

    /**
    * Change the width of the dataset.
    *
    * @param std::size_t newWidth
    */
    virtual void setWidth(const std::size_t newWidth) = 0;

    /**
    * Change the height of the dataset.
    *
    * @param std::size_t newHeight
    */
    virtual void setHeight(const std::size_t newHeight) = 0;

    /**
    * Change the width and height of the dataset.
    *
    * @param std::size_t newWidth
    * @param std::size_t newHeight
    */
    virtual void setDimensions(const std::size_t newWidth, const std::size_t newHeight) = 0;

    /**
    * Reset the shell data.
    */
    virtual void clear() = 0;

};

#endif