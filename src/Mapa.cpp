//
//  Mapa.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "Mapa.hpp"
#include "iostream"

Mapa::Mapa():tamanho(CoordF(400.f,600.f)),numCols(10),numLinhas(20),tamanhoCelula(40){
    inicializar();
}

Mapa::~Mapa(){}

void Mapa::inicializar(){
    for(int linhas=0;linhas<numLinhas;linhas++){
        for(int colunas=0;colunas<numCols;colunas++){
            mapa[linhas][colunas] =0;
        }
    }
    
}

void Mapa::print(){
    for(int linhas=0;linhas<numLinhas;linhas++){
        for(int colunas=0;colunas<numCols;colunas++){
            std::cout<<mapa[linhas][colunas]<<" ";
        }
        std::cout<<std::endl;
    }
}
