//
//  Blocos.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 04/08/26.
//

#include "Blocos.hpp"

Blocos::Blocos():id(0),cellSize(30),estado(0){
    cells.clear();
}


Blocos::~Blocos(){
    cells.clear();
}


int Blocos::getId(){return id;}
void Blocos::setId(int i){id = i;}
int Blocos::getEstado(){return estado;}
void Blocos::setEstado(int i){estado = i;}
