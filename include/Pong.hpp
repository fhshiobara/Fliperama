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

class Pong{
protected:
    Raquete* R1;
    Raquete* R2;
    Bola* bola;
    Gerenciadores::GerenciadorGrafico* pGG;
    
public:
    Pong();
    ~Pong();
    
    void executar();
    
    
};

#endif /* Pong_hpp */
