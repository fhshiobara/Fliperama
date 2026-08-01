//
//  Pong.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/07/26.
//

#ifndef Pong_hpp
#define Pong_hpp

#include <stdio.h>
#include "Bola.hpp"
#include "GerenciadorGrafico.hpp"
#include "Raquete.hpp"
#include "Gol.hpp"


class Pong{
protected:
    Raquete* R1;
    Raquete* R2;
    Bola* bola;
    Gol* G1;
    Gol* G2;
    Gerenciadores::GerenciadorGrafico* pGG;
    sf::Text txtG1;
    sf::Text txtG2;
    
public:
    Pong();
    ~Pong();
    
    void setPosInicial();
    
    void executar();
    
    
};

#endif /* Pong_hpp */
