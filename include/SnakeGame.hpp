//
//  SnakeGame.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/08/26.
//

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <stdio.h>
#include "GerenciadorGrafico.hpp"
#include "MapaSnake.hpp"

class SnakeGame{
private:
    Gerenciadores::GerenciadorGrafico* pGG;
    MapaSnake mapa;
public:
    SnakeGame();
    ~SnakeGame();
    void desenhar();
    void executar();
    void tratarEventos();
    void atualizar();
    
    
    
};

#endif /* SnakeGame_hpp */
