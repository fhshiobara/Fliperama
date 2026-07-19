//
//  Raquete.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#include "Raquete.hpp"


Raquete::Raquete(CoordF v,CoordF t):velocidade(v),tamanho(t),sprite(NULL),moveDir(false),moveCima(false),moveBaixo(false),moveEsq(false){
    sprite = new sf::RectangleShape;
    if(sprite!=NULL){
        sprite->setSize(sf::Vector2f(tamanho.x,tamanho.y));
        sprite->setPosition(pos.x,pos.y);
        sprite->setFillColor(sf::Color::Green);
        
    }else{
        std::cout<<"ERRO NA ALOCACAO DO RECTANGLESHAPE EM RAQUETE"<<std::endl;
        
    }
    
}
Raquete::~Raquete(){
    if(sprite!=NULL){
        delete sprite;
        sprite = NULL;
    }
}

void Raquete::setSize(CoordF t){
    if(sprite!=NULL){
        sprite->setSize(sf::Vector2f(t.x,t.y));
    }
}

CoordF Raquete::getSize(){return tamanho;}


void Raquete::mover(){
    if(moveCima){
        pos.y = pos.y-velocidade.y;
    }
    if(moveBaixo){
        pos.y = pos.y=velocidade.y;
    }
    if(moveEsq){
        pos.x = pos.x-velocidade.x;
    }
    if(moveDir){
        pos.x = pos.x +velocidade.x;
    }
    
}
