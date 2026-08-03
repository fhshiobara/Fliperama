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
    cores.clear();
    cores = {
        {0,sf::Color(20,10,46)},  //celula vazia
        {1,sf::Color(0,240,240)}, //ciano
        {2,sf::Color(0,0,240)}, //azul
        {3,sf::Color(240,160,0)}, //laranja
        {4,sf::Color(240,240,0)}, //amarelo
        {5,sf::Color(0,240,0)}, //verde
        {6,sf::Color(160,0,240)}, //roxo
        {7,sf::Color(240,0,0)}, //vermelho
        {10,sf::Color(43,26,74)}, //cor do grid
        
        
    };
    
    it = cores.begin();
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

void Mapa::draw(){
    for(int linhas=0;linhas<numLinhas;linhas++){
        for(int colunas=0;colunas<numCols;colunas++){
            sf::RectangleShape celula;
            celula.setSize(sf::Vector2f(tamanhoCelula,tamanhoCelula));
            celula.setOrigin(linhas*tamanhoCelula,colunas*tamanhoCelula);
            celula.setFillColor(getCor(mapa[linhas][colunas]));
            
        }
        
    }
    
}

sf::Color Mapa::getCor(int id){
    it = cores.find(id);
    if(it!=cores.end()){
        return it->second;
    }
    return cores[0];
    
        
    
    
}


