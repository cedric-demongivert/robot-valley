#include "utils/HorizontalLinearizer2D.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Simple empty constructor.
*/
HorizontalLinearizer2D::HorizontalLinearizer2D() : Linearizer2D()
{ }

/**
* Constructor with width and height.
*
* @param const std::size_t width
* @param const std::size_t height
*/
HorizontalLinearizer2D::HorizontalLinearizer2D(
  const std::size_t width,
  const std::size_t height
) : Linearizer2D(width, height)
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
HorizontalLinearizer2D::HorizontalLinearizer2D(
  const std::size_t width,
  const std::size_t height,
  const int offsetX,
  const int offsetY
) : Linearizer2D(width, height, offsetX, offsetY)
{ }

/**
* Copy constructor.
*
* @param const Linearizer2D& toCopy
*/
HorizontalLinearizer2D::HorizontalLinearizer2D(
      const Linearizer2D& toCopy
) : Linearizer2D(toCopy)
{ }

/**
* Simple empty destructor.
*/
HorizontalLinearizer2D::~HorizontalLinearizer2D()
{ }

/**
* Transform a 2D Point into a unique ID of an array.
*
* @param const int x
* @param const int y
*
* @throw std::out_of_range If the 2D point can't be linearized.
*
* @return std::size_t linearized point
*/
std::size_t HorizontalLinearizer2D::linearize(
  const int x,
  const int y
) const
{
  if(!contains(x,y)) {
    throw std::out_of_range(
      "The 2D point (" + std::to_string(x) + ", " + std::to_string(y)
      + ") can't be linearized."
    );
  }

  return getHeight() * (x - getOffsetX()) + (y - getOffsetY());
}

/**
* Get the X coordinate of a unique ID.
*
* @param const std::size_t Linearized point.
*
* @throw std::out_of_range If the linearized point is out of range.
*
* @return int X coordinate of the linearized point.
*/
int HorizontalLinearizer2D::getX(
  const std::size_t linearized
) const
{
  if(!contains(linearized)) {
    throw std::out_of_range(
      "The linearized point " + std::to_string(linearized) + " can't be reversed."
    );
  }

  return (linearized / getHeight()) + getOffsetX();
}

/**
* Get the Y coordinate of a unique ID.
*
* @param const std::size_t Linearized point.
*
* @throw std::out_of_range If the linearized point is out of range.
*
* @return int Y coordinate of the point.
*/
int HorizontalLinearizer2D::getY(
  const std::size_t linearized
) const
{
  if(!contains(linearized)) {
    throw std::out_of_range(
      "The linearized point " + std::to_string(linearized) + " can't be reversed."
    );
  }

  return (linearized % getHeight()) + getOffsetY();
}

/**
* Return the maximum value that can be computed with that linearization.
*
* @return std::size_t
*/
std::size_t HorizontalLinearizer2D::getMaxLinearizedValue() const
{
  return getWidth() * getHeight();
}

/**
* Allocate a new copy of this Linearizer.
*
* @return gsl::owner<Linearizer2D*>
*/
gsl::owner<Linearizer2D*> HorizontalLinearizer2D::copy() const
{
  return gsl::owner<Linearizer2D*>(new HorizontalLinearizer2D(*this));
}
