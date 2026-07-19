//
//  Entidade.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/07/26.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include <stdio.h>
#include "VectorTL.hpp"

class Entidade{
protected:
    CoordF pos;
public:
    Entidade();
    ~Entidade();
    void setPos(CoordF p);
    CoordF getPos();
};

#endif /* Entidade_hpp */
