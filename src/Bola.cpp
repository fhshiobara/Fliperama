//
//  Bola.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#include "Bola.hpp"

Bola::Bola(CoordF p, CoordF v, float r):velocidade(v),raio(r),sprite(NULL),tamJanela(0.f,0.f){
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

void Bola::tratarColisaoParede(){
    if(pos.x-raio<0.f){
        pos.x = raio;
        velocidade.x = std::abs(velocidade.x);
    }
    else if(pos.x+raio>tamJanela.x){
        pos.x = tamJanela.x-raio;
        velocidade.x = -std::abs(velocidade.x);
    }
    
    if(pos.y-raio<0.f){
        pos.y = raio;
        velocidade.y = std::abs(velocidade.y);
    }
    else if(pos.y+raio>tamJanela.y){
        pos.y = tamJanela.y-raio;
        velocidade.y = -std::abs(velocidade.y);
    }
    
}

