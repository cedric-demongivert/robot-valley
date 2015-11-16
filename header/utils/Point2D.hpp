#ifndef __POINT_2D_HPP
#define __POINT_2D_HPP

#include "mixins/Localizable2D.hpp"
#include "mixins/Movable2D.hpp"
#include "mixins/Copiable.hpp"

#include "GSL/gsl.h"

class Point2D
  : public Localizable2D,
    public Movable2D,
    public Copiable<Point2D>
{
  public:    
    /**
     * Create a new Zero Point.
     */
    inline Point2D() : x_(0), y_(0)
    { }
    
    /**
     * Create a new common point.
     * 
     * @param const int x
     * @param const int y
     */
    inline Point2D(const int x, const int y) : x_(x), y_(y)
    { }
    
    /**
     * Copy a localizable object.
     * 
     * @param const Localizable2D& toCopy
     */
    inline Point2D(const Localizable2D& toCopy) 
      : x_(toCopy.getX()),
        y_(toCopy.getY())
    { }
    
    /**
     * Return x coordinate.
     * 
     * @return int
     */
    inline int getX() const override
    {
      return x_;
    }
    
    /**
     * Return y coordinate.
     * 
     * @return int
     */
    inline int getY() const override
    {
      return y_;
    }
    
    /**
     * Change the x coordinate.
     * 
     * @param const int x
     */
    inline void setX(const int x) override
    {
      x_ = x;
    }
    
    /**
     * Change the y coordinate.
     * 
     * @param const int y
     */
    inline void setY(const int y) override
    {
      y_ = y;
    }
    
    /**
     * Change the point location.
     * 
     * @param const int x
     * @param const int y
     */
    inline void setLocation(const int x, const int y) override
    {
      x_ = x;
      y_ = y;
    }
    
    /**
     * Change the position of the point to another localizable object
     * position.
     * 
     * @param const Localizable2D& other
     */
    inline void setLocation(const Localizable2D& other) override
    {
      x_ = other.getX();
      y_ = other.getY();
    }
    
    /**
     * Allocate a copy of this point.
     * 
     * @return gsl::owner<Point2D*>
     */
    inline gsl::owner<Point2D*> copy() const override
    {
      return gsl::owner<Point2D*> (new Point2D(*this));
    }
    
  protected:
    int x_;
    int y_;
};

#endif
