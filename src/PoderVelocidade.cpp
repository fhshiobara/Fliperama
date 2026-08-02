//
//  PoderVelocidade.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#include "PoderVelocidade.hpp"


PoderVelocidade::PoderVelocidade():multiplicador(1.5),afetada(NULL){
    id = 1;
    sprite = new sf::RectangleShape;
    sprite->setSize(sf::Vector2f(tamanho.x,tamanho.y));
    sprite->setOrigin(sf::Vector2f(pos.x,pos.y));
    sprite->setFillColor(sf::Color::Red);
}

PoderVelocidade::~PoderVelocidade(){}

float PoderVelocidade::getMult(){
    return multiplicador;
}

void PoderVelocidade::executar(Bola* bola){
    afetada = bola->getUltima();
    if(afetada != NULL){
        CoordF vAtual = afetada->getVelocidade();
        afetada->setVelocidade(CoordF(vAtual.x*multiplicador, vAtual.y*multiplicador));
        afetada->setColor(sf::Color::Red);
        
    }
}

void PoderVelocidade::desativar(Bola* bola){
    if(afetada!=NULL){
        CoordF vAtual = afetada->getVelocidade();
        afetada->setVelocidade(CoordF(vAtual.x/multiplicador, vAtual.y/multiplicador));
        afetada->setColor(sf::Color::White);
        afetada = NULL;
    }
    
}

void PoderVelocidade::setPos(CoordF p){
    Entidade::setPos(p);
    if(sprite!=NULL) sprite->setPosition(pos.x, pos.y);
}

void PoderVelocidade::setTamanho(CoordF t){
    Poderes::setTamanho(t);
    if(sprite!=NULL){
        sprite->setSize(sf::Vector2f(t.x,t.y));
    }
}
