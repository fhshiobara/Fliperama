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
    sf::RectangleShape* ponto;
    std::vector<Blocos*> pecas;
    std::vector<Blocos*>::iterator it;
    int indicePeca;
    sf::Clock clockQueda;
    float intervaloQueda;
    bool gameOver;
    sf::Text txtGameOver;
    sf::Text txtReiniciar;
    sf::Text pontos;
    int pts;
    std::vector<int> saco;
    void reabastecerSaco();
    int proximaPeca();
public:
    Tetris();
    ~Tetris();
    
    void criarCenario();
    void criarPecas();
    
    void tratarEventos();
    void atualizar();
    void desenhar();
    
    void executar();
    void criarTextos();
    void reiniciar();
    
};



#endif /* Tetris_hpp */
