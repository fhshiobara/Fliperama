//
//  Tetris.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "Tetris.hpp"

Tetris::Tetris():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL),grid(NULL),indicePeca(0){
    criarCenario();
    criarPecas();
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
    for(it = pecas.begin();it!=pecas.end();it++){
        delete (*it);
    }
    pecas.clear();
}

void Tetris::criarCenario(){
    sf::Color corFundo(58,47,85);
        fundo = new sf::RectangleShape;
        fundo->setOrigin(0.f,0.f);
        fundo->setSize(sf::Vector2f(1280.f,720.f));
        fundo->setFillColor(corFundo);
        
        grid = new sf::RectangleShape;
        grid->setOrigin(0.f,0.f);
        grid->setSize(sf::Vector2f(300.f,600.f));
        grid->setPosition(490.f,61.f);
        grid->setFillColor(sf::Color(43,26,74));
}
void Tetris::criarPecas(){
    pecas.push_back(new BlocoJ()); // tecla 1
    pecas.push_back(new BlocoQ()); // tecla 2
    pecas.push_back(new BlocoL()); // tecla 3
    pecas.push_back(new BlocoI()); // tecla 4
    pecas.push_back(new BlocoT()); // tecla 5
    pecas.push_back(new BlocoS()); // tecla 6
    pecas.push_back(new BlocoZ()); // tecla 7
    
    for(it = pecas.begin();it!=pecas.end();it++){
        (*it)->setMapa(&mapa);
    }
}

void Tetris::tratarEventos(){
    sf::Event event;
    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
        }
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::Num1: indicePeca = 0; break;
                case sf::Keyboard::Num2: indicePeca = 1; break;
                case sf::Keyboard::Num3: indicePeca = 2; break;
                case sf::Keyboard::Num4: indicePeca = 3; break;
                case sf::Keyboard::Num5: indicePeca = 4; break;
                case sf::Keyboard::Num6: indicePeca = 5; break;
                case sf::Keyboard::Num7: indicePeca = 6; break;
                case sf::Keyboard::R:{
                    int estadoAtual = pecas[indicePeca]->getEstado();
                    pecas[indicePeca]->setEstado((estadoAtual+1)%4);
                    break;
                }
                default: break;
            }
        }
    }
}

void Tetris::atualizar(){//aqui entra a logica de cair
    mapa.inicializar();
    
    
}
void Tetris::desenhar(){
    pGG->clear();
    
    pGG->render(fundo);
    pGG->render(grid);
    
    pecas[indicePeca]->draw(); // escreve o id da peca dentro do mapa
    mapa.draw();                // desenha o mapa inteiro (ja com a peca dentro)
    
    pGG->display();
}

void Tetris::executar(){
    while(pGG->windowopen()){
        tratarEventos();
        atualizar();
        desenhar();
    }
}

