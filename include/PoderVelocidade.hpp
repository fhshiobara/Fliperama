//
//  PoderVelocidade.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#ifndef PoderVelocidade_hpp
#define PoderVelocidade_hpp

#include <stdio.h>
#include "Poderes.hpp"

class PoderVelocidade:public Poderes{
protected:
    float multiplicador;
public:
    PoderVelocidade();
    ~PoderVelocidade();
    float getMult();
    
};

#endif /* PoderVelocidade_hpp */
