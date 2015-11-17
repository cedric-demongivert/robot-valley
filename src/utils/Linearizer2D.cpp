#include "utils/Linearizer2D.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Simple empty constructor.
*/
Linearizer2D::Linearizer2D() 
  : width_(0), height_(0), offsetX_(0), offsetY_(0)
{ }

/**
* Constructor with width and height.
*
* @param const std::size_t width
* @param const std::size_t height
*/
Linearizer2D::Linearizer2D(
  const std::size_t width, 
  const std::size_t height
) : width_(width), height_(height), offsetX_(0), offsetY_(0)
{ }

/**
 * Constructor with width, height and offset.
 *
 * @param const std::size_t width
 * @param const std::size_t height
 * 
 * @param const int offsetX
 * @param const int offsetY
 */
Linearizer2D::Linearizer2D(
  const std::size_t width, 
  const std::size_t height,
  const int offsetX,
  const int offsetY
) : width_(width), height_(height), offsetX_(offsetX), offsetY_(offsetY)
{ }

/**
* Copy constructor.
*
* @param const Linearizer2D& toCopy
*/
Linearizer2D::Linearizer2D(const Linearizer2D& toCopy)
  : width_(toCopy.getWidth()), 
    height_(toCopy.getHeight()),
    offsetX_(toCopy.getOffsetX()),
    offsetY_(toCopy.getOffsetY())
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
* Return the linearizer x offset.
*
* @return int
*/
int Linearizer2D::getOffsetX() const
{
  return offsetX_;
}

/**
* Return the linearizer y offset.
*
* @return int
*/
int Linearizer2D::getOffsetY() const
{
  return offsetY_;
}

/**
* Set the linearizer x offset.
*
* @param const int offsetX.
*/
void Linearizer2D::setOffsetX(const int offsetX)
{
  offsetX_ = offsetX;
}

/**
* Set the linearizer y offset.
*
* @param const int offsetY.
*/
void Linearizer2D::setOffsetY(const int offsetY)
{
  offsetY_ = offsetY;
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
* @param const int x
* @param const int y
*
* @return bool
*/
bool Linearizer2D::contains(const int x, const int y) const
{
  return x >= getOffsetX() 
         && y >= getOffsetY()
         && x < getWidth() + getOffsetX()
         && y < getHeight() + getOffsetY();
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
  return linearized >= 0 && linearized <= getMaxLinearizedValue();
}
