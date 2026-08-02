//
//  PoderTamanho.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#ifndef PoderTamanho_hpp
#define PoderTamanho_hpp

#include <stdio.h>
#include "Poderes.hpp"

class PoderTamanho:public Poderes{
protected:
    float multiplicador;
    Raquete* afetada;
public:
    PoderTamanho();
    ~PoderTamanho();
    float getMult();
    void executar(Bola* bola);
    void desativar(Bola* bola);
    void setPos(CoordF p);
    void setTamanho(CoordF t);
    
    sf::RectangleShape* getSprite(){return sprite;}
    
};

#endif /* PoderTamanho_hpp */
