//
//  Tetris.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "Tetris.hpp"

Tetris::Tetris():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL){
    sf::Color corFundo(58,47,85);
    fundo = new sf::RectangleShape;
    fundo->setOrigin(0.f,0.f);
    fundo->setSize(sf::Vector2f(1280.f,720.f));
    fundo->setFillColor(corFundo);
    
}

Tetris::~Tetris(){
    if(pGG!=NULL){
        delete pGG;
        pGG = NULL;
    }
}

void Tetris::executar(){
    
    sf::Event event;
    while(pGG->windowopen()){
        while(pGG->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGG->closeWindow();
            }
            
            pGG->clear();
            
            
            pGG->render(fundo);
            mapa.print();
            mapa.draw();
            
            
            pGG->display();
            
            //o loop principal vai precisar vir aqui
        }
        
        
    }
}


