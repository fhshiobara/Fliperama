//
//  Bola.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#include "Bola.hpp"

Bola::Bola(CoordF p, CoordF v, float r):velocidade(v),raio(r),sprite(NULL),tamJanela(0.f,0.f){
    sprite = new sf::CircleShape;
    sprite->setRadius(raio);
    sprite->setOrigin(p.x,p.y);
    sprite->setFillColor(sf::Color::White);
    raquetes.clear();
    it = raquetes.begin();
}

Bola::~Bola(){
    if(sprite!=NULL){
        delete sprite;
        sprite = NULL;
    }
}

void Bola::mover(){
    pos.x = pos.x+velocidade.x;
    
    pos.y = pos.y+velocidade.y;
}

void Bola::tratarColisaoParede(){
    if(pos.x-raio<0.f){
        pos.x = raio;
        velocidade.x = std::abs(velocidade.x);
    }
    else if(pos.x+raio>tamJanela.x){
        pos.x = tamJanela.x-raio;
        velocidade.x = -std::abs(velocidade.x);
    }
    
    if(pos.y-raio<0.f){
        pos.y = raio;
        velocidade.y = std::abs(velocidade.y);
    }
    else if(pos.y+raio>tamJanela.y){
        pos.y = tamJanela.y-raio;
        velocidade.y = -std::abs(velocidade.y);
    }
    
}

void Bola::setRaquete(Raquete* r){
    raquetes.push_back(r);
}

void Bola::tratarColisaoRaquete(){
    for(it = raquetes.begin(); it != raquetes.end(); it++){
        CoordF tamanho = (*it)->getSize();
        float largura = tamanho.x;
        float altura = tamanho.y;

        CoordF posRaquete = (*it)->getPos();

        float esquerda = posRaquete.x;
        float direita  = posRaquete.x + largura;
        float topo     = posRaquete.y;
        float base     = posRaquete.y + altura;

        float pontoX = std::max(esquerda, std::min(pos.x, direita));
        float pontoY = std::max(topo, std::min(pos.y, base));

        float difX = pos.x - pontoX;
        float difY = pos.y - pontoY;

        float distanciaQuadrada = difX*difX + difY*difY;

        if(distanciaQuadrada < raio*raio){
            float sobreposicaoX = raio - std::abs(difX);
            float sobreposicaoY = raio - std::abs(difY);

            if(sobreposicaoX < sobreposicaoY){
                // colisao lateral (esquerda ou direita da raquete)
                if(pos.x < posRaquete.x + largura/2.f){
                    pos.x = esquerda - raio;
                    velocidade.x = -std::abs(velocidade.x);
                }
                else{
                    pos.x = direita + raio;
                    velocidade.x = std::abs(velocidade.x);
                }
            }
            else{
                // colisao por cima ou por baixo da raquete
                if(pos.y < posRaquete.y + altura/2.f){
                    pos.y = topo - raio;
                    velocidade.y = -std::abs(velocidade.y);
                }
                else{
                    pos.y = base + raio;
                    velocidade.y = std::abs(velocidade.y);
                }
            }
        }
    }
}
