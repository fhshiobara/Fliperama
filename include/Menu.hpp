//
//  Menu.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 15/08/26.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <vector>
#include <string>
#include "GerenciadorGrafico.hpp"

enum class EscolhaJogo{
    NENHUM,
    TETRIS,
    PONG,
    SNAKE,
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
    sf::Text instrucao;
    sf::Text rodape;

    std::vector<std::string> nomesOpcoes;
    std::vector<sf::Text> textosOpcoes;

    sf::Clock clockPiscar;
    bool visivel;

    int selecionado;
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
