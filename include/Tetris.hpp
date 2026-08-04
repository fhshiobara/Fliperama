//
//  Tetris.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#ifndef Tetris_hpp
#define Tetris_hpp

#include <stdio.h>
#include "GerenciadorGrafico.hpp"
#include "Mapa.hpp"
#include "Blocos.hpp"


class Tetris{
protected:
    Gerenciadores::GerenciadorGrafico* pGG;
    Mapa mapa;
    sf::RectangleShape* fundo;
    sf::RectangleShape* grid;
    BlocoL bloco;
public:
    Tetris();
    ~Tetris();
    
    void executar();
    
};



#endif /* Tetris_hpp */
