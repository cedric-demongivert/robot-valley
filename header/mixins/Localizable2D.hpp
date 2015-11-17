#ifndef __LOCALIZABLE_2D_HPP
#define __LOCALIZABLE_2D_HPP

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * Tagged class can be localized on a 2D grid.
 * 
 * @class Localizable2D
 */
class Localizable2D 
{
  public:
    virtual ~Localizable2D() {}
    
    /**
     * Return the x coordinate of the object.
     * 
     * @return int
     */
    virtual int getX() const = 0;
    
    /**
     * Return the y coordinate of the object.
     * 
     * @return int
     */
    virtual int getY() const = 0;
};

#endif
