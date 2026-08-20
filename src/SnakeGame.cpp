//
//  SnakeGame.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/08/26.
//

#include "SnakeGame.hpp"

SnakeGame::SnakeGame()
    : pGG(Gerenciadores::GerenciadorGrafico::getInstance()),
      fruta(NULL),
      cobra(CoordI(15,15)),
      intervaloMovimento(0.15f){
    fruta = new Frutinha;
    fruta->setPos(CoordI(14,23));
    mapa.setFrutinha(fruta);
}
SnakeGame::~SnakeGame(){}

void SnakeGame::executar(){
    while(pGG->windowopen()){
        tratarEventos();
        atualizar();
        desenhar();
    }
    
}

void SnakeGame::desenhar(){
    
    pGG->clear();
    mapa.sincronizar(fruta,cobra.getCorpo());
    mapa.draw();
    pGG->display();
    
}
void SnakeGame::atualizar(){
    if(relogio.getElapsedTime().asSeconds() < intervaloMovimento) return;
    relogio.restart();

    CoordI proxima = cobra.proximaPosicao();

    // colisão com parede ou com o próprio corpo
    if(mapa.mapa[proxima.x][proxima.y] == 2 || cobra.ocupaPosicao(proxima)){
        pGG->closeWindow(); // depois você troca por uma tela de "game over"
        return;
    }

    bool vaiComer = (proxima.x == fruta->getPos().x && proxima.y == fruta->getPos().y);
    cobra.mover(vaiComer);

    if(vaiComer){
        fruta->setPos(CoordI(rand()%28+1, rand()%28+1));
        mapa.setFrutinha(fruta);
    }
}

void SnakeGame::tratarEventos(){
    sf::Event event;
    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
        }
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Up:    cobra.setDirecao(Direcao::ESQUERDA); break;
                case sf::Keyboard::Down:  cobra.setDirecao(Direcao::DIREITA); break;
                case sf::Keyboard::Left:  cobra.setDirecao(Direcao::CIMA); break;
                case sf::Keyboard::Right: cobra.setDirecao(Direcao::BAIXO); break;
                default: break;
            }
        }
    }
}
