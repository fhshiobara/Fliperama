//
//  MapaSnake.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 17/08/26.
//

#include "MapaSnake.hpp"
#include <iostream>

MapaSnake::MapaSnake():numCols(30),numLinhas(30),tamCelula(20),pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL){
    inicializar();

    criarXadrez();
    criarLimites();
    
    float larguramax = numCols*tamCelula;
    float alturamax = numLinhas*tamCelula;
    correcaoX = (1280.f-larguramax)/2.f;
    correcaoY = (720.f-alturamax)/2.f;
    
    cores = {
        {0,sf::Color(190,245,190)},
        {1,sf::Color(190,245,160)},
        {2,sf::Color(34,139,34)},
        {3,sf::Color(240,128,128)},
    };
    fundo = new sf::RectangleShape;
    fundo->setOrigin(0.f,0.f);
    fundo->setSize(sf::Vector2f(1280.f,720.f));
    fundo->setFillColor(sf::Color(180,185,190));
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
        mapa[0][i] = 2;
    }
    for(int i=0;i<numLinhas;i++){//esquerda
        mapa[i][0] = 2;
    }
    for(int i=0;i<numCols;i++){//baixo
        mapa[numLinhas-1][i] = 2;
    }
    for(int i=0;i<numLinhas;i++){//esquerda
        mapa[i][numLinhas-1] = 2;
    }
}
void MapaSnake::criarXadrez(){
    
    for(int i=0;i<numLinhas;i++){
        int j;
        if(i%2==0){j=0;}
        else{j=1;}
        while(j<numCols){
            mapa[i][j]=1;
            j=j+2;
        }
    }
    /*
    for(int i=1;i<numCols;i+=2){
        mapa[1][i]=1;
    }*/
}

void MapaSnake::draw(){
    pGG->render(fundo);
    
    for(int linhas=0;linhas<numLinhas;linhas++){
        for(int colunas=0;colunas<numCols;colunas++){
            sf::RectangleShape celula;
            celula.setSize(sf::Vector2f(tamCelula-1,tamCelula-1));
            celula.setOrigin(0.f,0.f);
            celula.setPosition(correcaoX+colunas*tamCelula+1,correcaoY+(linhas*tamCelula)+1);
            celula.setFillColor(getCor(mapa[linhas][colunas]));
            celula.setOutlineColor(sf::Color::Black);
            celula.setOutlineThickness(0.5f);
            pGG->render(&celula);
            
        }
        
    }
}
    

sf::Color MapaSnake::getCor(int id){
    it = cores.find(id);
    if(it!=cores.end()){
        return it->second;
    }
    return cores[0];
}

void MapaSnake::setFrutinha(Frutinha* f){
    mapa[f->getPos().x][f->getPos().y] = 3;
}
