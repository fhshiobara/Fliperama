//
//  PoderVelocidade.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 01/08/26.
//

#include "PoderVelocidade.hpp"


PoderVelocidade::PoderVelocidade():multiplicador(1.5){
    sprite = new sf::RectangleShape;
    sprite->setSize(sf::Vector2f(tamanho.x,tamanho.y));
    sprite->setOrigin(sf::Vector2f(pos.x,pos.y));
    sprite->setFillColor(sf::Color::Red);
}

PoderVelocidade::~PoderVelocidade(){}

float PoderVelocidade::getMult(){
    return multiplicador;
}

