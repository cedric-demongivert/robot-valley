#include "scallop/SimpleScallopShellData.hpp"
#include <iostream>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* A easy and unoptimized implementation of ScallopShellDataInterface
*
* @class ScallopShellDataInterface
*/

SimpleScallopShellData::SimpleScallopShellData(const std::size_t width, const std::size_t height)
  : buffer_(gsl::owner<char*>(new char[width*height])),
    linearizer_(HorizontalLinearizer2D(width, height))
{
  cursor_ = linearizer_.linearize(0, 0);
  std::fill(buffer_, buffer_ + (width*height), ' ');
}

SimpleScallopShellData::SimpleScallopShellData(const ScallopShellDataInterface& toCopy)
  : buffer_(new char[toCopy.getWidth()*toCopy.getHeight()]),
    linearizer_(HorizontalLinearizer2D(toCopy.getWidth(), toCopy.getHeight())),
    cursor_(linearizer_.linearize(toCopy.getCursorX(), toCopy.getCursorY()))
{
  for (std::size_t x = 0; x < toCopy.getWidth(); ++x) {
    for (std::size_t y = 0; y < toCopy.getHeight(); ++y) {
      buffer_[linearizer_.linearize(x, y)] = toCopy.getChar(x, y);
    }
  }
}

SimpleScallopShellData::~SimpleScallopShellData()
{
  delete[] buffer_;
  buffer_ = nullptr;
}

/**
* Get a character of the shell.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @return char Char at the (x,y) position.
*/
char SimpleScallopShellData::getChar(const std::size_t x, const std::size_t y) const {
  return buffer_[linearizer_.linearize(x, y)];
}

/**
* Get a character of the shell.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @param const char ch Character to set.
*/
void SimpleScallopShellData::setChar(const std::size_t x, const std::size_t y, const char ch)
{
  buffer_[linearizer_.linearize(x, y)] = ch;
}

/**
* Set the dataset cursor to a specific location.
*
* @param const std::size_t x
* @param const std::size_t y
*/
void SimpleScallopShellData::setCursor(const std::size_t x, const std::size_t y)
{
  cursor_ = linearizer_.linearize(x, y);
}

/**
* Return the dataset cursor location.
*
* @return std::size_t X coordinate of the cursor.
*/
std::size_t SimpleScallopShellData::getCursorX() const
{
  return linearizer_.getX(cursor_);
}

/**
* Return the dataset cursor location.
*
* @return std::size_t Y coordinate of the cursor.
*/
std::size_t SimpleScallopShellData::getCursorY() const
{
  return linearizer_.getY(cursor_);
}

/**
* Print a character sequence in the dataset.
*
* @param const std::string& toPrint
*/
void SimpleScallopShellData::next(const std::string& toPrint)
{
  for (char c : toPrint) {
    next(c);
  }
}

/**
* Print a character sequence in the dataset and go to the next line.
*
* @param const std::string& toPrint
*/
void SimpleScallopShellData::nextln(const std::string& toPrint)
{
  for (char c : toPrint) {
    next(c);
  }
  nextLine();
}

/**
* Set the cursor to the next line.
*/
void SimpleScallopShellData::nextLine()
{
  cursor_ = linearizer_.linearize((getCursorX() + 1) % (getHeight()), 0);
}

/**
* Set the cursor to the next location.
*/
void SimpleScallopShellData::next()
{
  cursor_ = (cursor_ + 1) % (linearizer_.getMaxLinearizedValue());
}

/**
* Set a character to the actual cursor location, and set the cursor to the
* next location.
*
* @param const char ch Character to set.
*/
void SimpleScallopShellData::next(const char ch)
{
  buffer_[cursor_] = ch;
  next();
}

/**
* Return the width of the dataset.
*
* @return std::size_t Width of the dataset.
*/
std::size_t SimpleScallopShellData::getWidth() const
{
  return linearizer_.getWidth();
}

/**
* Return the height of the dataset.
*
* @return std::size_t Height of the dataset.
*/
std::size_t SimpleScallopShellData::getHeight() const
{
  return linearizer_.getHeight();
}

/**
* Change the width of the dataset.
*
* @param std::size_t newWidth
*/
void SimpleScallopShellData::setWidth(const std::size_t newWidth)
{
  setDimensions(newWidth, getHeight());
}

/**
* Change the height of the dataset.
*
* @param std::size_t newHeight
*/
void SimpleScallopShellData::setHeight(const std::size_t newHeight)
{
  setDimensions(getWidth(), newHeight);
}

/**
* Change the width and height of the dataset.
*
* @param std::size_t newWidth
* @param std::size_t newHeight
*/
void SimpleScallopShellData::setDimensions(const std::size_t newWidth, const std::size_t newHeight)
{
  gsl::owner<char*> oldBuffer = buffer_;
  HorizontalLinearizer2D oldLinearizer (linearizer_);

  buffer_ = new char[newWidth * newHeight];
  std::fill(buffer_, buffer_ + (newWidth * newHeight), ' ');
  linearizer_.setWidth(newWidth);
  linearizer_.setHeight(newHeight);
  cursor_ = linearizer_.linearize(0, 0);

  for (std::size_t y = 0; y < oldLinearizer.getHeight(); ++y) {
    for (std::size_t x = 0; x < oldLinearizer.getWidth(); ++x) {
      next(oldBuffer[oldLinearizer.linearize(x, y)]);
    }
    nextLine();
  }

  delete[] oldBuffer;
  oldBuffer = nullptr;
}

/**
* Reset the shell data.
*/
void SimpleScallopShellData::clear()
{
  std::fill(buffer_, buffer_ + linearizer_.getMaxLinearizedValue(), ' ');
}