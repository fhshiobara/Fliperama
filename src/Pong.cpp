//
//  Pong.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/07/26.
//

#include "Pong.hpp"

Pong::Pong():R1(NULL),R2(NULL),bola(NULL),pGG(Gerenciadores::GerenciadorGrafico::getInstance()),G1(NULL),G2(NULL),pV(NULL){
    R1 = new Raquete(CoordF(5.f,5.f), CoordF(20.f,100.f));
    R2 = new Raquete(CoordF(5.f,5.f), CoordF (25.f,100.f));
    G1 = new Gol(CoordF(1250.f,0.f));
    G2 = new Gol(CoordF(0.f,0.f));
    pV = new PoderVelocidade;
    bola = new Bola(CoordF(10.f,05.f),8.f);
    bola->setTamJanela(CoordF(1280.f,720.f));
    bola->setRaquete(R1);
    bola->setRaquete(R2);
    bola->setGol(G1);
    bola->setGol(G2);
    this->setPosInicial();
    
    sf::Font* fonte = pGG->getFont();
    if(fonte != NULL){
        txtG1.setFont(*fonte);
        txtG1.setCharacterSize(48);
        txtG1.setFillColor(sf::Color::White);
        txtG1.setPosition(1280.f/2.f - 80.f, 20.f);
        
        txtG2.setFont(*fonte);
        txtG2.setCharacterSize(48);
        txtG2.setFillColor(sf::Color::White);
        txtG2.setPosition(1280.f/2.f + 40.f, 20.f);
    }
    
    
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
    R1->setPos(CoordF(85.f,360.f));
    R2->setPos(CoordF(1180.f,360.f));
    bola->setPos(CoordF(85.f,300.f));
    pV->setPos(CoordF(640.f,360.f));
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
                
                if(event.key.code == sf::Keyboard::Space){
                    int aux = rand()%2; // 0 ou 1;
                    if(aux == 0){
                        aux = -1;
                    }
                    if(bola->getVelocidade().x==0.f && bola->getVelocidade().y==0.f){
                        
                        bola->setVelocidade(CoordF(bola->getVelocidadePadrao().x*aux,bola->getVelocidadePadrao().y*aux));
                    }
                }
                
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
        bola->tratarColisaoGol();
        txtG1.setString(std::to_string(G1->getPontos()));
        txtG2.setString(std::to_string(G2->getPontos()));
        
        pGG->render(pV->getSprite());
        pGG->render(&txtG1);
        pGG->render(&txtG2);
        pGG->render(R1->getSprite());
        pGG->render(R2->getSprite());
        pGG->render(bola->getSprite());
        
        if(G1->getPontos()==5||G2->getPontos()==5){
            pGG->closeWindow();
        }
        
        pGG->display();
    }
}
