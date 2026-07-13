//
//  Raquete.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#ifndef Raquete_hpp
#define Raquete_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "VectorTL.hpp"

class Raquete{
private:
    CoordF pos;
    CoordF tam;
    CoordF velocidade;
    sf::RectangleShape* sprite;
public:
    Raquete(CoordF p, CoordF t,CoordF v);
    ~Raquete();
    
    
    void setPos(CoordF p){pos = p;}
    CoordF getPos(){return pos;}
    void setTam(CoordF t){tam = t;}
    CoordF getTam(){return tam;}
    void setVel(CoordF v){velocidade = v;}
    CoordF getVel(){return velocidade;}
    
    void moverY(float dt);
};

#endif /* Raquete_hpp */
