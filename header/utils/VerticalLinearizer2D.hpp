#ifndef __VERTICAL_LINEARIZER_2D_HPP
#define __VERTICAL_LINEARIZER_2D_HPP

#include "utils/Linearizer2D.hpp"
#include <string>

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* Linearize 2D array, column by column.
*
* @class VerticalLinearizer2D
*/
class VerticalLinearizer2D :
  public Linearizer2D
{
  public:
    /**
    * Simple empty constructor.
    */
    VerticalLinearizer2D();

    /**
    * Constructor with width and height.
    *
    * @param const std::size_t width
    * @param const std::size_t height
    */
    VerticalLinearizer2D(
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
    VerticalLinearizer2D(
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
    VerticalLinearizer2D(const Linearizer2D& toCopy);

    /**
    * Simple empty destructor.
    */
    virtual ~VerticalLinearizer2D();

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
    ) const;

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
    ) const;

    /**
    * Get the Y coordinate of a unique ID.
    *
    * @param const std::size_t Linearized point.
    *
    * @throw std::out_of_range If the linearized point is out of range.
    *
    * @return int Y coordinate of the point.
    */
    virtual int getY(
      const std::size_t linearized
    ) const;

    /**
    * Return the maximum value that can be computed with that linearization.
    *
    * @return std::size_t
    */
    virtual std::size_t getMaxLinearizedValue() const;
};

#endif
