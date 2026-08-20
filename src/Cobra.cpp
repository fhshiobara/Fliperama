//
//  Cobra.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/08/26.
//

#include "Cobra.hpp"

Cobra::Cobra(CoordI posInicial)
    : direcaoAtual(Direcao::DIREITA), direcaoAnterior(Direcao::DIREITA){
    corpo.push_front(posInicial);
}

Cobra::~Cobra(){}

void Cobra::setDirecao(Direcao d){
    bool inversao180 =
        (d==Direcao::CIMA      && direcaoAnterior==Direcao::BAIXO)   ||
        (d==Direcao::BAIXO     && direcaoAnterior==Direcao::CIMA)    ||
        (d==Direcao::ESQUERDA  && direcaoAnterior==Direcao::DIREITA) ||
        (d==Direcao::DIREITA   && direcaoAnterior==Direcao::ESQUERDA);
    if(!inversao180) direcaoAtual = d;
}

CoordI Cobra::proximaPosicao() const{
    CoordI cabeca = corpo.front();
    switch(direcaoAtual){
        case Direcao::CIMA:     cabeca.y -= 1; break;
        case Direcao::BAIXO:    cabeca.y += 1; break;
        case Direcao::ESQUERDA: cabeca.x -= 1; break;
        case Direcao::DIREITA:  cabeca.x += 1; break;
    }
    return cabeca;
}

void Cobra::mover(bool cresce){
    corpo.push_front(proximaPosicao());
    if(!cresce) corpo.pop_back();
    direcaoAnterior = direcaoAtual;
}

CoordI Cobra::getCabeca() const{ return corpo.front(); }

const std::deque<CoordI>& Cobra::getCorpo() const{ return corpo; }

bool Cobra::ocupaPosicao(CoordI pos) const{
    for(const auto& seg : corpo){
        if(seg.x==pos.x && seg.y==pos.y) return true;
    }
    return false;
}
