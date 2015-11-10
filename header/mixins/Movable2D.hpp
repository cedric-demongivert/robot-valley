#ifndef __MOVABLE_2D_HPP
#define __MOVABLE_2D_HPP

#include "mixins/Localizable2D.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * An object that can be moved on a 2D board.
 * 
 * @class Movable2D
 */
class Movable2D 
{
  public:
    virtual ~Movable2D() {};
    
    /**
     * Change the x coordinate of the object.
     * 
     * @param const int x
     */
    virtual void setX(const int x);
    
    /**
     * Change the y coordinate of the object.
     * 
     * @param const int y
     */
    virtual void setY(const int y);
    
    /**
     * Change the location of the object to a defined position.
     * 
     * @param const int x
     * @param const int y
     */
    virtual void setLocation(const int x, const int y);
    
    /**
     * Change the location of the object to another existent 
     * localizable object.
     * 
     * @param const Localizable2D& location.
     */
    virtual void setLocation(const Localizable2D& location);
};

#endif
