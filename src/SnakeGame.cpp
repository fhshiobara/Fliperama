//
//  SnakeGame.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 18/08/26.
//

#include "SnakeGame.hpp"

SnakeGame::SnakeGame():pGG(Gerenciadores::GerenciadorGrafico::getInstance()){
    
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
    mapa.draw();
    pGG->display();
    
}
void SnakeGame::atualizar(){}

void SnakeGame::tratarEventos(){
    sf::Event event;
    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
        }
        // depois você adiciona aqui as teclas de direção da cobra
    }
}
