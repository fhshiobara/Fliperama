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

class Bola{
private:
    float raio;
    CoordF velocidade;
    CoordF pos;
    sf::CircleShape* sprite;
public:
    Bola(CoordF p, CoordF v, float r);
    ~Bola();
    
    void setVelocidade(CoordF vel){velocidade = vel;}
    CoordF getVelocidade(){return velocidade;}
    
    void setRaio(float r){raio = r;}
    float getRaio(){return raio;}
    
    void setPos(CoordF p){pos = p;}
    CoordF getPos(){return pos;}
};

#endif /* Bola_hpp */
