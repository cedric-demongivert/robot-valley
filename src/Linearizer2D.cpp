#include "Linearizer2D.hpp"

/**
* @author C�dric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Simple empty constructor.
*/
Linearizer2D::Linearizer2D() : width_(0), height_(0)
{ }

/**
* Constructor with width and height.
*
* @param const std::size_t width
* @param const std::size_t height
*/
Linearizer2D::Linearizer2D(const std::size_t width, const std::size_t height)
  : width_(width), height_(height)
{ }

/**
* Copy constructor.
*
* @param const Linearizer2D& toCopy
*/
Linearizer2D::Linearizer2D(const Linearizer2D& toCopy)
  : width_(toCopy.getWidth()), height_(toCopy.getHeight())
{ }

/**
* Simple empty destructor.
*/
Linearizer2D::~Linearizer2D()
{ }

/**
* Return the linearizer prefered width.
*
* @return std::size_t Width.
*/
std::size_t Linearizer2D::getWidth() const
{
  return width_;
}

/**
* Return the linearizer prefered height.
*
* @return std::size_t Height.
*/
std::size_t Linearizer2D::getHeight() const
{
  return height_;
}

/**
* Change the linearizer preferred width.
*
* @param const std::size_t newWidth
*/
void Linearizer2D::setWidth(const std::size_t newWidth)
{
  width_ = newWidth;
}

/**
* Change the linearizer preferred height.
*
* @param const std::size_t newHeight
*/
void Linearizer2D::setHeight(const std::size_t newHeight)
{
  height_ = newHeight;
}

/**
* Return true if this linearizer can linearize a specified 2D point.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @return bool
*/
bool Linearizer2D::contains(const std::size_t x, const std::size_t y) const
{
  return x >= 0 && y >= 0 && x < getWidth() && y < getHeight();
}

/**
* Return true if this linearizer can convert a linearized point to
* a 2D point.
*
* @param const std::size_t linearized
*
* @return bool
*/
bool Linearizer2D::contains(const std::size_t linearized) const
{
  return linearized >= 0 && linearized < getMaxLinearizedValue();
}
