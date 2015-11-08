#ifndef __HORIZONTAL_LINEARIZER_2D_HPP
#define __HORIZONTAL_LINEARIZER_2D_HPP

#include "utils/Linearizer2D.hpp"
#include <string>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* Linearize 2D array, row by row.
*
* @class HorizontalLinearizer2D
*/
class HorizontalLinearizer2D :
  public Linearizer2D
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
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @throw std::out_of_range If the 2D point can't be linearized.
    *
    * @return std::size_t linearized point
    */
    virtual std::size_t linearize(
      const std::size_t x, const std::size_t y
    ) const override;

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
    ) const override;

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
    ) const override;

    /**
    * Return the maximum value that can be computed with that linearization.
    *
    * @return std::size_t
    */
    virtual std::size_t getMaxLinearizedValue() const override;
};

#endif
