//
//  Gol.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 31/07/26.
//

#include "Gol.hpp"

Gol::Gol(CoordF pos):tamanho(CoordF(25,720)),pontos(0){
    this->Entidade::setPos(pos);
}

Gol::~Gol(){}

void Gol::setPontos(int p){
    pontos = pontos+p;
}

int Gol::getPontos(){
    return pontos;
}

