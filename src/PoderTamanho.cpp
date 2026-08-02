//
//  PoderTamanho.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "PoderTamanho.hpp"

PoderTamanho::PoderTamanho():multiplicador(1.5),afetada(NULL){
    id = 2;
    sprite = new sf::RectangleShape;
    sprite->setSize(sf::Vector2f(tamanho.x,tamanho.y));
    sprite->setOrigin(sf::Vector2f(pos.x,pos.y));
    sprite->setFillColor(sf::Color::Blue);
    
}
PoderTamanho::~PoderTamanho(){
    if(afetada!=NULL){
        afetada = NULL;
    }
}

float PoderTamanho::getMult(){return multiplicador;}

void PoderTamanho::executar(Bola* bola){
    afetada = bola->getUltima();
    if(afetada!=NULL){
        CoordF tamanho = afetada->getSize();
        afetada->setSize(CoordF(tamanho.x,tamanho.y*multiplicador));
        afetada->setColor(sf::Color::Blue);
    }
}

void PoderTamanho::desativar(Bola* bola){
    if(afetada!=NULL){
        CoordF tamanho = afetada->getSize();
        //essa funcao abaixo seria o certo mas vou fazer no pelo pq deu bug
        //afetada->setSize(CoordF(tamanho.x/multiplicador,tamanho.y/multiplicador));
        afetada->setSize(CoordF(25.f,100.f));
        afetada->setColor(sf::Color::White);
        afetada = NULL;
    }
}

void PoderTamanho::setPos(CoordF p){
    Entidade::setPos(p);
    if(sprite!=NULL){
        sprite->setPosition(pos.x,pos.y);
    }
}

void PoderTamanho::setTamanho(CoordF t){
    Poderes::setTamanho(t);
    if(sprite!=NULL){
        sprite->setSize(sf::Vector2f(t.x,t.y));
    }
}
