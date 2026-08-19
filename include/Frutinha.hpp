//
//  Frutinha.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/08/26.
//

#ifndef Frutinha_hpp
#define Frutinha_hpp

#include <stdio.h>
#include "VectorTL.hpp"
class Frutinha{
private:
    int x;
    int y;
public:
    Frutinha();
    ~Frutinha();
    
    void setPos(CoordI pos);
    CoordI getPos();
    
    
    
};
#endif /* Frutinha_hpp */
