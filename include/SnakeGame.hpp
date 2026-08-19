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
#include <vector>

class SnakeGame{
private:
    Gerenciadores::GerenciadorGrafico* pGG;
    MapaSnake mapa;
    std::vector<Frutinha*> frutas;
    
public:
    SnakeGame();
    ~SnakeGame();
    void addFrutas();
    void desenhar();
    void executar();
    void tratarEventos();
    void atualizar();
    
    
    
};

#endif /* SnakeGame_hpp */
