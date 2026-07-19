//
//  Bola.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#include "Bola.hpp"

Bola::Bola(CoordF p, CoordF v, float r):velocidade(v),raio(r),sprite(NULL){
    sprite = new sf::CircleShape;
    sprite->setRadius(raio);
    sprite->setOrigin(p.x,p.y);
    sprite->setFillColor(sf::Color::White);
}

Bola::~Bola(){
    if(sprite!=NULL){
        delete sprite;
        sprite = NULL;
    }
}

void Bola::mover(){
    pos.x = pos.x+velocidade.x;
    
    pos.y = pos.y+velocidade.y;
}

