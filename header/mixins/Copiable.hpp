#ifndef __COPIABLE_HPP
#define __COPIABLE_HPP

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * An object that can be copied.
 * 
 * @class Copiable
 */
template<class T>
class Copiable 
{
  public:
    ~Copiable() {};
    
    /**
     * Copy the object.
     * 
     * @return T
     */
    virtual T copy() const = 0;
};


#endif
