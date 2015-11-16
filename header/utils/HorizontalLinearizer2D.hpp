#ifndef __HORIZONTAL_LINEARIZER_2D_HPP
#define __HORIZONTAL_LINEARIZER_2D_HPP

#include "utils/Linearizer2D.hpp"
#include <string>
#include <cstdlib>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* Linearize 2D array, row by row.
*
* @class HorizontalLinearizer2D
*/
class HorizontalLinearizer2D 
  : public Linearizer2D
{
  public:
    /**
    * Simple empty constructor.
    */
    HorizontalLinearizer2D();

    /**
    * Constructor with width and height.
    *
    * @param const std::size_t width
    * @param const std::size_t height
    */
    HorizontalLinearizer2D(
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
    HorizontalLinearizer2D(
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
    HorizontalLinearizer2D(const Linearizer2D& toCopy);

    /**
    * Simple empty destructor.
    */
    virtual ~HorizontalLinearizer2D();

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
    std::size_t linearize(
      const int x, const int y
    ) const override;

    /**
    * Get the X coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return int X coordinate of the linearized point.
    */
    int getX(
      const std::size_t linearized
    ) const override;

    /**
    * Get the Y coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return int Y coordinate of the point.
    */
    int getY(
      const std::size_t linearized
    ) const override;

    /**
    * Return the maximum value that can be computed with that linearization.
    *
    * @return std::size_t
    */
    std::size_t getMaxLinearizedValue() const override;

    /**
    * Allocate a new copy of this Linearizer.
    *
    * @return gsl::owner<Linearizer2D*>
    */
    virtual gsl::owner<Linearizer2D*> copy() const override;
};

#endif
