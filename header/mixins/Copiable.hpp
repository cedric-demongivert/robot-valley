#ifndef __COPIABLE_HPP
#define __COPIABLE_HPP

#include "GSL/gsl.h"

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
    virtual ~Copiable() {}
    
    /**
     * Copy the object.
     * 
     * Allocate a new copy of this object.
     * 
     * @return gsl::owner<T*>
     */
    virtual gsl::owner<T*> copy() const = 0;
};


#endif
