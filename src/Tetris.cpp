//
//  Tetris.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "Tetris.hpp"

Tetris::Tetris():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL){
    sf::Color corFundo(58,47,85);
    fundo = new sf::RectangleShape;
    fundo->setOrigin(0.f,0.f);
    fundo->setSize(sf::Vector2f(1280.f,720.f));
    fundo->setFillColor(corFundo);
    
    grid = new sf::RectangleShape;
    grid->setOrigin(0.f,0.f);
    grid->setSize(sf::Vector2f(300,600));
    grid->setPosition(490.f,61.f);
    grid->setFillColor(sf::Color(43,26,74));
    bloco.setEstado(2);
    bloco.setMapa(&mapa);
    
    
    
    //mapa.mapa[10][10] = 2;
    
}

Tetris::~Tetris(){
    if(fundo!=NULL){
        delete fundo;
        fundo = NULL;
        
    }
    if(grid!=NULL){
        delete grid;
        grid = NULL;
    }
}

void Tetris::executar(){
    
    sf::Event event;
    while(pGG->windowopen()){
        while(pGG->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGG->closeWindow();
            }
        }
        pGG->clear();
        
        
        pGG->render(fundo);
        //mapa.print();
        mapa.mapa[5][5] = 2;
        pGG->render(grid);
        mapa.draw();
        bloco.draw();
        bloco.setEstado(0);
        
        pGG->display();
        
        //o loop principal vai precisar vir aqui
        
        
    }
}


