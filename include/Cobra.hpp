//
//  Cobra.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/08/26.
//

#ifndef Cobra_hpp
#define Cobra_hpp

#include <deque>
#include "VectorTL.hpp"

enum class Direcao { CIMA, BAIXO, ESQUERDA, DIREITA };

class Cobra{
private:
    std::deque<CoordI> corpo; // corpo.front() = cabeça, corpo.back() = cauda
    Direcao direcaoAtual;
    Direcao direcaoAnterior; // evita a cobra virar 180° sobre si mesma
public:
    Cobra(CoordI posInicial);
    ~Cobra();

    void setDirecao(Direcao d);
    CoordI proximaPosicao() const; // pra checar colisão/fruta ANTES de mover de fato
    void mover(bool cresce );

    CoordI getCabeca() const;
    const std::deque<CoordI>& getCorpo() const;

    bool ocupaPosicao(CoordI pos) const;
};

#endif
