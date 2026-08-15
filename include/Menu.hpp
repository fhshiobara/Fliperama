//
//  Menu.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 15/08/26.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "GerenciadorGrafico.hpp"

enum class EscolhaJogo{
    NENHUM,
    TETRIS,
    PONG,
    SAIR
};

class Menu{
protected:
    Gerenciadores::GerenciadorGrafico* pGG;

    sf::RectangleShape* fundo;
    sf::RectangleShape* moldura;
    sf::RectangleShape* faixaTitulo;
    sf::RectangleShape* destaque;

    sf::Text titulo;
    sf::Text opcaoTetris;
    sf::Text opcaoPong;
    sf::Text instrucao;
    sf::Text rodape;

    sf::Clock clockPiscar;
    bool visivel;

    int selecionado; // 0 = Tetris, 1 = Pong
    EscolhaJogo escolha;

public:
    Menu();
    ~Menu();

    void criarCenario();
    void criarTextos();
    void atualizarDestaque();

    void tratarEventos();
    void atualizar();
    void desenhar();

    EscolhaJogo executar();
};

#endif /* Menu_hpp */
