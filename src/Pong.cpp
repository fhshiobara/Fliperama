//
//  Pong.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/07/26.
//

#include "Pong.hpp"

Pong::Pong():R1(NULL),R2(NULL),bola(NULL),pGG(Gerenciadores::GerenciadorGrafico::getInstance()){
    R1 = new Raquete(CoordF(5.f,5.f), CoordF(20.f,100.f));
    R2 = new Raquete(CoordF(5.f,5.f), CoordF (25.f,100.f));
    bola = new Bola(CoordF(10.f,05.f),8.f);
    bola->setTamJanela(CoordF(1280.f,720.f));
    bola->setRaquete(R1);
    bola->setRaquete(R2);
    this->setPosInicial();
    
    
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

void Pong::setPosInicial(){
    R1->setPos(CoordF(65.f,360.f));
    R2->setPos(CoordF(1200.f,360.f));
    bola->setPos(CoordF(85.f,300.f));
}

void Pong::executar(){
    sf::Event event;
    
    while(pGG->windowopen()){
  
        while(pGG->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGG->closeWindow();
            }
                    
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W) R1->moveCima = true;
                if(event.key.code == sf::Keyboard::S) R1->moveBaixo = true;
                        //----
                if(event.key.code == sf::Keyboard::Up)   R2->moveCima = true;
                if(event.key.code == sf::Keyboard::Down) R2->moveBaixo = true;
                
                if(event.key.code == sf::Keyboard::Escape){
                    pGG->closeWindow();//serve apenas para fechar a janela
                }
                }
                    
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::W) R1->moveCima = false;
                if(event.key.code == sf::Keyboard::S) R1->moveBaixo = false;
                        //------
                if(event.key.code == sf::Keyboard::Up)   R2->moveCima = false;
                if(event.key.code == sf::Keyboard::Down) R2->moveBaixo = false;
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
