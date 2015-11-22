#include "utils/VerticalLinearizer2D.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Simple empty constructor.
*/
VerticalLinearizer2D::VerticalLinearizer2D() : Linearizer2D()
{ }

/**
* Constructor with width and height.
*
* @param const std::size_t width
* @param const std::size_t height
*/
VerticalLinearizer2D::VerticalLinearizer2D(
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
VerticalLinearizer2D::VerticalLinearizer2D(
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
VerticalLinearizer2D::VerticalLinearizer2D(const Linearizer2D& toCopy)
  : Linearizer2D(toCopy)
{ }

/**
* Simple empty destructor.
*/
VerticalLinearizer2D::~VerticalLinearizer2D()
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
std::size_t VerticalLinearizer2D::linearize(
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

  return getWidth() * (y - getOffsetY()) + (x - getOffsetX());
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
int VerticalLinearizer2D::getX(
  const std::size_t linearized
) const
{
  if(!contains(linearized)) {
    throw std::out_of_range(
      "The linearized point " + std::to_string(linearized) + " can't be reversed."
    );
  }

  return linearized % getWidth() + getOffsetX();
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
int VerticalLinearizer2D::getY(
  const std::size_t linearized
) const
{
  if(!contains(linearized)) {
    throw std::out_of_range(
      "The linearized point " + std::to_string(linearized) + " can't be reversed."
    );
  }

  return linearized / getWidth() + getOffsetY();
}

/**
* Return the maximum value that can be computed with that linearization.
*
* @return std::size_t
*/
std::size_t VerticalLinearizer2D::getMaxLinearizedValue() const
{
  return getWidth() * getHeight();
}

/**
* Allocate a new copy of this Linearizer.
*
* @return gsl::owner<Linearizer2D*>
*/
gsl::owner<Linearizer2D*> VerticalLinearizer2D::copy() const
{
  return gsl::owner<Linearizer2D*>(new VerticalLinearizer2D(*this));
}