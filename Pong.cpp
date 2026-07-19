//
//  Pong.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/07/26.
//

#include "Pong.hpp"

Pong::Pong():R1(NULL),R2(NULL),bola(NULL),pGG(Gerenciadores::GerenciadorGrafico::getInstance()){
    
}

Pong::~Pong(){
    if(R1!=NULL){
        delete R1;
        R1 = NULL;
    }
    if(R2!=NULL){
        delete R2;
        R2 = NULL;
    }
    if(bola!=NULL){
        delete bola;
        bola = NULL;
    }
    if(pGG!=NULL){
        delete pGG;
        pGG = NULL;
    }
    
}

void Pong::executar(){
    sf::Event event;
    
    while(pGG->windowopen()){
  
        while(pGG->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGG->closeWindow();
            }
        }
        pGG->clear();
        

        R1->mover();
        R2->mover();
        bola->mover();
        bola->tratarColisaoParede();
        bola->tratarColisaoRaquete();
        
        pGG->render(R1->getSprite());
        pGG->render(R2->getSprite());
        pGG->render(bola->getSprite());
        
        pGG->display();
    }
}
