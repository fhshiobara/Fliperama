//
//  Bola.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 12/07/26.
//

#include "Bola.hpp"
#include "Poderes.hpp"
Bola::Bola(CoordF v, float r):velocidade(v),raio(r),sprite(NULL),tamJanela(0.f,0.f),ultimo(0),ultima(NULL){
    sprite = new sf::CircleShape;
    sprite->setRadius(raio);

    sprite->setFillColor(sf::Color::White);
    raquetes.clear();
    it = raquetes.begin();
    gols.clear();
    i = gols.begin();
    poderes.clear();
    p = poderes.begin();
    
    velocidadePadrao = velocidade; // a velociade padrao é a que é passada na construtora
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
    
    atualizarSprite();
}

void Bola::atualizarSprite(){
    if(sprite!=NULL){
        sprite->setPosition(pos.x-raio,pos.y-raio);
    }
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
    atualizarSprite();
    
}

void Bola::setRaquete(Raquete* r){
    raquetes.push_back(r);
}
void Bola::setPos(CoordF p){
    Entidade::setPos(p);
    atualizarSprite();
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
            // se o centro da bola esta dentro da faixa vertical da raquete,
            // a colisao e sempre lateral (essa e a colisao "normal" do Pong)
            if(pos.y >= topo && pos.y <= base){
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
                // bola bateu genuinamente no canto (topo ou base) da raquete
                if(pos.y < posRaquete.y + altura/2.f){
                    pos.y = topo - raio;
                    velocidade.y = -std::abs(velocidade.y);
                }
                else{
                    pos.y = base + raio;
                    velocidade.y = std::abs(velocidade.y);
                }
            }
            
            if(this->getPos().x<640){
                ultimo = 1;
                //sprite->setFillColor(sf::Color::Blue);
            }
            else if(this->getPos().x>640){
                ultimo = 2;
                //sprite->setFillColor(sf::Color::Red);
            }
            ultima = (*it);
            atualizarSprite();
            break; // ja resolveu a colisao, nao precisa checar a outra raquete
        }
    }
}

void Bola::setGol(Gol* g){
    gols.push_back(g);
}

void Bola::tratarColisaoGol(){
    for(i=gols.begin(); i!=gols.end(); i++){
        CoordF tamanho = (*i)->getTamanho();
        float largura = tamanho.x;
        float altura = tamanho.y;

        CoordF posGol = (*i)->getPos();

        float esquerda = posGol.x;
        float direita  = posGol.x + largura;
        float topo     = posGol.y;
        float base     = posGol.y + altura;

        float pontoX = std::max(esquerda, std::min(pos.x, direita));
        float pontoY = std::max(topo, std::min(pos.y, base));

        float difX = pos.x - pontoX;
        float difY = pos.y - pontoY;

        float distanciaQuadrada = difX*difX + difY*difY;

        if(distanciaQuadrada < raio*raio){
            (*i)->setPontos(1);
//isso aqui comeca a bolinha direto no meio, vou mudar para que a bolinha tenha um tipo de saque ou sla
            sprite->setFillColor(sf::Color::White);
            pos.x = tamJanela.x/2.f;
            pos.y = tamJanela.y/2.f;
            velocidade.x = 0.f;
            velocidade.y = 0.f;

            atualizarSprite();

            break; // evita processar colisao com outro gol no mesmo frame
        }
    }
}

void Bola::tratarColisaoPoderes(){
    for(p = poderes.begin(); p != poderes.end(); p++){
        CoordF tamanho = (*p)->getTamanho();
        CoordF posPoder = (*p)->getPos();

        float esquerda = posPoder.x;
        float direita  = posPoder.x + tamanho.x;
        float topo     = posPoder.y;
        float base     = posPoder.y + tamanho.y;

        float pontoX = std::max(esquerda, std::min(pos.x, direita));
        float pontoY = std::max(topo, std::min(pos.y, base));

        float difX = pos.x - pontoX;
        float difY = pos.y - pontoY;

        float distanciaQuadrada = difX*difX + difY*difY;

        if(distanciaQuadrada < raio*raio){
            
            (*p)->executar(this);   // dispara o efeito do poder
            (*p)->setAtivo(true);
            (*p)->setFoiAtivado(true);
            
            break; // apenas um poder ativado por frame
        }
    }
}
