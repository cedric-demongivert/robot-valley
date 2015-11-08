#ifndef __LINEARIZER_2D_HPP
#define __LINEARIZER_2D_HPP

#include <cstdlib>
#include <stdexcept>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* This class is an abstract base class for other linearizer.
* A 2D Linearizer will assign a unique ID of a linear array to
* each 2D point of a matrix.
*
* @class Linearizer2D
*/
class Linearizer2D
{
  public:
    /**
    * Simple empty constructor.
    */
    Linearizer2D();

    /**
    * Constructor with width and height.
    *
    * @param const std::size_t width
    * @param const std::size_t height
    */
    Linearizer2D(
      const std::size_t width,
      const std::size_t height
    );

    /**
    * Copy constructor.
    *
    * @param const Linearizer2D& toCopy
    */
    Linearizer2D(const Linearizer2D& toCopy);

    /**
    * Simple empty destructor.
    */
    virtual ~Linearizer2D();

    /**
    * Transform a 2D Point into a unique ID of an array.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @throw std::out_of_range If the 2D point can't be linearized.
    *
    * @return std::size_t linearized point
    */
    virtual std::size_t linearize(
      const std::size_t x, const std::size_t y
    ) const = 0;

    /**
    * Get the X coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return std::size_t X coordinate of the linearized point.
    */
    virtual std::size_t getX(
      const std::size_t linearized
    ) const = 0;

    /**
    * Get the Y coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return std::size_t Y coordinate of the point.
    */
    virtual std::size_t getY(
      const std::size_t linearized
    ) const = 0;

    /**
    * Return the linearizer prefered width.
    *
    * @return std::size_t Width.
    */
    virtual std::size_t getWidth() const;

    /**
    * Return the linearizer prefered height.
    *
    * @return std::size_t Height.
    */
    virtual std::size_t getHeight() const;

    /**
    * Change the linearizer preferred width.
    *
    * @param const std::size_t newWidth
    */
    virtual void setWidth(const std::size_t newWidth);

    /**
    * Change the linearizer preferred height.
    *
    * @param const std::size_t newHeight
    */
    virtual void setHeight(const std::size_t newHeight);

    /**
    * Return the maximum value that can be computed with that linearization.
    *
    * @return std::size_t
    */
    virtual std::size_t getMaxLinearizedValue() const = 0;

    /**
    * Return true if this linearizer can linearize a specified 2D point.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return bool
    */
    virtual bool contains(const std::size_t x, const std::size_t y) const;

    /**
    * Return true if this linearizer can convert a linearized point to
    * a 2D point.
    *
    * @param const std::size_t linearized
    *
    * @return bool
    */
    virtual bool contains(const std::size_t linearized) const;

  protected:
    std::size_t width_;
    std::size_t height_;
};

#endif
