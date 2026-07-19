//
//  Bola.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#ifndef Bola_hpp
#define Bola_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "VectorTL.hpp"
#include "Entidade.hpp"


class Bola:public Entidade{
protected:
    float raio;
    CoordF velocidade;
    sf::CircleShape* sprite;
public:
    Bola(CoordF p, CoordF v, float r);
    ~Bola();
    
    void mover();
    
    void setVelocidade(CoordF vel){velocidade = vel;}
    CoordF getVelocidade(){return velocidade;}
    
    void setRaio(float r){raio = r;}
    float getRaio(){return raio;}
    
};

#endif /* Bola_hpp */
