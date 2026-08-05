//
//  Blocos.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 04/08/26.
//

#include "Blocos.hpp"

Blocos::Blocos():id(0),cellSize(30),estado(0),pM(NULL){
    cells.clear();
}


Blocos::~Blocos(){
    cells.clear();
}


int Blocos::getId(){return id;}
void Blocos::setId(int i){id = i;}
int Blocos::getEstado(){return estado;}
void Blocos::setEstado(int i){estado = i;}

void Blocos::setMapa(Mapa *m){
    pM = m;
}
Mapa* Blocos::getMapa(){
    return pM;
}

void Blocos::draw(){
    if(pM!=NULL){
        std::vector<CoordI> tiles = cells[estado];
        std::vector<CoordI>::iterator it;
        for(it = tiles.begin();it!=tiles.end();it++){
            pM->mapa[it->y][it->x] = id;
        }
    }
}


