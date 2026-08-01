//
//  Gol.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 31/07/26.
//

#ifndef Gol_hpp
#define Gol_hpp

#include <stdio.h>
#include "Entidade.hpp"

class Gol:public Entidade{
protected:
    CoordF tamanho;
    int pontos;
public:
    Gol();
    ~Gol();
    
    void setPontos(int p);
    int getPontos();
    
    void setTamanho(CoordF t);
    
};

#endif /* Gol_hpp */
