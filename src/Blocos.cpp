//
//  Blocos.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 04/08/26.
//

#include "Blocos.hpp"

Blocos::Blocos():id(0),cellSize(30),estado(0),pM(NULL),offsetColuna(0),offsetLinha(0){
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

void Blocos::mover(int linhas, int colunas){
    offsetLinha+=linhas;
    offsetColuna+=colunas;
}

std::vector<CoordI> Blocos::getCellPositions(){
    std::vector<CoordI> pos = cells[estado];
    std::vector<CoordI>::iterator it;
    std::vector<CoordI> posFuturas;
    for(it = pos.begin();it!=pos.end();it++){
        CoordI novo = CoordI((*it).x+offsetLinha,(*it).y+offsetColuna);
        posFuturas.push_back(novo);
    }
    return posFuturas;
}


