#ifndef __LINEARIZER_2D_HPP
#define __LINEARIZER_2D_HPP

#include <cstdlib>
#include <stdexcept>
#include "mixins/Copiable.hpp"
#include "mixins/Localizable2D.hpp"
#include "mixins/Movable2D.hpp"
#include "utils/Point2D.hpp"
#include "GSL/gsl.h"

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
  : public Copiable<Linearizer2D>
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
    * Constructor with width, height and offset.
    *
    * @param const std::size_t width
    * @param const std::size_t height
    * 
    * @param const int offsetX
    * @param const int offsetY
    */
    Linearizer2D(
      const std::size_t width,
      const std::size_t height,
      const int offsetX,
      const int offsetY
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
    * @param const int x
    * @param const int y
    *
    * @throw std::out_of_range If the 2D point can't be linearized.
    *
    * @return std::size_t linearized point
    */
    virtual std::size_t linearize(
      const int x, const int y
    ) const = 0;

    /**
    * Get the X coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return int coordinate of the linearized point.
    */
    virtual int getX(
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
    virtual int getY(
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
    * Return the linearizer x offset.
    *
    * @return int
    */
    virtual int getOffsetX() const;
    
    /**
    * Return the linearizer y offset.
    *
    * @return int
    */
    virtual int getOffsetY() const;

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
    * Set the linearizer x offset.
    *
    * @param const int offsetX.
    */
    virtual void setOffsetX(const int offsetX);
    
    /**
    * Set the linearizer y offset.
    *
    * @param const int offsetY.
    */
    virtual void setOffsetY(const int offsetY);

    /**
    * Return the maximum value that can be computed with that linearization.
    *
    * @return std::size_t
    */
    virtual std::size_t getMaxLinearizedValue() const = 0;

    /**
    * Return true if this linearizer can linearize a specified 2D point.
    *
    * @param const int x
    * @param const int y
    *
    * @return bool
    */
    virtual bool contains(const int x, const int y) const;

    /**
    * Return true if this linearizer can convert a linearized point to
    * a 2D point.
    *
    * @param const std::size_t linearized
    *
    * @return bool
    */
    virtual bool contains(const std::size_t linearized) const;
    
    virtual gsl::owner<Linearizer2D*> copy() const = 0;

  protected:
    std::size_t width_;
    std::size_t height_;
    int offsetX_;
    int offsetY_;
};

#endif
