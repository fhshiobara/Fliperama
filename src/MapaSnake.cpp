//
//  MapaSnake.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 17/08/26.
//

#include "MapaSnake.hpp"
#include <iostream>

MapaSnake::MapaSnake():numCols(30),numLinhas(30),tamCelula(30),pGG(Gerenciadores::GerenciadorGrafico::getInstance()){
    inicializar();
    criarLimites();
}

MapaSnake::~MapaSnake(){
    inicializar();
}

void MapaSnake::inicializar(){
    for(int i =0;i<numLinhas;i++){
        for(int j =0;j<numCols;j++){
            mapa[i][j] = 0;
        }
    }
}

void MapaSnake::print(){
    for(int i =0;i<numLinhas;i++){
        for(int j =0;j<numCols;j++){
            std::cout<<mapa[i][j];
        }
        std::cout<<std::endl;
    }
}

void MapaSnake::criarLimites(){
    for(int i=0;i<numCols;i++){//topo
        mapa[0][i] = 1;
    }
    for(int i=0;i<numLinhas;i++){//esquerda
        mapa[i][0] = 1;
    }
    for(int i=0;i<numCols;i++){//baixo
        mapa[numLinhas-1][i] = 1;
    }
    for(int i=0;i<numLinhas;i++){//esquerda
        mapa[i][numLinhas-1] = 1;
    }
}

void MapaSnake::draw(){
    for(int linhas=0;linhas<numLinhas;linhas++){
        for(int colunas=0;colunas<numCols;colunas++){
            sf::RectangleShape celula;
            celula.setSize(sf::Vector2f(tamCelula-1,tamCelula-1));
            celula.setOrigin(0.f,0.f);
            celula.setPosition(colunas*tamCelula+1,(linhas*tamCelula)+1);
            celula.setFillColor(sf::Color::Green);
            pGG->render(&celula);
            
        }
        
    }
}
    

