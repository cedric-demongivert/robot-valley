#ifndef __SIMPLE_SCALLOP_SHELL_DATA_HPP
#define __SIMPLE_SCALLOP_SHELL_DATA_HPP

#include "scallop/ScallopShellDataInterface.hpp"
#include "utils/HorizontalLinearizer2D.hpp"
#include "GSL/gsl.h"
#include <cstdlib>
#include <string>
#include <algorithm>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* A easy and unoptimized implementation of ScallopShellDataInterface
*
* @class ScallopShellDataInterface
*/
class SimpleScallopShellData
  : public ScallopShellDataInterface
{
  public:  
    SimpleScallopShellData(const std::size_t width, const std::size_t height);
    SimpleScallopShellData(const ScallopShellDataInterface& toCopy);
    virtual ~SimpleScallopShellData();

    /**
    * Get a character of the shell.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return char Char at the (x,y) position.
    */
    char getChar(const std::size_t x, const std::size_t y) const override;

    /**
    * Get a character of the shell.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @param const char ch Character to set.
    */
    void setChar(const std::size_t x, const std::size_t y, const char ch) override;

    /**
    * Set the dataset cursor to a specific location.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    */
    void setCursor(const std::size_t x, const std::size_t y) override;

    /**
    * Return the dataset cursor location.
    *
    * @return std::size_t X coordinate of the cursor.
    */
    std::size_t getCursorX() const override;

    /**
    * Return the dataset cursor location.
    *
    * @return std::size_t Y coordinate of the cursor.
    */
    std::size_t getCursorY() const override;

    /**
    * Print a character sequence in the dataset.
    *
    * @param const std::string& toPrint
    */
    void next(const std::string& toPrint) override;

    /**
    * Print a character sequence in the dataset and go to the next line.
    *
    * @param const std::string& toPrint
    */
    void nextln(const std::string& toPrint) override;

    /**
    * Set the cursor to the next line.
    */
    void nextLine() override;

    /**
    * Set the cursor to the next location.
    */
    void next() override;

    /**
    * Set a character to the actual cursor location, and set the cursor to the 
    * next location.
    *
    * @param const char ch Character to set.
    */
    void next(const char ch) override;

    /**
    * Return the width of the dataset.
    *
    * @return std::size_t Width of the dataset.
    */
    std::size_t getWidth() const override;

    /**
    * Return the height of the dataset.
    *
    * @return std::size_t Height of the dataset.
    */
    std::size_t getHeight() const override;

    /**
    * Change the width of the dataset.
    *
    * @param std::size_t newWidth
    */
    void setWidth(const std::size_t newWidth) override;

    /**
    * Change the height of the dataset.
    *
    * @param std::size_t newHeight
    */
    void setHeight(const std::size_t newHeight) override;

    /**
    * Change the width and height of the dataset.
    *
    * @param std::size_t newWidth
    * @param std::size_t newHeight
    */
    void setDimensions(const std::size_t newWidth, const std::size_t newHeight) override;

    /**
    * Reset the shell data.
    */
    void clear() override;

  protected:
    std::size_t cursor_;
    gsl::owner<char*> buffer_;
    HorizontalLinearizer2D linearizer_;
};

#endif